##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=RaceViewer
ConfigurationName      :=Debug
WorkspacePath          :="C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager"
ProjectPath            :="C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceViewer"
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
ObjectsFileList        :="RaceViewer.txt"
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
Objects0=$(IntermediateDirectory)/src_vwrMain.c$(ObjectSuffix) $(IntermediateDirectory)/src_vwrMenu.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_vwrMain.c$(ObjectSuffix): src/vwrMain.c $(IntermediateDirectory)/src_vwrMain.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceViewer/src/vwrMain.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_vwrMain.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_vwrMain.c$(DependSuffix): src/vwrMain.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_vwrMain.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_vwrMain.c$(DependSuffix) -MM "src/vwrMain.c"

$(IntermediateDirectory)/src_vwrMain.c$(PreprocessSuffix): src/vwrMain.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_vwrMain.c$(PreprocessSuffix) "src/vwrMain.c"

$(IntermediateDirectory)/src_vwrMenu.c$(ObjectSuffix): src/vwrMenu.c $(IntermediateDirectory)/src_vwrMenu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/SC/ESTUDIO/MATERIAS/4 - PRACTICAS PROGRAMACION/PEC/PR3/UOCRaceManager/RaceViewer/src/vwrMenu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_vwrMenu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_vwrMenu.c$(DependSuffix): src/vwrMenu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_vwrMenu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_vwrMenu.c$(DependSuffix) -MM "src/vwrMenu.c"

$(IntermediateDirectory)/src_vwrMenu.c$(PreprocessSuffix): src/vwrMenu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_vwrMenu.c$(PreprocessSuffix) "src/vwrMenu.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


