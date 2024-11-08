# CMake generated Testfile for 
# Source directory: /home/mm/longshan11_6/src/lidar_processing
# Build directory: /home/mm/longshan11_6/build/lidar_processing
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cppcheck "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/cppcheck.xunit.xml" "--package-name" "lidar_processing" "--output-file" "/home/mm/longshan11_6/build/lidar_processing/ament_cppcheck/cppcheck.txt" "--command" "/opt/ros/foxy/bin/ament_cppcheck" "--xunit-file" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/cppcheck.xunit.xml" "--include_dirs" "/home/mm/longshan11_6/src/lidar_processing/include")
set_tests_properties(cppcheck PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/home/mm/longshan11_6/src/lidar_processing" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;61;ament_add_test;/opt/ros/foxy/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;83;ament_cppcheck;/opt/ros/foxy/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;65;ament_package;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;0;")
add_test(flake8 "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/flake8.xunit.xml" "--package-name" "lidar_processing" "--output-file" "/home/mm/longshan11_6/build/lidar_processing/ament_flake8/flake8.txt" "--command" "/opt/ros/foxy/bin/ament_flake8" "--xunit-file" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/flake8.xunit.xml")
set_tests_properties(flake8 PROPERTIES  LABELS "flake8;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mm/longshan11_6/src/lidar_processing" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_flake8/cmake/ament_flake8.cmake;48;ament_add_test;/opt/ros/foxy/share/ament_cmake_flake8/cmake/ament_cmake_flake8_lint_hook.cmake;18;ament_flake8;/opt/ros/foxy/share/ament_cmake_flake8/cmake/ament_cmake_flake8_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;65;ament_package;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;0;")
add_test(lint_cmake "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/lint_cmake.xunit.xml" "--package-name" "lidar_processing" "--output-file" "/home/mm/longshan11_6/build/lidar_processing/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/foxy/bin/ament_lint_cmake" "--xunit-file" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mm/longshan11_6/src/lidar_processing" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;41;ament_add_test;/opt/ros/foxy/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/opt/ros/foxy/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;65;ament_package;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;0;")
add_test(pep257 "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/pep257.xunit.xml" "--package-name" "lidar_processing" "--output-file" "/home/mm/longshan11_6/build/lidar_processing/ament_pep257/pep257.txt" "--command" "/opt/ros/foxy/bin/ament_pep257" "--xunit-file" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/pep257.xunit.xml")
set_tests_properties(pep257 PROPERTIES  LABELS "pep257;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mm/longshan11_6/src/lidar_processing" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_pep257/cmake/ament_pep257.cmake;41;ament_add_test;/opt/ros/foxy/share/ament_cmake_pep257/cmake/ament_cmake_pep257_lint_hook.cmake;18;ament_pep257;/opt/ros/foxy/share/ament_cmake_pep257/cmake/ament_cmake_pep257_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;65;ament_package;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;0;")
add_test(uncrustify "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/uncrustify.xunit.xml" "--package-name" "lidar_processing" "--output-file" "/home/mm/longshan11_6/build/lidar_processing/ament_uncrustify/uncrustify.txt" "--command" "/opt/ros/foxy/bin/ament_uncrustify" "--xunit-file" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/uncrustify.xunit.xml")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mm/longshan11_6/src/lidar_processing" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;65;ament_add_test;/opt/ros/foxy/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;34;ament_uncrustify;/opt/ros/foxy/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;65;ament_package;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3" "-u" "/opt/ros/foxy/share/ament_cmake_test/cmake/run_test.py" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/xmllint.xunit.xml" "--package-name" "lidar_processing" "--output-file" "/home/mm/longshan11_6/build/lidar_processing/ament_xmllint/xmllint.txt" "--command" "/opt/ros/foxy/bin/ament_xmllint" "--xunit-file" "/home/mm/longshan11_6/build/lidar_processing/test_results/lidar_processing/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mm/longshan11_6/src/lidar_processing" _BACKTRACE_TRIPLES "/opt/ros/foxy/share/ament_cmake_test/cmake/ament_add_test.cmake;118;add_test;/opt/ros/foxy/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/opt/ros/foxy/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/opt/ros/foxy/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/foxy/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/foxy/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;65;ament_package;/home/mm/longshan11_6/src/lidar_processing/CMakeLists.txt;0;")
