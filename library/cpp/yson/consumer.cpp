#include "consumer.h"

#include "parser.h"

namespace NYT {
    ////////////////////////////////////////////////////////////////////////////////

    void TYsonConsumerBase::OnRaw(const TStringBuf& yson, EYsonType type) {
        ParseYsonStringBuffer(yson, this, type);
    }

    ////////////////////////////////////////////////////////////////////////////////

}
