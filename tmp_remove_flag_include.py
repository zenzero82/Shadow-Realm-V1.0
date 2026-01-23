from pathlib import Path
path = Path('src/battle_script_commands.c')
data = path.read_text()
data = data.replace('#include  constants/flags.h\r\n', '', 1)
path.write_text(data)
