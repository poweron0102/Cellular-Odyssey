import os

import PySimpleGUI as sg

# Lista de resoluções suportadas
resolutions = ['800x600', '640x360', '1280x720', '1920x1080']

# Atualiza as configurações no arquivo settings.py
RES = (1280, 720)
FULLSCREEN = True
VOLUME = 100.0
SCALE = 2
scale_map = [False, False, False, False]
with open('settings.py', 'r') as settings_file:
    lines = settings_file.readlines()
    for line in lines:
        if line.startswith('RES '):
            exec(line)
        elif line.startswith('FULLSCREEN '):
            exec(line)
        elif line.startswith('VOLUME '):
            exec(line)
        elif line.startswith('SCALE '):
            exec(line)
            scale_map[SCALE - 1] = True

# Layout da janela de configurações
layout = [
    [sg.Text('Settings')],
    [sg.Text('Resolution:'), sg.Combo(resolutions, default_value=f'{RES[0]}x{RES[1]}', key='-RESOLUTION-')],
    [sg.Checkbox('Full screen', default=FULLSCREEN, key='-FULLSCREEN-')],
    [sg.Text('Game sound')],
    [sg.Slider(range=(0, 100), default_value=VOLUME, orientation='h', key='-VOLUME-')],
    [sg.Text('Qualidade Gráfica')],
    [
        sg.Radio('Low', 'graficos', default=scale_map[3], key='-LOW-'),
        sg.Radio('Medium', 'graficos', default=scale_map[2], key='-MEDIUM-'),
        sg.Radio('High', 'graficos', default=scale_map[1],  key='-HIGH-')
    ],
    [sg.Button('Play'), sg.Button('Exit')]
]

window = sg.Window('Cells', layout)

while True:
    event, values = window.read()

    if event == sg.WIN_CLOSED or event == 'Exit':
        break
    elif event == 'Play':
        resolution = values['-RESOLUTION-']
        full_screen = values['-FULLSCREEN-']
        volume = values['-VOLUME-']
        quality = 4
        if values['-MEDIUM-']:
            quality = 3
        elif values['-HIGH-']:
            quality = 2

        with open('settings.py', 'w') as settings_file:
            for line in lines:
                if line.startswith('RES '):
                    res = resolution.split('x')
                    settings_file.write(f"RES = ({res[0]}, {res[1]})\n")
                elif line.startswith('FULLSCREEN '):
                    settings_file.write(f"FULLSCREEN = {full_screen}\n")
                elif line.startswith('VOLUME '):
                    settings_file.write(f"VOLUME = {volume}\n")
                elif line.startswith('SCALE '):
                    settings_file.write(f"SCALE = {quality}\n")
                else:
                    settings_file.write(line)

        # Fecha a janela de configurações
        window.close()
        os.system('python main.py')
        break

window.close()

