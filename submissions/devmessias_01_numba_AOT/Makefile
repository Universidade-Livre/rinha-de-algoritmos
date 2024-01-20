compile:
	cd aot && python setup.py build_ext --inplace


install:
	pip install -r requirements.txt

install-aot-lib:
	cd aot && python setup.py install

compile-pyc:
	python -m compileall problem_01.py


setup: install compile install-aot-lib compile-pyc
