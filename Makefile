SASS=sass

all: styles

styles:
	$(SASS) scss/style.scss css/style.css
