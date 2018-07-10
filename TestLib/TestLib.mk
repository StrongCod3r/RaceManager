##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TestLib
ConfigurationName      :=Debug
WorkspacePath          := "C:\Codelite\20152\Pract3_Enunciat\UOCRaceManager"
ProjectPath            := "C:\Codelite\20152\Pract3_Enunciat\UOCRaceManager\TestLib"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ricard
Date                   :=16/05/2016
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.7.1/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW-4.7.1/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="TestLib.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.7.1/bin/windres.exe
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
AR       := C:/MinGW-4.7.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.7.1/bin/g++.exe
CC       := C:/MinGW-4.7.1/bin/gcc.exe
CXXFLAGS :=  -g  -Wall  -Werror $(Preprocessors)
CFLAGS   :=  -g  -Wall  -Werror $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.7.1/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_testLib.c$(ObjectSuffix) 



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
	@$(MakeDirCommand) "C:\Codelite\20152\Pract3_Enunciat\UOCRaceManager/.build-debug"
	@echo rebuilt > "C:\Codelite\20152\Pract3_Enunciat\UOCRaceManager/.build-debug/TestLib"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_testLib.c$(ObjectSuffix): src/testLib.c $(IntermediateDirectory)/src_testLib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Codelite/20152/Pract3_Enunciat/UOCRaceManager/TestLib/src/testLib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_testLib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_testLib.c$(DependSuffix): src/testLib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_testLib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_testLib.c$(DependSuffix) -MM "src/testLib.c"

$(IntermediateDirectory)/src_testLib.c$(PreprocessSuffix): src/testLib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_testLib.c$(PreprocessSuffix) "src/testLib.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


