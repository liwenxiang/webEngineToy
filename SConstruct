#coding=utf-8
env = Environment()
env.Clone()
import os

env['install_lib_root'] = ['#/build/install/lib/']
env['install_head_root'] = ['#/build/install/header/']

env["systerm_include"] = ['/Users/liwenxiang/Program/boost/include/']
env["user_include"] = ['']
env.Append(CPPPATH = [['#'], env["systerm_include"], env["user_include"]])


env["build_lib"] = ["#/build/lib/"]
env["systerm_lib_path"] = ['']
env["user_lib_path"] = ['']
env.Append(LIBPATH = env["systerm_lib_path"] + env["user_lib_path"] + env["build_lib"] + env['install_lib_root'])

env["system_lib"] = ['m']
env["use_lib"] = [""]
env["all_libs"] = env["system_lib"] + env["use_lib"]

env["project_name"] = "web_engine_toy"


#Export 和子目录的Import对应，是为了传递env变量
Export('env')
SConscript("web_engine_toy/SConscript", variant_dir="build/src/", duplicate=0)
