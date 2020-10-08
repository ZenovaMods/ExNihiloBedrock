#pragma once

#include "Zenova/Common.h"
#include "VertexField.h"

namespace mce {
    class VertexFormat {
    protected:
        unsigned char _fieldOffset[5];

    public:
        void enableField(VertexField field) {
            _fieldOffset[enum_cast(field)] = 1;
        }

        bool hasField(VertexField field) const {
            return _fieldOffset[enum_cast(field)] == 1;
        }
    };
}