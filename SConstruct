#coding=utf-8
env = Environment()
env.Clone()
import os

# do not use -lpthread, that's wrong
env['LINKFLAGS'] = ['-pthread']

env["project_name"] = "web_engine_toy"

env['install_lib_root'] = ['#/build/install/lib/']
env['install_head_root'] = '#/build/install/header/'


env["user_include"] = ['/home/liwenxiang/bin/header/']
env.Append(CPPPATH = [['#'], env["user_include"]])

env["user_lib_path"] = ['/home/liwenxiang/bin/lib/']
env["build_lib_path"] = ["#/build/lib/"]
env.Append(LIBPATH = [env["user_lib_path"], env["build_lib_path"]])


env["bin_depend_libs"] = ['muduo_base']
env["run_case_lib_path"] = '/home/liwenxiang/bin/lib/:./build/lib/'

def run_ut(ut_env, target, source, libs):
    #ugly static link main
    ut_env['LINKCOM'] = ut_env['LINKCOM'] + " /home/liwenxiang/bin/lib/static_main/libgtest.a";
    source = source + ['#/web_engine_toy/common/do_test.cpp']
    program = ut_env.Program(target=target, source=source, LIBS=libs)
    run_str = "/usr/bin/env LD_LIBRARY_PATH=$LD_LIBRARY_PATH:" + ut_env['run_case_lib_path'] + " " + program[0].abspath
    test_alias = Alias('test', [program], run_str)
    AlwaysBuild(test_alias)
env["run_ut"] = run_ut



#Export 和子目录的Import对应，是为了传递env变量
Export('env')
SConscript("web_engine_toy/SConscript", variant_dir="build/src/", duplicate=0)
