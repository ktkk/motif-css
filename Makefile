SASS=sass

STYLES_DIR=scss

STYLES_OUT_DIR=css

all: styles static-files

styles:
	$(SASS) $(STYLES_DIR)/style.scss $(STYLES_OUT_DIR)/style.css

static-files:
	@mkdir -p css/
	cp -r fonts/ $(STYLES_OUT_DIR)/
	cp -r icons/ $(STYLES_OUT_DIR)/

.PHONY: clean run

clean:
	rm -rf \
		$(STYLES_OUT_DIR)

run: all
	./run.py
