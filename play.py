import os

import PySimpleGUI as sg

# Lista de resoluções suportadas
resolutions = ['800x600', '640x360', '1280x720', '1920x1080']

# Layout da janela de configurações
layout = [
    [sg.Text('Settings')],
    [sg.Text('Resolution:'), sg.Combo(resolutions, default_value='1280x720', key='-RESOLUTION-')],
    [sg.Checkbox('Full screen', default=False, key='-FULLSCREEN-')],
    [sg.Text('Game sound')],
    [sg.Slider(range=(0, 100), default_value=100, orientation='h', key='-VOLUME-')],
    [sg.Text('Qualidade Gráfica')],
    [
        sg.Radio('Low', 'graficos', key='-LOW-'),
        sg.Radio('Medium', 'graficos', key='-MEDIUM-'),
        sg.Radio('High', 'graficos', default=True,  key='-HIGH-')
    ],
    [sg.Button('Play'), sg.Button('Exit')]
]

window = sg.Window('Configurações do Jogo', layout)

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

        # Atualiza as configurações no arquivo settings.py
        with open('settings.py', 'r') as settings_file:
            lines = settings_file.readlines()

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

