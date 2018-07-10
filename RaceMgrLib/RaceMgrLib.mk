##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=RaceMgrLib
ConfigurationName      :=Debug
WorkspacePath          :="C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager"
ProjectPath            :="C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceMgrLib"
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
OutputFile             :=../lib/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="RaceMgrLib.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/DEVELOP/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/DEVELOP/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/DEVELOP/TDM-GCC-64/bin/g++.exe
CC       := C:/DEVELOP/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g  -Wall  -Werror $(Preprocessors)
CFLAGS   :=  -g  -Wall  -Werror $(Preprocessors)
ASFLAGS  := 
AS       := C:/DEVELOP/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_operations.c$(ObjectSuffix) $(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) $(IntermediateDirectory)/src_races.c$(ObjectSuffix) $(IntermediateDirectory)/src_runners.c$(ObjectSuffix) $(IntermediateDirectory)/src_times.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\SC\ESTUDIO\MATERIAS\4 - PRACTICAS PROGRAMACION\PEC\PR3\UOCRaceManager/.build-debug"
	@echo rebuilt > "C:\SC\ESTUDIO\MATERIAS\4 - PRACTICAS PROGRAMACION\PEC\PR3\UOCRaceManager/.build-debug/RaceMgrLib"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_operations.c$(ObjectSuffix): src/operations.c $(IntermediateDirectory)/src_operations.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceMgrLib/src/operations.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_operations.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_operations.c$(DependSuffix): src/operations.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_operations.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_operations.c$(DependSuffix) -MM "src/operations.c"

$(IntermediateDirectory)/src_operations.c$(PreprocessSuffix): src/operations.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_operations.c$(PreprocessSuffix) "src/operations.c"

$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix): src/helpers.c $(IntermediateDirectory)/src_helpers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceMgrLib/src/helpers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_helpers.c$(DependSuffix): src/helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_helpers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_helpers.c$(DependSuffix) -MM "src/helpers.c"

$(IntermediateDirectory)/src_helpers.c$(PreprocessSuffix): src/helpers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_helpers.c$(PreprocessSuffix) "src/helpers.c"

$(IntermediateDirectory)/src_races.c$(ObjectSuffix): src/races.c $(IntermediateDirectory)/src_races.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceMgrLib/src/races.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_races.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_races.c$(DependSuffix): src/races.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_races.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_races.c$(DependSuffix) -MM "src/races.c"

$(IntermediateDirectory)/src_races.c$(PreprocessSuffix): src/races.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_races.c$(PreprocessSuffix) "src/races.c"

$(IntermediateDirectory)/src_runners.c$(ObjectSuffix): src/runners.c $(IntermediateDirectory)/src_runners.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceMgrLib/src/runners.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_runners.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_runners.c$(DependSuffix): src/runners.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_runners.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_runners.c$(DependSuffix) -MM "src/runners.c"

$(IntermediateDirectory)/src_runners.c$(PreprocessSuffix): src/runners.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_runners.c$(PreprocessSuffix) "src/runners.c"

$(IntermediateDirectory)/src_times.c$(ObjectSuffix): src/times.c $(IntermediateDirectory)/src_times.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceMgrLib/src/times.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_times.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_times.c$(DependSuffix): src/times.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_times.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_times.c$(DependSuffix) -MM "src/times.c"

$(IntermediateDirectory)/src_times.c$(PreprocessSuffix): src/times.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_times.c$(PreprocessSuffix) "src/times.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


