#include <Python.h>

#include "../core/VM.hpp"

#include <memory>
#include <string>


using namespace NovaLuau;


static std::unique_ptr<VM> vm;



static PyObject* nova_create(
    PyObject* self,
    PyObject* args
)
{

    vm = std::make_unique<VM>();

    vm->registerLibraries();


    Py_RETURN_NONE;

}



static PyObject* nova_execute(
    PyObject* self,
    PyObject* args
)
{

    const char* code;


    if(!PyArg_ParseTuple(
        args,
        "s",
        &code
    ))
    {
        return nullptr;
    }



    bool result =
        vm->execute(
            std::string(code)
        );



    if(result)
    {
        Py_RETURN_TRUE;
    }


    Py_RETURN_FALSE;

}



static PyMethodDef methods[] =
{

    {
        "create",
        nova_create,
        METH_NOARGS,
        "Create NovaLuau VM"
    },


    {
        "execute",
        nova_execute,
        METH_VARARGS,
        "Execute Luau code"
    },


    {
        nullptr,
        nullptr,
        0,
        nullptr
    }

};



static struct PyModuleDef module =
{

    PyModuleDef_HEAD_INIT,

    "novaluau",

    "NovaLuau Python Binding",

    -1,

    methods

};



PyMODINIT_FUNC PyInit_novaluau()
{
    return PyModule_Create(
        &module
    );
}
