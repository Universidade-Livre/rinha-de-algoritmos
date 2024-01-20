from setuptools import setup
from setuptools.extension import Extension
from Cython.Build import cythonize

extensions = [
    Extension(
        name="knapsack",
        sources=["knapsack.py"]
    ),
]

setup(
    name="knapsack",
    ext_modules=cythonize(extensions),
)
