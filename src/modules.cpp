#include "types.hpp"

#include "sstvdecoder.hpp"

#include <csdr-sstv/version.hpp>

static PyModuleDef pycsdrsstvmodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "csdrsstv.modules",
    .m_doc = "Python bindings for the csdr-sstv library",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_modules(void) {
    PyObject* bases = PyTuple_Pack(1, getModuleType());
    if (bases == NULL) return NULL;
    PyObject* SstvDecoderType = PyType_FromSpecWithBases(&SstvDecoderSpec, bases);
    if (SstvDecoderType == NULL) return NULL;

    PyObject* m = PyModule_Create(&pycsdrsstvmodule);
    if (m == NULL) {
        return NULL;
    }

    PyModule_AddObject(m, "SstvDecoder", SstvDecoderType);

    PyObject* csdrSstvVersion = PyUnicode_FromStringAndSize(Csdr::Sstv::version.c_str(), Csdr::Sstv::version.length());
    if (csdrSstvVersion == NULL) return NULL;
    PyModule_AddObject(m, "csdrsstv_version", csdrSstvVersion);

    PyObject* version = PyUnicode_FromString(VERSION);
    if (version == NULL) return NULL;
    PyModule_AddObject(m, "version", version);

    return m;
}