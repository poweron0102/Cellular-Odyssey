#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[115];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_main_internal;
extern CPyModule *CPyModule_main;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_sys;
extern CPyModule *CPyModule_os;
extern CPyModule *CPyModule_time;
extern CPyModule *CPyModule_types;
extern CPyModule *CPyModule_dataclasses;
extern CPyModule *CPyModule_enum;
extern CPyModule *CPyModule_importlib;
extern CPyModule *CPyModule_math;
extern CPyModule *CPyModule_random;
extern CPyModule *CPyModule_pygame;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_settings;
extern CPyModule *CPyModule_functions;
extern CPyModule *CPyModule_in_game;
extern CPyModule *CPyModule_scheduler;
extern CPyModule *CPyModule_textures;
extern CPyModule *CPyModule_parallax;
extern CPyModule *CPyModule_map;
extern CPyModule *CPyModule_gun;
extern CPyModule *CPyModule_player;
extern CPyModule *CPyModule_events;
extern CPyModule *CPyModule_hud;
extern CPyModule *CPyModule_ray_caster;
extern CPyModule *CPyModule_dialogue;
extern CPyModule *CPyModule_sprites;
extern CPyModule *CPyModule_enemy;
extern CPyModule *CPyModule_drawer;
extern CPyModule *CPyModule_actions;
extern PyTypeObject *CPyType_NewGame;
extern PyTypeObject *CPyType_Game;
extern PyObject *CPyDef_Game(void);
extern PyObject *CPyDef_check_events(void);
extern PyObject *CPyPy_check_events(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_Game_____init__(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_Game___new_game(PyObject *cpy_r_self, PyObject *cpy_r_level, PyObject *cpy_r_set_screen, PyObject *cpy_r_supress);
extern PyObject *CPyPy_Game___new_game(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Game___update(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game___update(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Game___run(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game___run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
