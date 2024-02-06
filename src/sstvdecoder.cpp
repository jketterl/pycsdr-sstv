#include "sstvdecoder.hpp"
#include "types.hpp"

#include <csdr-sstv/csdr-sstv.hpp>

static int SstvDecoder_init(SstvDecoder* self, PyObject* args, PyObject* kwds) {
    self->inputFormat = FORMAT_FLOAT;
    self->outputFormat = FORMAT_CHAR;
    self->setModule(new Csdr::Sstv::SstvDecoder());

    return 0;
}
static PyType_Slot SstvDecoderSlots[] = {
    {Py_tp_init, (void*) SstvDecoder_init},
    {0, 0}
};

PyType_Spec SstvDecoderSpec = {
    "csdrsstv.modules.SstvDecoder",
    sizeof(SstvDecoder),
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_FINALIZE,
    SstvDecoderSlots
};
