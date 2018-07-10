##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=RaceManager
ConfigurationName      :=Debug
WorkspacePath          :="C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager"
ProjectPath            :="C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceManager"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=sc
Date                   :=31/05/2016
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/DEVELOP/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/DEVELOP/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="RaceManager.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/DEVELOP/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)../RaceMgrLib/include $(IncludeSwitch)../TestLib/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)RaceMgrLib 
ArLibs                 :=  "RaceMgrLib" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/DEVELOP/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/DEVELOP/TDM-GCC-64/bin/g++.exe
CC       := C:/DEVELOP/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall  -Werror $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall  -Werror $(Preprocessors)
ASFLAGS  := 
AS       := C:/DEVELOP/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_mgrMain.c$(ObjectSuffix) $(IntermediateDirectory)/src_mgrTests.c$(ObjectSuffix) $(IntermediateDirectory)/src_mgrMenu.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d "..\.build-debug\RaceMgrLib" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

"..\.build-debug\RaceMgrLib":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\RaceMgrLib"




MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_mgrMain.c$(ObjectSuffix): src/mgrMain.c $(IntermediateDirectory)/src_mgrMain.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceManager/src/mgrMain.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_mgrMain.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_mgrMain.c$(DependSuffix): src/mgrMain.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_mgrMain.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_mgrMain.c$(DependSuffix) -MM "src/mgrMain.c"

$(IntermediateDirectory)/src_mgrMain.c$(PreprocessSuffix): src/mgrMain.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_mgrMain.c$(PreprocessSuffix) "src/mgrMain.c"

$(IntermediateDirectory)/src_mgrTests.c$(ObjectSuffix): src/mgrTests.c $(IntermediateDirectory)/src_mgrTests.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceManager/src/mgrTests.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_mgrTests.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_mgrTests.c$(DependSuffix): src/mgrTests.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_mgrTests.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_mgrTests.c$(DependSuffix) -MM "src/mgrTests.c"

$(IntermediateDirectory)/src_mgrTests.c$(PreprocessSuffix): src/mgrTests.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_mgrTests.c$(PreprocessSuffix) "src/mgrTests.c"

$(IntermediateDirectory)/src_mgrMenu.c$(ObjectSuffix): src/mgrMenu.c $(IntermediateDirectory)/src_mgrMenu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceManager/src/mgrMenu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_mgrMenu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_mgrMenu.c$(DependSuffix): src/mgrMenu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_mgrMenu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_mgrMenu.c$(DependSuffix) -MM "src/mgrMenu.c"

$(IntermediateDirectory)/src_mgrMenu.c$(PreprocessSuffix): src/mgrMenu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_mgrMenu.c$(PreprocessSuffix) "src/mgrMenu.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


