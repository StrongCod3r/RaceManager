.PHONY: clean All

All:
	@echo "----------Building project:[ RaceMgrLib - Debug ]----------"
	@cd "RaceMgrLib" && "$(MAKE)" -f  "RaceMgrLib.mk"
	@echo "----------Building project:[ RaceViewer - Debug ]----------"
	@cd "RaceViewer" && "$(MAKE)" -f  "RaceViewer.mk"
clean:
	@echo "----------Cleaning project:[ RaceMgrLib - Debug ]----------"
	@cd "RaceMgrLib" && "$(MAKE)" -f  "RaceMgrLib.mk"  clean
	@echo "----------Cleaning project:[ RaceViewer - Debug ]----------"
	@cd "RaceViewer" && "$(MAKE)" -f  "RaceViewer.mk" clean
