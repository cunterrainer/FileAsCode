import os, sys, shutil, time, filecmp
from termcolor import colored

def GetFilesInDir(path:str) -> list:
    files:list = []
    for (_, _, filenames) in os.walk(path):
        files.extend(filenames)
        break
    return files

def CreateFolder(path:str):
    if not os.path.exists(path):
        os.makedirs(path)

def DeleteFolder(path:str):
    if os.path.exists(path):
        shutil.rmtree(path)

def DeleteFile(file:str):
    if os.path.exists(file):
        os.remove(file)

def GetFileNames(files:list) -> list:
    names:list = []
    for file in files:
        names.append(file.split(".")[0])
    return names

def GetBuildCommands(fileNames:list, files:list, checkLevel:int):
    commands:list = []
    filePaths:list = []
    for i in range(len(fileNames)):
        if checkLevel >= 1:
            filePaths.append(fileNames[i] + "CInlineRaw.h")
            filePaths.append(fileNames[i] + "CppInlineRaw.h")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CInlineRaw.h" + " -c -il -r")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CppInlineRaw.h" + " -c++ -il -r")
        if checkLevel >= 2:
            filePaths.append(fileNames[i] + "CInlineUncompressed.h")
            filePaths.append(fileNames[i] + "CppInlineUncompressed.h")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CInlineUncompressed.h" + " -c -il -uc")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CppInlineUncompressed.h" + " -c++ -il -uc")

        if checkLevel >= 3:
            filePaths.append(fileNames[i] + "CRaw.h")
            filePaths.append(fileNames[i] + "CppRaw.h")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CRaw.h" + " -c -r")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CppRaw.h" + " -c++ -r")
        if checkLevel >= 4:
            filePaths.append(fileNames[i] + "CUncompressed.h")
            filePaths.append(fileNames[i] + "CppUncompressed.h")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CUncompressed.h" + " -c -uc")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CppUncompressed.h" + " -c++ -uc")

        if checkLevel >= 5:
            filePaths.append(fileNames[i] + "RawInline.h")
            filePaths.append(fileNames[i] + "UncompressedInline.h")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "RawInline.h" + " -r -il")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "UncompressedInline.h" + " -uc -il")
        if checkLevel >= 6:
            filePaths.append(fileNames[i] + "Raw.h")
            filePaths.append(fileNames[i] + "Uncompressed.h")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "Raw.h" + " -r")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "Uncompressed.h" + " -uc")
        if checkLevel >= 7:
            filePaths.append(fileNames[i] + "C.h")
            filePaths.append(fileNames[i] + "Cpp.h")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "C.h" + " -c")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "Cpp.h" + " -c++")
        if checkLevel >= 8:
            filePaths.append(fileNames[i] + "CInline.h")
            filePaths.append(fileNames[i] + "CppInline.h")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CInline.h" + " -c -il")
            commands.append("-i " + files[i] + " -o " + fileNames[i] + "CppInline.h" + " -c++ -il")
    return commands, filePaths

def CreateHeaderFiles(checkLevel:int):
    path:str = "test/images"
    headerPath:str = "test/headers"
    files:list = GetFilesInDir(path)
    headerNames:list = GetFileNames(files)
    headerNamesOld:list = GetFileNames(files)
    for i in range(len(files)):
        headerNames[i] = headerPath + "/" + headerNames[i]
        headerNamesOld[i] = headerPath + "/" + headerNamesOld[i] + "Old"
        files[i] = path + "/" + files[i]

    commands, filePaths = GetBuildCommands(headerNames, files, checkLevel)
    commandsOld, filePathsOld = GetBuildCommands(headerNamesOld, files, checkLevel)

    for i in range(len(commands)):
        print("Generating " + str(i+1) + " | " + str(len(commands)), end="\r")
        os.system("test\im2c " + commands[i])
        os.system("test\im2cOld " + commandsOld[i])

    print("", end="\r")
    return filePaths, filePathsOld

def CheckHeader(filePaths:list, filePathsOld:list):
    filePathsAmount = len(filePaths)
    filecmp.clear_cache()
    for i in range(filePathsAmount):
        if not os.path.exists(filePaths[i]):
            print(colored("\nError: " + filePaths[i] + " does not exist", "red"))
            return
        if not os.path.exists(filePathsOld[i]):
            print(colored("\nError: " + filePathsOld[i] + " does not exist", "red"))
            return
        if not filecmp.cmp(filePaths[i], filePathsOld[i], shallow=False):
            print(colored("\nError: " + filePaths[i] + " and " + filePathsOld[i] + " are different", "red"))
            return
        if i == filePathsAmount - 1:
            print(colored("Passed " + str(i+1) + " | " + str(filePathsAmount) + " tests", "green"))
            print(colored("All files are the same", "green"))
        else:
            print(colored("Passed " + str(i+1) + " | " + str(filePathsAmount) + " tests", "green"), end="\r")
    return

def main():
    startTime = time.time()
    os.system("color")
    checkLevel:int = 1
    if len(sys.argv) > 1:
        if sys.argv[1].lower() == "-help" or sys.argv[1].lower() == "-h":
            print("Usage: test.py [check level]")
            print("Check level: 1(default) - 8")
            print("1 is the least strict, 8 is the most strict")
            return
        checkLevel = int(sys.argv[1])
    
    DeleteFolder("test/headers")
    DeleteFile("test/im2c.exe")

    binaryPath = "BIN/Release/x86_64/im2c/bin/im2c.exe"
    if os.path.exists(binaryPath):
        shutil.copy2(binaryPath, "test/im2c.exe")
    else:
        print(colored("Error: im2c.exe couldn't be copied path: " + binaryPath, "red"))
        return

    CreateFolder("test/headers")
    print("Check level: " + str(checkLevel) + " | 8")
    filePaths, filePathsOld = CreateHeaderFiles(checkLevel)
    CheckHeader(filePaths, filePathsOld)

    print("Time: " + str(time.time() - startTime) + " sec")

if __name__ == '__main__':
    main()