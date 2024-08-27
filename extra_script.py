Import("env")
from os.path import join, basename

def generate_coverage_report(source, target, env):
    # Run the GCOV tool to generate a coverage report
    env.Execute("gcov -o .pio/build/native/ src/*.cpp")

    # Move the .gcov files to a specific directory if needed
    env.Execute("mkdir -p coverage")
    env.Execute("mv *.gcov coverage/")

env.AddPostAction("test", generate_coverage_report)
