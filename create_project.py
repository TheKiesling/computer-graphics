#      #    #######    ########   #######   #          #######   ##      #    #########
#     #        #       #          #         #             #      # #     #    #
#    #         #       #          #         #             #      #  #    #    #
####           #       #####      #######   #             #      #   #   #    #    ####
#    #         #       #                #   #             #      #    #  #    #       #
#     #        #       #                #   #             #      #     # #    #       #
#      #    ########   ########   #######   ########   #######   #      ##    #########

import os
import subprocess
import curses
import shutil
import requests

def select_parent_directory(directories):
    stdscr = curses.initscr()
    curses.noecho()
    curses.cbreak()
    stdscr.keypad(True)

    current_row = 0

    while True:
        stdscr.clear()
        stdscr.addstr("Seleccione el directorio donde desea crear el proyecto:\n")
        for idx, directory in enumerate(directories):
            if idx == current_row:
                stdscr.addstr(">> ")
            else:
                stdscr.addstr("   ")
            stdscr.addstr(directory + "\n")

        key = stdscr.getch()

        if key == curses.KEY_UP and current_row > 0:
            current_row -= 1
        elif key == curses.KEY_DOWN and current_row < len(directories) - 1:
            current_row += 1
        elif key == curses.KEY_ENTER or key in [10, 13]:
            break

    curses.endwin()

    return directories[current_row]

def select_directory(directories):
    stdscr = curses.initscr()
    curses.noecho()
    curses.cbreak()
    stdscr.keypad(True)

    current_row = 0
    selected = [False] * len(directories)

    while True:
        stdscr.clear()
        stdscr.addstr("Seleccione los directorios a incluir:\n")
        for idx, directory in enumerate(directories):
            if idx == current_row:
                stdscr.addstr(">> ")
            else:
                stdscr.addstr("   ")

            if selected[idx]:
                stdscr.addstr("[X] ")
            else:
                stdscr.addstr("[ ] ")

            stdscr.addstr(directory + "\n")

        key = stdscr.getch()

        if key == curses.KEY_UP and current_row > 0:
            current_row -= 1
        elif key == curses.KEY_DOWN and current_row < len(directories) - 1:
            current_row += 1
        elif key == ord(" ") or key == 10 or key == 13:
            selected[current_row] = not selected[current_row]
        elif key == ord("q"):
            break

    curses.endwin()

    selected_directories = [directories[i] for i in range(len(directories)) if selected[i]]
    return selected_directories

def extract_header_files(source_directories, target_directory):
    os.makedirs(target_directory, exist_ok=True)  # Crear el directorio destino si no existe
    for source_directory in source_directories:
        for root, dirs, files in os.walk(source_directory):
            for file in files:
                if file.endswith(".h"):
                    source_path = os.path.join(root, file)
                    target_path = os.path.join(target_directory, file)
                    shutil.copy(source_path, target_path)

def create_github_repository(repo_name, token):
    headers = {
        "Authorization": f"token {token}",
        "Accept": "application/vnd.github.v3+json"
    }
    data = {
        "name": repo_name,
        "auto_init": True
    }
    response = requests.post("https://api.github.com/user/repos", headers=headers, json=data)
    if response.status_code == 201:
        print("Repositorio creado en GitHub exitosamente.")
    else:
        print("Error al crear el repositorio en GitHub.")

def create_project():
    parent_directory = select_parent_directory(os.listdir())

    project_name = input("Ingrese el nombre del proyecto: ")

    project_directory = os.path.join(parent_directory, project_name)
    os.makedirs(project_directory, exist_ok=True)
    os.chdir(project_directory)

    os.makedirs("src", exist_ok=True)

    interfaces_directory = os.path.join(os.path.dirname(os.path.abspath(__file__)), "interfaces")
    directories = [name for name in os.listdir(interfaces_directory) if os.path.isdir(os.path.join(interfaces_directory, name))]
    selected_directories = select_directory(directories)

    source_directories = [os.path.join(interfaces_directory, directory) for directory in selected_directories]
    target_directory = os.path.join("src")

    extract_header_files(source_directories, target_directory)

    main_content = '''\
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
'''
    with open(os.path.join("src", "main.cpp"), 'w') as main_file:
        main_file.write(main_content)

    editor_command = "code {}".format(os.path.join("src", "main.cpp"))
    subprocess.call(editor_command, shell=True)

    cmake_content = '''\
cmake_minimum_required(VERSION 3.26)

project({} VERSION 1.0)

add_executable(${{PROJECT_NAME}}
    src/main.cpp
)
'''.format(project_name)
    with open('CMakeLists.txt', 'w') as cmake_file:
        cmake_file.write(cmake_content)

    configure_content = 'cmake -S . -B build -G "MinGW Makefiles"'
    with open('configure.bat', 'w') as configure_file:
        configure_file.write(configure_content)

    build_content = 'cd build && make'
    with open('build.bat', 'w') as build_file:
        build_file.write(build_content)

    run_content = 'call configure.bat\ncall build.bat\ncall {}.exe\npause'.format(project_name)
    with open('run.bat', 'w') as run_file:
        run_file.write(run_content)
        
    gitignore_content = 'build'
    with open('.gitignore', 'w') as gitignore_file:
        gitignore_file.write(gitignore_content)
        

    create_github_repository(project_name, "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")

if __name__ == '__main__':
    create_project()