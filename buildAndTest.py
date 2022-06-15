import os, shutil, sys

def DeleteFolder(path:str):
    if os.path.exists(path):
        shutil.rmtree(path)

def ExecuteCommand(command):
    print(command)
    os.system(command)

if len(sys.argv) < 2:
    print("Usage: buildAndTest.py <checkLevel>")
    sys.exit(1)

DeleteFolder("BIN/Release/x86_64/im2c")
ExecuteCommand("cls")
ExecuteCommand("make -j config=release_x64")
ExecuteCommand("python test/test.py " + sys.argv[1])