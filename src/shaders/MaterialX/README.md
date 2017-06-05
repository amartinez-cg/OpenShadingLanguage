README for MaterialX Shader Nodes
=================================


### [MaterialX Specification](http://www.materialx.org/)


This is a reference implementation of version 1.35 of the MaterialX specification, drafted by Lucasfilm Ltd, in collaboration with Autodesk and The Foundry. 


Each .mx file contains a type-independent declaration of a shader.  During the build process, CMake will pass pre-processor arguments to oslc to generate the type-specific .oso shaders. In all, 475 separate nodes will be built.


Alternatively, the python script in src/build-scripts/build_materialX_osl.py can be used to generate .osl that will compile with oslc without any preprocessor definitions. 

The MaterialX specification is authored and maintained by Doug Smythe and Jonathan Stone at Lucasfilm Ltd.

This reference implementation was authored by Adam Martinez and Derek Haase.
