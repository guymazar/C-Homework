project = "Guy_Mazar_homework_SESSION_17_19"
copyright = "2024, You"
author = "You"
# Breathe is an extension that allows us to connect Doxygen with Sphinx
# There are many sphinx extensions, which can be added to this list
extensions = ["breathe"]
# Breathe Configuration
breathe_default_project = project
templates_path = ["_templates"]
exclude_patterns = []
html_theme = "alabaster" # There are many themes to choose from
html_static_path = ["_static"] # This is where you put static files like images
