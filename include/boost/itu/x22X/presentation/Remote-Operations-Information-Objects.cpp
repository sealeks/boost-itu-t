#include "Remote-Operations-Information-Objects.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4065)
#endif



namespace Remote_Operations_Information_Objects {

    // choice Code

    void Code::local(const int& vl) {
        set<int>(new int(vl), Code_local);
    }

    void Code::global(const oid_type& vl) {
        set<oid_type>(new oid_type(vl), Code_global);
    }

    template<> void Code::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Code_local:
            {
                ITU_T_BIND_TAG(value<int > (false, Code_local));
                break;
            }
            case Code_global:
            {
                ITU_T_BIND_TAG(value<oid_type > (false, Code_global));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Code::serialize(boost::asn1::x690::input_coder& arch) {
        int __tag_id__ = arch.test_id();
        switch (arch.test_class()) {
            case 0x0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x40:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0x80:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            case 0xC0:
            {
                switch (__tag_id__) {
                    default:
                    {
                    }
                }
            }
            default:
            {
                if (ITU_T_BIND_TAG(value<int > (true, Code_local))) return;
                else free();
                if (ITU_T_BIND_TAG(value<oid_type > (true, Code_global))) return;
                else free();
            }
        }
    }


}


#ifdef _MSC_VER
#pragma warning(pop)
#endif

