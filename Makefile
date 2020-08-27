.PHONY: nightly
nightly: requirements
	cd bin && ./check.sh

.PHONY: requirements
requirements: requirements/build.sh
	cd requirements && ./build.sh

.PHONY: clean
clean:
	find src -type d -name "__pycache__" -exec ${RM} -r {} +

.PHONY: clean-requirements
clean-requirements:
	$(RM) -r requirements/FPTaylor
	$(RM) -r requirements/gelpia
	$(RM) requirements/log.txt
	$(RM) requirements/debug_eniroment.sh
