
reST is a somewhat intuitive format, you will get the hang of it quickly as you need stuff. The primer
is a good reference.
The toctree directive is used to create a table of contents. The maxdepth option specifies how many levels
of subdirectories to include in the table of contents. The caption option specifies the title of the table
of contents. The toctree directive is followed by a list of documents to include in the table of contents.
For instance "introduction" expects a file called introduction.rst in the same folder as index.rst. Any
headings in the included files will be used as section titles in the table of contents.
3.3.1 Adding it to CMake
We must run sphinx-build after Doxygen has generated the documentation database. We can do this by
adding a custom target to the CMakeLists.txt file in the docs folder:
Source code
set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/source) # Location of the Sphinx
source files (index.rst, conf.py,...)↪→
set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx) # Location of the
generated Sphinx documentation↪→
add_custom_target(Sphinx ALL
COMMAND
sphinx-build -b html
-Dbreathe_projects.${PROJECT_NAME}=${DOXYGEN_OUTPUT_DIR}/xml
${SPHINX_SOURCE} ${SPHINX_BUILD}
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating documentation with Sphinx")
With some luck and a bit of tweaking, you should now be able to run cmake --build . from the
build directory and get a nice web page with your documentation. You will find the web page in the
docs/sphinx folder. Open the index.html file in your browser to see the documentation.
9