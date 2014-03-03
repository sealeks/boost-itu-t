#include "ACSE-1.hpp"

namespace ACSE_1 {

    const boost::array<boost::asn1::oidindx_type, 5> acse_as_id_OID_ARR = {2, 2, 1, 0, 1};
    const oid_type acse_as_id = boost::asn1::oid_type(acse_as_id_OID_ARR);

    const boost::array<boost::asn1::oidindx_type, 5> aCSE_id_OID_ARR = {2, 2, 3, 1, 1};
    const oid_type aCSE_id = boost::asn1::oid_type(aCSE_id_OID_ARR);

    // choice ACSE-apdu

    template<> void ACSE_apdu::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ACSE_apdu_aarq:
            {
                ITU_T_BIND_TAG(value<AARQ_apdu > (false, ACSE_apdu_aarq));
                break;
            }
            case ACSE_apdu_aare:
            {
                ITU_T_BIND_TAG(value<AARE_apdu > (false, ACSE_apdu_aare));
                break;
            }
            case ACSE_apdu_rlrq:
            {
                ITU_T_BIND_TAG(value<RLRQ_apdu > (false, ACSE_apdu_rlrq));
                break;
            }
            case ACSE_apdu_rlre:
            {
                ITU_T_BIND_TAG(value<RLRE_apdu > (false, ACSE_apdu_rlre));
                break;
            }
            case ACSE_apdu_abrt:
            {
                ITU_T_BIND_TAG(value<ABRT_apdu > (false, ACSE_apdu_abrt));
                break;
            }
            case ACSE_apdu_adt:
            {
                ITU_T_BIND_TAG(value<A_DT_apdu > (false, ACSE_apdu_adt));
                break;
            }
            case ACSE_apdu_acrq:
            {
                ITU_T_BIND_TAG(value<ACRQ_apdu > (false, ACSE_apdu_acrq));
                break;
            }
            case ACSE_apdu_acrp:
            {
                ITU_T_BIND_TAG(value<ACRP_apdu > (false, ACSE_apdu_acrp));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ACSE_apdu::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(value<AARQ_apdu > (true, ACSE_apdu_aarq))) return;
                else free();
                if (ITU_T_BIND_TAG(value<AARE_apdu > (true, ACSE_apdu_aare))) return;
                else free();
                if (ITU_T_BIND_TAG(value<RLRQ_apdu > (true, ACSE_apdu_rlrq))) return;
                else free();
                if (ITU_T_BIND_TAG(value<RLRE_apdu > (true, ACSE_apdu_rlre))) return;
                else free();
                if (ITU_T_BIND_TAG(value<ABRT_apdu > (true, ACSE_apdu_abrt))) return;
                else free();
                if (ITU_T_BIND_TAG(value<A_DT_apdu > (true, ACSE_apdu_adt))) return;
                else free();
                if (ITU_T_BIND_TAG(value<ACRQ_apdu > (true, ACSE_apdu_acrq))) return;
                else free();
                if (ITU_T_BIND_TAG(value<ACRP_apdu > (true, ACSE_apdu_acrp))) return;
                else free();
            }
        }
    }


    // sequence AARQ-apdu
    const bitstring_type AARQ_apdu_impl::protocol_version_version1 = bitstring_type(true, 0);

    AARQ_apdu_impl::AARQ_apdu_impl() : aSO_context_name_() {
    };

    AARQ_apdu_impl::AARQ_apdu_impl(const ASO_context_name& arg__aSO_context_name) :
    aSO_context_name_(arg__aSO_context_name) {
    };

    AARQ_apdu_impl::AARQ_apdu_impl(boost::shared_ptr< bitstring_type> arg__protocol_version,
            boost::shared_ptr< ASO_context_name> arg__aSO_context_name,
            boost::shared_ptr< AP_title> arg__called_AP_title,
            boost::shared_ptr< AE_qualifier> arg__called_AE_qualifier,
            boost::shared_ptr< AP_invocation_identifier> arg__called_AP_invocation_identifier,
            boost::shared_ptr< AE_invocation_identifier> arg__called_AE_invocation_identifier,
            boost::shared_ptr< AP_title> arg__calling_AP_title,
            boost::shared_ptr< AE_qualifier> arg__calling_AE_qualifier,
            boost::shared_ptr< AP_invocation_identifier> arg__calling_AP_invocation_identifier,
            boost::shared_ptr< AE_invocation_identifier> arg__calling_AE_invocation_identifier,
            boost::shared_ptr< ACSE_requirements> arg__sender_acse_requirements,
            boost::shared_ptr< Mechanism_name> arg__mechanism_name,
            boost::shared_ptr< Authentication_value> arg__calling_authentication_value,
            boost::shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
            boost::shared_ptr< Implementation_data> arg__implementation_information,
            boost::shared_ptr< Syntactic_context_list> arg__p_context_definition_list,
            boost::shared_ptr< ASOI_tag> arg__called_asoi_tag,
            boost::shared_ptr< ASOI_tag> arg__calling_asoi_tag,
            boost::shared_ptr< Association_data> arg__user_information) :
    protocol_version_(arg__protocol_version),
    aSO_context_name_(arg__aSO_context_name),
    called_AP_title_(arg__called_AP_title),
    called_AE_qualifier_(arg__called_AE_qualifier),
    called_AP_invocation_identifier_(arg__called_AP_invocation_identifier),
    called_AE_invocation_identifier_(arg__called_AE_invocation_identifier),
    calling_AP_title_(arg__calling_AP_title),
    calling_AE_qualifier_(arg__calling_AE_qualifier),
    calling_AP_invocation_identifier_(arg__calling_AP_invocation_identifier),
    calling_AE_invocation_identifier_(arg__calling_AE_invocation_identifier),
    sender_acse_requirements_(arg__sender_acse_requirements),
    mechanism_name_(arg__mechanism_name),
    calling_authentication_value_(arg__calling_authentication_value),
    aSO_context_name_list_(arg__aSO_context_name_list),
    implementation_information_(arg__implementation_information),
    p_context_definition_list_(arg__p_context_definition_list),
    called_asoi_tag_(arg__called_asoi_tag),
    calling_asoi_tag_(arg__calling_asoi_tag),
    user_information_(arg__user_information) {
    };

    const bitstring_type AARQ_apdu_impl::protocol_version__default = protocol_version_version1;

    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_EXPLICIT_TAG(aSO_context_name_, 1);
        ITU_T_CHOICE_TAG(called_AP_title_, 2);
        ITU_T_CHOICE_TAG(called_AE_qualifier_, 3);
        ITU_T_EXPLICIT_TAG(called_AP_invocation_identifier_, 4);
        ITU_T_EXPLICIT_TAG(called_AE_invocation_identifier_, 5);
        ITU_T_CHOICE_TAG(calling_AP_title_, 6);
        ITU_T_CHOICE_TAG(calling_AE_qualifier_, 7);
        ITU_T_EXPLICIT_TAG(calling_AP_invocation_identifier_, 8);
        ITU_T_EXPLICIT_TAG(calling_AE_invocation_identifier_, 9);
        ITU_T_IMPLICIT_TAG(sender_acse_requirements_, 10);
        ITU_T_IMPLICIT_TAG(mechanism_name_, 11);
        ITU_T_CHOICE_TAG(calling_authentication_value_, 12);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 13);
        ITU_T_IMPLICIT_TAG(implementation_information_, 29);
        ITU_T_CHOICE_TAG(p_context_definition_list_, 14);
        ITU_T_IMPLICIT_TAG(called_asoi_tag_, 15);
        ITU_T_IMPLICIT_TAG(calling_asoi_tag_, 16);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void AARQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_EXPLICIT_TAG(aSO_context_name_, 1);
        ITU_T_CHOICE_TAG(called_AP_title_, 2);
        ITU_T_CHOICE_TAG(called_AE_qualifier_, 3);
        ITU_T_EXPLICIT_TAG(called_AP_invocation_identifier_, 4);
        ITU_T_EXPLICIT_TAG(called_AE_invocation_identifier_, 5);
        ITU_T_CHOICE_TAG(calling_AP_title_, 6);
        ITU_T_CHOICE_TAG(calling_AE_qualifier_, 7);
        ITU_T_EXPLICIT_TAG(calling_AP_invocation_identifier_, 8);
        ITU_T_EXPLICIT_TAG(calling_AE_invocation_identifier_, 9);
        ITU_T_IMPLICIT_TAG(sender_acse_requirements_, 10);
        ITU_T_IMPLICIT_TAG(mechanism_name_, 11);
        ITU_T_CHOICE_TAG(calling_authentication_value_, 12);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 13);
        ITU_T_IMPLICIT_TAG(implementation_information_, 29);
        ITU_T_CHOICE_TAG(p_context_definition_list_, 14);
        ITU_T_IMPLICIT_TAG(called_asoi_tag_, 15);
        ITU_T_IMPLICIT_TAG(calling_asoi_tag_, 16);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    const bitstring_type& AARQ_apdu_impl::protocol_version() const {
        return *protocol_version_;
    }

    void AARQ_apdu_impl::protocol_version(const bitstring_type& vl) {
        protocol_version_ = vl;
    }

    void AARQ_apdu_impl::protocol_version(boost::shared_ptr< bitstring_type> vl) {
        protocol_version_ = vl;
    }

    ASO_context_name& AARQ_apdu_impl::aSO_context_name() {
        return *aSO_context_name_;
    }

    const ASO_context_name& AARQ_apdu_impl::aSO_context_name() const {
        return *aSO_context_name_;
    }

    void AARQ_apdu_impl::aSO_context_name(const ASO_context_name& vl) {
        aSO_context_name_ = vl;
    }

    void AARQ_apdu_impl::aSO_context_name(boost::shared_ptr< ASO_context_name> vl) {
        aSO_context_name_ = vl;
    }

    boost::shared_ptr<AP_title> AARQ_apdu_impl::called_AP_title__new() {
        return called_AP_title_ = boost::shared_ptr<AP_title>(new AP_title());
    }

    void AARQ_apdu_impl::called_AP_title(const AP_title& vl) {
        called_AP_title_ = boost::shared_ptr<AP_title>(new AP_title(vl));
    }

    boost::shared_ptr<AE_qualifier> AARQ_apdu_impl::called_AE_qualifier__new() {
        return called_AE_qualifier_ = boost::shared_ptr<AE_qualifier>(new AE_qualifier());
    }

    void AARQ_apdu_impl::called_AE_qualifier(const AE_qualifier& vl) {
        called_AE_qualifier_ = boost::shared_ptr<AE_qualifier>(new AE_qualifier(vl));
    }

    boost::shared_ptr<AP_invocation_identifier> AARQ_apdu_impl::called_AP_invocation_identifier__new() {
        return called_AP_invocation_identifier_ = boost::shared_ptr<AP_invocation_identifier>(new AP_invocation_identifier());
    }

    void AARQ_apdu_impl::called_AP_invocation_identifier(const AP_invocation_identifier& vl) {
        called_AP_invocation_identifier_ = boost::shared_ptr<AP_invocation_identifier>(new AP_invocation_identifier(vl));
    }

    boost::shared_ptr<AE_invocation_identifier> AARQ_apdu_impl::called_AE_invocation_identifier__new() {
        return called_AE_invocation_identifier_ = boost::shared_ptr<AE_invocation_identifier>(new AE_invocation_identifier());
    }

    void AARQ_apdu_impl::called_AE_invocation_identifier(const AE_invocation_identifier& vl) {
        called_AE_invocation_identifier_ = boost::shared_ptr<AE_invocation_identifier>(new AE_invocation_identifier(vl));
    }

    boost::shared_ptr<AP_title> AARQ_apdu_impl::calling_AP_title__new() {
        return calling_AP_title_ = boost::shared_ptr<AP_title>(new AP_title());
    }

    void AARQ_apdu_impl::calling_AP_title(const AP_title& vl) {
        calling_AP_title_ = boost::shared_ptr<AP_title>(new AP_title(vl));
    }

    boost::shared_ptr<AE_qualifier> AARQ_apdu_impl::calling_AE_qualifier__new() {
        return calling_AE_qualifier_ = boost::shared_ptr<AE_qualifier>(new AE_qualifier());
    }

    void AARQ_apdu_impl::calling_AE_qualifier(const AE_qualifier& vl) {
        calling_AE_qualifier_ = boost::shared_ptr<AE_qualifier>(new AE_qualifier(vl));
    }

    boost::shared_ptr<AP_invocation_identifier> AARQ_apdu_impl::calling_AP_invocation_identifier__new() {
        return calling_AP_invocation_identifier_ = boost::shared_ptr<AP_invocation_identifier>(new AP_invocation_identifier());
    }

    void AARQ_apdu_impl::calling_AP_invocation_identifier(const AP_invocation_identifier& vl) {
        calling_AP_invocation_identifier_ = boost::shared_ptr<AP_invocation_identifier>(new AP_invocation_identifier(vl));
    }

    boost::shared_ptr<AE_invocation_identifier> AARQ_apdu_impl::calling_AE_invocation_identifier__new() {
        return calling_AE_invocation_identifier_ = boost::shared_ptr<AE_invocation_identifier>(new AE_invocation_identifier());
    }

    void AARQ_apdu_impl::calling_AE_invocation_identifier(const AE_invocation_identifier& vl) {
        calling_AE_invocation_identifier_ = boost::shared_ptr<AE_invocation_identifier>(new AE_invocation_identifier(vl));
    }

    boost::shared_ptr<ACSE_requirements> AARQ_apdu_impl::sender_acse_requirements__new() {
        return sender_acse_requirements_ = boost::shared_ptr<ACSE_requirements>(new ACSE_requirements());
    }

    void AARQ_apdu_impl::sender_acse_requirements(const ACSE_requirements& vl) {
        sender_acse_requirements_ = boost::shared_ptr<ACSE_requirements>(new ACSE_requirements(vl));
    }

    boost::shared_ptr<Mechanism_name> AARQ_apdu_impl::mechanism_name__new() {
        return mechanism_name_ = boost::shared_ptr<Mechanism_name>(new Mechanism_name());
    }

    void AARQ_apdu_impl::mechanism_name(const Mechanism_name& vl) {
        mechanism_name_ = boost::shared_ptr<Mechanism_name>(new Mechanism_name(vl));
    }

    boost::shared_ptr<Authentication_value> AARQ_apdu_impl::calling_authentication_value__new() {
        return calling_authentication_value_ = boost::shared_ptr<Authentication_value>(new Authentication_value());
    }

    void AARQ_apdu_impl::calling_authentication_value(const Authentication_value& vl) {
        calling_authentication_value_ = boost::shared_ptr<Authentication_value>(new Authentication_value(vl));
    }

    boost::shared_ptr<ASO_context_name_list> AARQ_apdu_impl::aSO_context_name_list__new() {
        return aSO_context_name_list_ = boost::shared_ptr<ASO_context_name_list>(new ASO_context_name_list());
    }

    void AARQ_apdu_impl::aSO_context_name_list(const ASO_context_name_list& vl) {
        aSO_context_name_list_ = boost::shared_ptr<ASO_context_name_list>(new ASO_context_name_list(vl));
    }

    boost::shared_ptr<Implementation_data> AARQ_apdu_impl::implementation_information__new() {
        return implementation_information_ = boost::shared_ptr<Implementation_data>(new Implementation_data());
    }

    void AARQ_apdu_impl::implementation_information(const Implementation_data& vl) {
        implementation_information_ = boost::shared_ptr<Implementation_data>(new Implementation_data(vl));
    }

    boost::shared_ptr<Syntactic_context_list> AARQ_apdu_impl::p_context_definition_list__new() {
        return p_context_definition_list_ = boost::shared_ptr<Syntactic_context_list>(new Syntactic_context_list());
    }

    void AARQ_apdu_impl::p_context_definition_list(const Syntactic_context_list& vl) {
        p_context_definition_list_ = boost::shared_ptr<Syntactic_context_list>(new Syntactic_context_list(vl));
    }

    boost::shared_ptr<ASOI_tag> AARQ_apdu_impl::called_asoi_tag__new() {
        return called_asoi_tag_ = boost::shared_ptr<ASOI_tag>(new ASOI_tag());
    }

    void AARQ_apdu_impl::called_asoi_tag(const ASOI_tag& vl) {
        called_asoi_tag_ = boost::shared_ptr<ASOI_tag>(new ASOI_tag(vl));
    }

    boost::shared_ptr<ASOI_tag> AARQ_apdu_impl::calling_asoi_tag__new() {
        return calling_asoi_tag_ = boost::shared_ptr<ASOI_tag>(new ASOI_tag());
    }

    void AARQ_apdu_impl::calling_asoi_tag(const ASOI_tag& vl) {
        calling_asoi_tag_ = boost::shared_ptr<ASOI_tag>(new ASOI_tag(vl));
    }

    boost::shared_ptr<Association_data> AARQ_apdu_impl::user_information__new() {
        return user_information_ = boost::shared_ptr<Association_data>(new Association_data());
    }

    void AARQ_apdu_impl::user_information(const Association_data& vl) {
        user_information_ = boost::shared_ptr<Association_data>(new Association_data(vl));
    }


    // sequence AARE-apdu
    const bitstring_type AARE_apdu_impl::protocol_version_version1 = bitstring_type(true, 0);

    AARE_apdu_impl::AARE_apdu_impl() : aSO_context_name_(), result_(), result_source_diagnostic_() {
    };

    AARE_apdu_impl::AARE_apdu_impl(const ASO_context_name& arg__aSO_context_name,
            const Associate_result& arg__result,
            const Associate_source_diagnostic& arg__result_source_diagnostic) :
    aSO_context_name_(arg__aSO_context_name),
    result_(arg__result),
    result_source_diagnostic_(arg__result_source_diagnostic) {
    };

    AARE_apdu_impl::AARE_apdu_impl(boost::shared_ptr< bitstring_type> arg__protocol_version,
            boost::shared_ptr< ASO_context_name> arg__aSO_context_name,
            boost::shared_ptr< Associate_result> arg__result,
            boost::shared_ptr< Associate_source_diagnostic> arg__result_source_diagnostic,
            boost::shared_ptr< AP_title> arg__responding_AP_title,
            boost::shared_ptr< AE_qualifier> arg__responding_AE_qualifier,
            boost::shared_ptr< AP_invocation_identifier> arg__responding_AP_invocation_identifier,
            boost::shared_ptr< AE_invocation_identifier> arg__responding_AE_invocation_identifier,
            boost::shared_ptr< ACSE_requirements> arg__responder_acse_requirements,
            boost::shared_ptr< Mechanism_name> arg__mechanism_name,
            boost::shared_ptr< Authentication_value> arg__responding_authentication_value,
            boost::shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
            boost::shared_ptr< Implementation_data> arg__implementation_information,
            boost::shared_ptr< P_context_result_list> arg__p_context_result_list,
            boost::shared_ptr< ASOI_tag> arg__called_asoi_tag,
            boost::shared_ptr< ASOI_tag> arg__calling_asoi_tag,
            boost::shared_ptr< Association_data> arg__user_information) :
    protocol_version_(arg__protocol_version),
    aSO_context_name_(arg__aSO_context_name),
    result_(arg__result),
    result_source_diagnostic_(arg__result_source_diagnostic),
    responding_AP_title_(arg__responding_AP_title),
    responding_AE_qualifier_(arg__responding_AE_qualifier),
    responding_AP_invocation_identifier_(arg__responding_AP_invocation_identifier),
    responding_AE_invocation_identifier_(arg__responding_AE_invocation_identifier),
    responder_acse_requirements_(arg__responder_acse_requirements),
    mechanism_name_(arg__mechanism_name),
    responding_authentication_value_(arg__responding_authentication_value),
    aSO_context_name_list_(arg__aSO_context_name_list),
    implementation_information_(arg__implementation_information),
    p_context_result_list_(arg__p_context_result_list),
    called_asoi_tag_(arg__called_asoi_tag),
    calling_asoi_tag_(arg__calling_asoi_tag),
    user_information_(arg__user_information) {
    };

    const bitstring_type AARE_apdu_impl::protocol_version__default = protocol_version_version1;

    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_EXPLICIT_TAG(aSO_context_name_, 1);
        ITU_T_EXPLICIT_TAG(result_, 2);
        ITU_T_CHOICE_TAG(result_source_diagnostic_, 3);
        ITU_T_CHOICE_TAG(responding_AP_title_, 4);
        ITU_T_CHOICE_TAG(responding_AE_qualifier_, 5);
        ITU_T_EXPLICIT_TAG(responding_AP_invocation_identifier_, 6);
        ITU_T_EXPLICIT_TAG(responding_AE_invocation_identifier_, 7);
        ITU_T_IMPLICIT_TAG(responder_acse_requirements_, 8);
        ITU_T_IMPLICIT_TAG(mechanism_name_, 9);
        ITU_T_CHOICE_TAG(responding_authentication_value_, 10);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 11);
        ITU_T_IMPLICIT_TAG(implementation_information_, 29);
        ITU_T_IMPLICIT_TAG(p_context_result_list_, 12);
        ITU_T_IMPLICIT_TAG(called_asoi_tag_, 13);
        ITU_T_IMPLICIT_TAG(calling_asoi_tag_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void AARE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_EXPLICIT_TAG(aSO_context_name_, 1);
        ITU_T_EXPLICIT_TAG(result_, 2);
        ITU_T_CHOICE_TAG(result_source_diagnostic_, 3);
        ITU_T_CHOICE_TAG(responding_AP_title_, 4);
        ITU_T_CHOICE_TAG(responding_AE_qualifier_, 5);
        ITU_T_EXPLICIT_TAG(responding_AP_invocation_identifier_, 6);
        ITU_T_EXPLICIT_TAG(responding_AE_invocation_identifier_, 7);
        ITU_T_IMPLICIT_TAG(responder_acse_requirements_, 8);
        ITU_T_IMPLICIT_TAG(mechanism_name_, 9);
        ITU_T_CHOICE_TAG(responding_authentication_value_, 10);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 11);
        ITU_T_IMPLICIT_TAG(implementation_information_, 29);
        ITU_T_IMPLICIT_TAG(p_context_result_list_, 12);
        ITU_T_IMPLICIT_TAG(called_asoi_tag_, 13);
        ITU_T_IMPLICIT_TAG(calling_asoi_tag_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    const bitstring_type& AARE_apdu_impl::protocol_version() const {
        return *protocol_version_;
    }

    void AARE_apdu_impl::protocol_version(const bitstring_type& vl) {
        protocol_version_ = vl;
    }

    void AARE_apdu_impl::protocol_version(boost::shared_ptr< bitstring_type> vl) {
        protocol_version_ = vl;
    }

    ASO_context_name& AARE_apdu_impl::aSO_context_name() {
        return *aSO_context_name_;
    }

    const ASO_context_name& AARE_apdu_impl::aSO_context_name() const {
        return *aSO_context_name_;
    }

    void AARE_apdu_impl::aSO_context_name(const ASO_context_name& vl) {
        aSO_context_name_ = vl;
    }

    void AARE_apdu_impl::aSO_context_name(boost::shared_ptr< ASO_context_name> vl) {
        aSO_context_name_ = vl;
    }

    Associate_result& AARE_apdu_impl::result() {
        return *result_;
    }

    const Associate_result& AARE_apdu_impl::result() const {
        return *result_;
    }

    void AARE_apdu_impl::result(const Associate_result& vl) {
        result_ = vl;
    }

    void AARE_apdu_impl::result(boost::shared_ptr< Associate_result> vl) {
        result_ = vl;
    }

    Associate_source_diagnostic& AARE_apdu_impl::result_source_diagnostic() {
        return *result_source_diagnostic_;
    }

    const Associate_source_diagnostic& AARE_apdu_impl::result_source_diagnostic() const {
        return *result_source_diagnostic_;
    }

    void AARE_apdu_impl::result_source_diagnostic(const Associate_source_diagnostic& vl) {
        result_source_diagnostic_ = vl;
    }

    void AARE_apdu_impl::result_source_diagnostic(boost::shared_ptr< Associate_source_diagnostic> vl) {
        result_source_diagnostic_ = vl;
    }

    boost::shared_ptr<AP_title> AARE_apdu_impl::responding_AP_title__new() {
        return responding_AP_title_ = boost::shared_ptr<AP_title>(new AP_title());
    }

    void AARE_apdu_impl::responding_AP_title(const AP_title& vl) {
        responding_AP_title_ = boost::shared_ptr<AP_title>(new AP_title(vl));
    }

    boost::shared_ptr<AE_qualifier> AARE_apdu_impl::responding_AE_qualifier__new() {
        return responding_AE_qualifier_ = boost::shared_ptr<AE_qualifier>(new AE_qualifier());
    }

    void AARE_apdu_impl::responding_AE_qualifier(const AE_qualifier& vl) {
        responding_AE_qualifier_ = boost::shared_ptr<AE_qualifier>(new AE_qualifier(vl));
    }

    boost::shared_ptr<AP_invocation_identifier> AARE_apdu_impl::responding_AP_invocation_identifier__new() {
        return responding_AP_invocation_identifier_ = boost::shared_ptr<AP_invocation_identifier>(new AP_invocation_identifier());
    }

    void AARE_apdu_impl::responding_AP_invocation_identifier(const AP_invocation_identifier& vl) {
        responding_AP_invocation_identifier_ = boost::shared_ptr<AP_invocation_identifier>(new AP_invocation_identifier(vl));
    }

    boost::shared_ptr<AE_invocation_identifier> AARE_apdu_impl::responding_AE_invocation_identifier__new() {
        return responding_AE_invocation_identifier_ = boost::shared_ptr<AE_invocation_identifier>(new AE_invocation_identifier());
    }

    void AARE_apdu_impl::responding_AE_invocation_identifier(const AE_invocation_identifier& vl) {
        responding_AE_invocation_identifier_ = boost::shared_ptr<AE_invocation_identifier>(new AE_invocation_identifier(vl));
    }

    boost::shared_ptr<ACSE_requirements> AARE_apdu_impl::responder_acse_requirements__new() {
        return responder_acse_requirements_ = boost::shared_ptr<ACSE_requirements>(new ACSE_requirements());
    }

    void AARE_apdu_impl::responder_acse_requirements(const ACSE_requirements& vl) {
        responder_acse_requirements_ = boost::shared_ptr<ACSE_requirements>(new ACSE_requirements(vl));
    }

    boost::shared_ptr<Mechanism_name> AARE_apdu_impl::mechanism_name__new() {
        return mechanism_name_ = boost::shared_ptr<Mechanism_name>(new Mechanism_name());
    }

    void AARE_apdu_impl::mechanism_name(const Mechanism_name& vl) {
        mechanism_name_ = boost::shared_ptr<Mechanism_name>(new Mechanism_name(vl));
    }

    boost::shared_ptr<Authentication_value> AARE_apdu_impl::responding_authentication_value__new() {
        return responding_authentication_value_ = boost::shared_ptr<Authentication_value>(new Authentication_value());
    }

    void AARE_apdu_impl::responding_authentication_value(const Authentication_value& vl) {
        responding_authentication_value_ = boost::shared_ptr<Authentication_value>(new Authentication_value(vl));
    }

    boost::shared_ptr<ASO_context_name_list> AARE_apdu_impl::aSO_context_name_list__new() {
        return aSO_context_name_list_ = boost::shared_ptr<ASO_context_name_list>(new ASO_context_name_list());
    }

    void AARE_apdu_impl::aSO_context_name_list(const ASO_context_name_list& vl) {
        aSO_context_name_list_ = boost::shared_ptr<ASO_context_name_list>(new ASO_context_name_list(vl));
    }

    boost::shared_ptr<Implementation_data> AARE_apdu_impl::implementation_information__new() {
        return implementation_information_ = boost::shared_ptr<Implementation_data>(new Implementation_data());
    }

    void AARE_apdu_impl::implementation_information(const Implementation_data& vl) {
        implementation_information_ = boost::shared_ptr<Implementation_data>(new Implementation_data(vl));
    }

    boost::shared_ptr<P_context_result_list> AARE_apdu_impl::p_context_result_list__new() {
        return p_context_result_list_ = boost::shared_ptr<P_context_result_list>(new P_context_result_list());
    }

    void AARE_apdu_impl::p_context_result_list(const P_context_result_list& vl) {
        p_context_result_list_ = boost::shared_ptr<P_context_result_list>(new P_context_result_list(vl));
    }

    boost::shared_ptr<ASOI_tag> AARE_apdu_impl::called_asoi_tag__new() {
        return called_asoi_tag_ = boost::shared_ptr<ASOI_tag>(new ASOI_tag());
    }

    void AARE_apdu_impl::called_asoi_tag(const ASOI_tag& vl) {
        called_asoi_tag_ = boost::shared_ptr<ASOI_tag>(new ASOI_tag(vl));
    }

    boost::shared_ptr<ASOI_tag> AARE_apdu_impl::calling_asoi_tag__new() {
        return calling_asoi_tag_ = boost::shared_ptr<ASOI_tag>(new ASOI_tag());
    }

    void AARE_apdu_impl::calling_asoi_tag(const ASOI_tag& vl) {
        calling_asoi_tag_ = boost::shared_ptr<ASOI_tag>(new ASOI_tag(vl));
    }

    boost::shared_ptr<Association_data> AARE_apdu_impl::user_information__new() {
        return user_information_ = boost::shared_ptr<Association_data>(new Association_data());
    }

    void AARE_apdu_impl::user_information(const Association_data& vl) {
        user_information_ = boost::shared_ptr<Association_data>(new Association_data(vl));
    }


    // sequence RLRQ-apdu

    RLRQ_apdu_impl::RLRQ_apdu_impl() {
    };

    RLRQ_apdu_impl::RLRQ_apdu_impl(boost::shared_ptr< Release_request_reason> arg__reason,
            boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
            boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
            boost::shared_ptr< Association_data> arg__user_information) :
    reason_(arg__reason),
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    user_information_(arg__user_information) {
    };

    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(reason_, 0);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void RLRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(reason_, 0);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    boost::shared_ptr<Release_request_reason> RLRQ_apdu_impl::reason__new() {
        return reason_ = boost::shared_ptr<Release_request_reason>(new Release_request_reason());
    }

    void RLRQ_apdu_impl::reason(const Release_request_reason& vl) {
        reason_ = boost::shared_ptr<Release_request_reason>(new Release_request_reason(vl));
    }

    boost::shared_ptr<ASO_qualifier> RLRQ_apdu_impl::aso_qualifier__new() {
        return aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier());
    }

    void RLRQ_apdu_impl::aso_qualifier(const ASO_qualifier& vl) {
        aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier(vl));
    }

    boost::shared_ptr<ASOI_identifier> RLRQ_apdu_impl::asoi_identifier__new() {
        return asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier());
    }

    void RLRQ_apdu_impl::asoi_identifier(const ASOI_identifier& vl) {
        asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier(vl));
    }

    boost::shared_ptr<Association_data> RLRQ_apdu_impl::user_information__new() {
        return user_information_ = boost::shared_ptr<Association_data>(new Association_data());
    }

    void RLRQ_apdu_impl::user_information(const Association_data& vl) {
        user_information_ = boost::shared_ptr<Association_data>(new Association_data(vl));
    }


    // sequence RLRE-apdu

    RLRE_apdu_impl::RLRE_apdu_impl() {
    };

    RLRE_apdu_impl::RLRE_apdu_impl(boost::shared_ptr< Release_response_reason> arg__reason,
            boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
            boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
            boost::shared_ptr< Association_data> arg__user_information) :
    reason_(arg__reason),
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    user_information_(arg__user_information) {
    };

    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(reason_, 0);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void RLRE_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(reason_, 0);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    boost::shared_ptr<Release_response_reason> RLRE_apdu_impl::reason__new() {
        return reason_ = boost::shared_ptr<Release_response_reason>(new Release_response_reason());
    }

    void RLRE_apdu_impl::reason(const Release_response_reason& vl) {
        reason_ = boost::shared_ptr<Release_response_reason>(new Release_response_reason(vl));
    }

    boost::shared_ptr<ASO_qualifier> RLRE_apdu_impl::aso_qualifier__new() {
        return aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier());
    }

    void RLRE_apdu_impl::aso_qualifier(const ASO_qualifier& vl) {
        aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier(vl));
    }

    boost::shared_ptr<ASOI_identifier> RLRE_apdu_impl::asoi_identifier__new() {
        return asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier());
    }

    void RLRE_apdu_impl::asoi_identifier(const ASOI_identifier& vl) {
        asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier(vl));
    }

    boost::shared_ptr<Association_data> RLRE_apdu_impl::user_information__new() {
        return user_information_ = boost::shared_ptr<Association_data>(new Association_data());
    }

    void RLRE_apdu_impl::user_information(const Association_data& vl) {
        user_information_ = boost::shared_ptr<Association_data>(new Association_data(vl));
    }


    // sequence ABRT-apdu

    ABRT_apdu_impl::ABRT_apdu_impl() : abort_source_() {
    };

    ABRT_apdu_impl::ABRT_apdu_impl(const ABRT_source& arg__abort_source) :
    abort_source_(arg__abort_source) {
    };

    ABRT_apdu_impl::ABRT_apdu_impl(boost::shared_ptr< ABRT_source> arg__abort_source,
            boost::shared_ptr< ABRT_diagnostic> arg__abort_diagnostic,
            boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
            boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
            boost::shared_ptr< Association_data> arg__user_information) :
    abort_source_(arg__abort_source),
    abort_diagnostic_(arg__abort_diagnostic),
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    user_information_(arg__user_information) {
    };

    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(abort_source_, 0);
        ITU_T_IMPLICIT_TAG(abort_diagnostic_, 1);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void ABRT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(abort_source_, 0);
        ITU_T_IMPLICIT_TAG(abort_diagnostic_, 1);
        ITU_T_CHOICE_TAG(aso_qualifier_, 13);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 14);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    ABRT_source& ABRT_apdu_impl::abort_source() {
        return *abort_source_;
    }

    const ABRT_source& ABRT_apdu_impl::abort_source() const {
        return *abort_source_;
    }

    void ABRT_apdu_impl::abort_source(const ABRT_source& vl) {
        abort_source_ = vl;
    }

    void ABRT_apdu_impl::abort_source(boost::shared_ptr< ABRT_source> vl) {
        abort_source_ = vl;
    }

    boost::shared_ptr<ABRT_diagnostic> ABRT_apdu_impl::abort_diagnostic__new() {
        return abort_diagnostic_ = boost::shared_ptr<ABRT_diagnostic>(new ABRT_diagnostic());
    }

    void ABRT_apdu_impl::abort_diagnostic(const ABRT_diagnostic& vl) {
        abort_diagnostic_ = boost::shared_ptr<ABRT_diagnostic>(new ABRT_diagnostic(vl));
    }

    boost::shared_ptr<ASO_qualifier> ABRT_apdu_impl::aso_qualifier__new() {
        return aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier());
    }

    void ABRT_apdu_impl::aso_qualifier(const ASO_qualifier& vl) {
        aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier(vl));
    }

    boost::shared_ptr<ASOI_identifier> ABRT_apdu_impl::asoi_identifier__new() {
        return asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier());
    }

    void ABRT_apdu_impl::asoi_identifier(const ASOI_identifier& vl) {
        asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier(vl));
    }

    boost::shared_ptr<Association_data> ABRT_apdu_impl::user_information__new() {
        return user_information_ = boost::shared_ptr<Association_data>(new Association_data());
    }

    void ABRT_apdu_impl::user_information(const Association_data& vl) {
        user_information_ = boost::shared_ptr<Association_data>(new Association_data(vl));
    }


    // sequence A-DT-apdu

    A_DT_apdu_impl::A_DT_apdu_impl() : a_user_data_() {
    };

    A_DT_apdu_impl::A_DT_apdu_impl(const User_Data& arg__a_user_data) :
    a_user_data_(arg__a_user_data) {
    };

    A_DT_apdu_impl::A_DT_apdu_impl(boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
            boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
            boost::shared_ptr< User_Data> arg__a_user_data) :
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    a_user_data_(arg__a_user_data) {
    };

    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_CHOICE_TAG(a_user_data_, 30);
    }

    template<> void A_DT_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_CHOICE_TAG(a_user_data_, 30);
    }

    boost::shared_ptr<ASO_qualifier> A_DT_apdu_impl::aso_qualifier__new() {
        return aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier());
    }

    void A_DT_apdu_impl::aso_qualifier(const ASO_qualifier& vl) {
        aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier(vl));
    }

    boost::shared_ptr<ASOI_identifier> A_DT_apdu_impl::asoi_identifier__new() {
        return asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier());
    }

    void A_DT_apdu_impl::asoi_identifier(const ASOI_identifier& vl) {
        asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier(vl));
    }

    User_Data& A_DT_apdu_impl::a_user_data() {
        return *a_user_data_;
    }

    const User_Data& A_DT_apdu_impl::a_user_data() const {
        return *a_user_data_;
    }

    void A_DT_apdu_impl::a_user_data(const User_Data& vl) {
        a_user_data_ = vl;
    }

    void A_DT_apdu_impl::a_user_data(boost::shared_ptr< User_Data> vl) {
        a_user_data_ = vl;
    }


    // sequence ACRQ-apdu

    ACRQ_apdu_impl::ACRQ_apdu_impl() {
    };

    ACRQ_apdu_impl::ACRQ_apdu_impl(boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
            boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
            boost::shared_ptr< ASO_context_name> arg__aSO_context_name,
            boost::shared_ptr< ASO_context_name_list> arg__aSO_context_name_list,
            boost::shared_ptr< Syntactic_context_list> arg__p_context_definition_list,
            boost::shared_ptr< User_information> arg__user_information) :
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    aSO_context_name_(arg__aSO_context_name),
    aSO_context_name_list_(arg__aSO_context_name_list),
    p_context_definition_list_(arg__p_context_definition_list),
    user_information_(arg__user_information) {
    };

    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_IMPLICIT_TAG(aSO_context_name_, 3);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 4);
        ITU_T_CHOICE_TAG(p_context_definition_list_, 5);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void ACRQ_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_IMPLICIT_TAG(aSO_context_name_, 3);
        ITU_T_IMPLICIT_TAG(aSO_context_name_list_, 4);
        ITU_T_CHOICE_TAG(p_context_definition_list_, 5);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    boost::shared_ptr<ASO_qualifier> ACRQ_apdu_impl::aso_qualifier__new() {
        return aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier());
    }

    void ACRQ_apdu_impl::aso_qualifier(const ASO_qualifier& vl) {
        aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier(vl));
    }

    boost::shared_ptr<ASOI_identifier> ACRQ_apdu_impl::asoi_identifier__new() {
        return asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier());
    }

    void ACRQ_apdu_impl::asoi_identifier(const ASOI_identifier& vl) {
        asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier(vl));
    }

    boost::shared_ptr<ASO_context_name> ACRQ_apdu_impl::aSO_context_name__new() {
        return aSO_context_name_ = boost::shared_ptr<ASO_context_name>(new ASO_context_name());
    }

    void ACRQ_apdu_impl::aSO_context_name(const ASO_context_name& vl) {
        aSO_context_name_ = boost::shared_ptr<ASO_context_name>(new ASO_context_name(vl));
    }

    boost::shared_ptr<ASO_context_name_list> ACRQ_apdu_impl::aSO_context_name_list__new() {
        return aSO_context_name_list_ = boost::shared_ptr<ASO_context_name_list>(new ASO_context_name_list());
    }

    void ACRQ_apdu_impl::aSO_context_name_list(const ASO_context_name_list& vl) {
        aSO_context_name_list_ = boost::shared_ptr<ASO_context_name_list>(new ASO_context_name_list(vl));
    }

    boost::shared_ptr<Syntactic_context_list> ACRQ_apdu_impl::p_context_definition_list__new() {
        return p_context_definition_list_ = boost::shared_ptr<Syntactic_context_list>(new Syntactic_context_list());
    }

    void ACRQ_apdu_impl::p_context_definition_list(const Syntactic_context_list& vl) {
        p_context_definition_list_ = boost::shared_ptr<Syntactic_context_list>(new Syntactic_context_list(vl));
    }

    boost::shared_ptr<User_information> ACRQ_apdu_impl::user_information__new() {
        return user_information_ = boost::shared_ptr<User_information>(new User_information());
    }

    void ACRQ_apdu_impl::user_information(const User_information& vl) {
        user_information_ = boost::shared_ptr<User_information>(new User_information(vl));
    }


    // sequence ACRP-apdu

    ACRP_apdu_impl::ACRP_apdu_impl() {
    };

    ACRP_apdu_impl::ACRP_apdu_impl(boost::shared_ptr< ASO_qualifier> arg__aso_qualifier,
            boost::shared_ptr< ASOI_identifier> arg__asoi_identifier,
            boost::shared_ptr< ASO_context_name_list> arg__aSO_context_name,
            boost::shared_ptr< P_context_result_list> arg__p_context_result_list,
            boost::shared_ptr< User_information> arg__user_information) :
    aso_qualifier_(arg__aso_qualifier),
    asoi_identifier_(arg__asoi_identifier),
    aSO_context_name_(arg__aSO_context_name),
    p_context_result_list_(arg__p_context_result_list),
    user_information_(arg__user_information) {
    };

    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_IMPLICIT_TAG(aSO_context_name_, 3);
        ITU_T_IMPLICIT_TAG(p_context_result_list_, 4);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    template<> void ACRP_apdu_impl::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(aso_qualifier_, 0);
        ITU_T_IMPLICIT_TAG(asoi_identifier_, 1);
        ITU_T_IMPLICIT_TAG(aSO_context_name_, 3);
        ITU_T_IMPLICIT_TAG(p_context_result_list_, 4);
        ITU_T_IMPLICIT_TAG(user_information_, 30);
    }

    boost::shared_ptr<ASO_qualifier> ACRP_apdu_impl::aso_qualifier__new() {
        return aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier());
    }

    void ACRP_apdu_impl::aso_qualifier(const ASO_qualifier& vl) {
        aso_qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier(vl));
    }

    boost::shared_ptr<ASOI_identifier> ACRP_apdu_impl::asoi_identifier__new() {
        return asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier());
    }

    void ACRP_apdu_impl::asoi_identifier(const ASOI_identifier& vl) {
        asoi_identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier(vl));
    }

    boost::shared_ptr<ASO_context_name_list> ACRP_apdu_impl::aSO_context_name__new() {
        return aSO_context_name_ = boost::shared_ptr<ASO_context_name_list>(new ASO_context_name_list());
    }

    void ACRP_apdu_impl::aSO_context_name(const ASO_context_name_list& vl) {
        aSO_context_name_ = boost::shared_ptr<ASO_context_name_list>(new ASO_context_name_list(vl));
    }

    boost::shared_ptr<P_context_result_list> ACRP_apdu_impl::p_context_result_list__new() {
        return p_context_result_list_ = boost::shared_ptr<P_context_result_list>(new P_context_result_list());
    }

    void ACRP_apdu_impl::p_context_result_list(const P_context_result_list& vl) {
        p_context_result_list_ = boost::shared_ptr<P_context_result_list>(new P_context_result_list(vl));
    }

    boost::shared_ptr<User_information> ACRP_apdu_impl::user_information__new() {
        return user_information_ = boost::shared_ptr<User_information>(new User_information());
    }

    void ACRP_apdu_impl::user_information(const User_information& vl) {
        user_information_ = boost::shared_ptr<User_information>(new User_information(vl));
    }


    const ABRT_diagnostic ABRT_diagnostic_no_reason_given = 1;
    const ABRT_diagnostic ABRT_diagnostic_protocol_error = 2;
    const ABRT_diagnostic ABRT_diagnostic_authentication_mechanism_name_not_recognized = 3;
    const ABRT_diagnostic ABRT_diagnostic_authentication_mechanism_name_required = 4;
    const ABRT_diagnostic ABRT_diagnostic_authentication_failure = 5;
    const ABRT_diagnostic ABRT_diagnostic_authentication_required = 6;

    const ABRT_source ABRT_source_acse_service_user = 0;
    const ABRT_source ABRT_source_acse_service_provider = 1;

    const ACSE_requirements ACSE_requirements_authentication = bitstring_type(true, 0);
    const ACSE_requirements ACSE_requirements_aSO_context_negotiation = bitstring_type(true, 1);
    const ACSE_requirements ACSE_requirements_higher_level_association = bitstring_type(true, 2);
    const ACSE_requirements ACSE_requirements_nested_association = bitstring_type(true, 3);

    // choice AP-title

    template<> void AP_title::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AP_title_ap_title_form1:
            {
                ITU_T_BIND_TAG(value<AP_title_form1 > (false, AP_title_ap_title_form1));
                break;
            }
            case AP_title_ap_title_form2:
            {
                ITU_T_BIND_TAG(value<AP_title_form2 > (false, AP_title_ap_title_form2));
                break;
            }
            case AP_title_ap_title_form3:
            {
                ITU_T_BIND_TAG(value<AP_title_form3 > (false, AP_title_ap_title_form3));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AP_title::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(value<AP_title_form1 > (true, AP_title_ap_title_form1))) return;
                else free();
                if (ITU_T_BIND_TAG(value<AP_title_form2 > (true, AP_title_ap_title_form2))) return;
                else free();
                if (ITU_T_BIND_TAG(value<AP_title_form3 > (true, AP_title_ap_title_form3))) return;
                else free();
            }
        }
    }


    // choice ASO-qualifier

    template<> void ASO_qualifier::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ASO_qualifier_aso_qualifier_form1:
            {
                ITU_T_BIND_TAG(value<ASO_qualifier_form1 > (false, ASO_qualifier_aso_qualifier_form1));
                break;
            }
            case ASO_qualifier_aso_qualifier_form2:
            {
                ITU_T_BIND_TAG(value<ASO_qualifier_form2 > (false, ASO_qualifier_aso_qualifier_form2));
                break;
            }
            case ASO_qualifier_aso_qualifier_form3:
            {
                ITU_T_BIND_TAG(value<ASO_qualifier_form3 > (false, ASO_qualifier_aso_qualifier_form3));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ASO_qualifier::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(value<ASO_qualifier_form1 > (true, ASO_qualifier_aso_qualifier_form1))) return;
                else free();
                if (ITU_T_BIND_TAG(value<ASO_qualifier_form2 > (true, ASO_qualifier_aso_qualifier_form2))) return;
                else free();
                if (ITU_T_BIND_TAG(value<ASO_qualifier_form3 > (true, ASO_qualifier_aso_qualifier_form3))) return;
                else free();
            }
        }
    }


    // choice AE-title

    template<> void AE_title::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case AE_title_ae_title_form1:
            {
                ITU_T_BIND_TAG(value<AE_title_form1 > (false, AE_title_ae_title_form1));
                break;
            }
            case AE_title_ae_title_form2:
            {
                ITU_T_BIND_TAG(value<AE_title_form2 > (false, AE_title_ae_title_form2));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void AE_title::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(value<AE_title_form1 > (true, AE_title_ae_title_form1))) return;
                else free();
                if (ITU_T_BIND_TAG(value<AE_title_form2 > (true, AE_title_ae_title_form2))) return;
                else free();
            }
        }
    }

    ASOI_tag_sequence_of::ASOI_tag_sequence_of() {
    };

    ASOI_tag_sequence_of::ASOI_tag_sequence_of(boost::shared_ptr< ASO_qualifier> arg__qualifier,
            boost::shared_ptr< ASOI_identifier> arg__identifier) :
    qualifier_(arg__qualifier),
    identifier_(arg__identifier) {
    };

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_CHOICE_TAG(qualifier_, 0);
        ITU_T_EXPLICIT_TAG(identifier_, 1);
    }

    template<> void ASOI_tag_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_CHOICE_TAG(qualifier_, 0);
        ITU_T_EXPLICIT_TAG(identifier_, 1);
    }

    boost::shared_ptr<ASO_qualifier> ASOI_tag_sequence_of::qualifier__new() {
        return qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier());
    }

    void ASOI_tag_sequence_of::qualifier(const ASO_qualifier& vl) {
        qualifier_ = boost::shared_ptr<ASO_qualifier>(new ASO_qualifier(vl));
    }

    boost::shared_ptr<ASOI_identifier> ASOI_tag_sequence_of::identifier__new() {
        return identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier());
    }

    void ASOI_tag_sequence_of::identifier(const ASOI_identifier& vl) {
        identifier_ = boost::shared_ptr<ASOI_identifier>(new ASOI_identifier(vl));
    }


    // choice Syntactic-context-list

    template<> void Syntactic_context_list::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Syntactic_context_list_context_list:
            {
                ITU_T_EXPLICIT_TAG(value<Context_list > (false, Syntactic_context_list_context_list), 0);
                break;
            }
            case Syntactic_context_list_default_contact_list:
            {
                ITU_T_EXPLICIT_TAG(value<Default_Context_List > (false, Syntactic_context_list_default_contact_list), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Syntactic_context_list::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<Context_list > (true, Syntactic_context_list_context_list), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<Default_Context_List > (true, Syntactic_context_list_default_contact_list), 1)) return;
                        else free();
                        break;
                    }
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
            }
        }
    }

    Context_list_sequence_of::Context_list_sequence_of() : pci_(), abstract_syntax_(), transfer_syntaxes_() {
    };

    Context_list_sequence_of::Context_list_sequence_of(const Presentation_context_identifier& arg__pci,
            const Abstract_syntax_name& arg__abstract_syntax,
            const transfer_syntaxes_type& arg__transfer_syntaxes) :
    pci_(arg__pci),
    abstract_syntax_(arg__abstract_syntax),
    transfer_syntaxes_(arg__transfer_syntaxes) {
    };

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(pci_);
        ITU_T_BIND_TAG(abstract_syntax_);
        ITU_T_BIND_TAG(transfer_syntaxes_);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(pci_);
        ITU_T_BIND_TAG(abstract_syntax_);
        ITU_T_BIND_TAG(transfer_syntaxes_);
    }

    Presentation_context_identifier& Context_list_sequence_of::pci() {
        return *pci_;
    }

    const Presentation_context_identifier& Context_list_sequence_of::pci() const {
        return *pci_;
    }

    void Context_list_sequence_of::pci(const Presentation_context_identifier& vl) {
        pci_ = vl;
    }

    void Context_list_sequence_of::pci(boost::shared_ptr< Presentation_context_identifier> vl) {
        pci_ = vl;
    }

    Abstract_syntax_name& Context_list_sequence_of::abstract_syntax() {
        return *abstract_syntax_;
    }

    const Abstract_syntax_name& Context_list_sequence_of::abstract_syntax() const {
        return *abstract_syntax_;
    }

    void Context_list_sequence_of::abstract_syntax(const Abstract_syntax_name& vl) {
        abstract_syntax_ = vl;
    }

    void Context_list_sequence_of::abstract_syntax(boost::shared_ptr< Abstract_syntax_name> vl) {
        abstract_syntax_ = vl;
    }

    Context_list_sequence_of::transfer_syntaxes_type& Context_list_sequence_of::transfer_syntaxes() {
        return *transfer_syntaxes_;
    }

    const Context_list_sequence_of::transfer_syntaxes_type& Context_list_sequence_of::transfer_syntaxes() const {
        return *transfer_syntaxes_;
    }

    void Context_list_sequence_of::transfer_syntaxes(const transfer_syntaxes_type& vl) {
        transfer_syntaxes_ = vl;
    }

    void Context_list_sequence_of::transfer_syntaxes(boost::shared_ptr< transfer_syntaxes_type> vl) {
        transfer_syntaxes_ = vl;
    }

    Default_Context_List_sequence_of::Default_Context_List_sequence_of() : transfer_syntax_name_() {
    };

    Default_Context_List_sequence_of::Default_Context_List_sequence_of(const Transfer_syntax_name& arg__transfer_syntax_name) :
    transfer_syntax_name_(arg__transfer_syntax_name) {
    };

    Default_Context_List_sequence_of::Default_Context_List_sequence_of(boost::shared_ptr< Abstract_syntax_name> arg__abstract_syntax_name,
            boost::shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name) :
    abstract_syntax_name_(arg__abstract_syntax_name),
    transfer_syntax_name_(arg__transfer_syntax_name) {
    };

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(abstract_syntax_name_, 0);
        ITU_T_IMPLICIT_TAG(transfer_syntax_name_, 1);
    }

    template<> void Default_Context_List_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(abstract_syntax_name_, 0);
        ITU_T_IMPLICIT_TAG(transfer_syntax_name_, 1);
    }

    boost::shared_ptr<Abstract_syntax_name> Default_Context_List_sequence_of::abstract_syntax_name__new() {
        return abstract_syntax_name_ = boost::shared_ptr<Abstract_syntax_name>(new Abstract_syntax_name());
    }

    void Default_Context_List_sequence_of::abstract_syntax_name(const Abstract_syntax_name& vl) {
        abstract_syntax_name_ = boost::shared_ptr<Abstract_syntax_name>(new Abstract_syntax_name(vl));
    }

    Transfer_syntax_name& Default_Context_List_sequence_of::transfer_syntax_name() {
        return *transfer_syntax_name_;
    }

    const Transfer_syntax_name& Default_Context_List_sequence_of::transfer_syntax_name() const {
        return *transfer_syntax_name_;
    }

    void Default_Context_List_sequence_of::transfer_syntax_name(const Transfer_syntax_name& vl) {
        transfer_syntax_name_ = vl;
    }

    void Default_Context_List_sequence_of::transfer_syntax_name(boost::shared_ptr< Transfer_syntax_name> vl) {
        transfer_syntax_name_ = vl;
    }



    const int P_context_result_list_sequence_of::provider_reason_reason_not_specified = 0;
    const int P_context_result_list_sequence_of::provider_reason_abstract_syntax_not_supported = 1;
    const int P_context_result_list_sequence_of::provider_reason_proposed_transfer_syntaxes_not_supported = 2;
    const int P_context_result_list_sequence_of::provider_reason_local_limit_on_DCS_exceeded = 3;

    P_context_result_list_sequence_of::P_context_result_list_sequence_of() : result_() {
    };

    P_context_result_list_sequence_of::P_context_result_list_sequence_of(const Result& arg__result) :
    result_(arg__result) {
    };

    P_context_result_list_sequence_of::P_context_result_list_sequence_of(boost::shared_ptr< Result> arg__result,
            boost::shared_ptr< Concrete_syntax_name> arg__concrete_syntax_name,
            boost::shared_ptr< int> arg__provider_reason) :
    result_(arg__result),
    concrete_syntax_name_(arg__concrete_syntax_name),
    provider_reason_(arg__provider_reason) {
    };

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(result_, 0);
        ITU_T_IMPLICIT_TAG(concrete_syntax_name_, 1);
        ITU_T_IMPLICIT_TAG(provider_reason_, 2);
    }

    template<> void P_context_result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(result_, 0);
        ITU_T_IMPLICIT_TAG(concrete_syntax_name_, 1);
        ITU_T_IMPLICIT_TAG(provider_reason_, 2);
    }

    Result& P_context_result_list_sequence_of::result() {
        return *result_;
    }

    const Result& P_context_result_list_sequence_of::result() const {
        return *result_;
    }

    void P_context_result_list_sequence_of::result(const Result& vl) {
        result_ = vl;
    }

    void P_context_result_list_sequence_of::result(boost::shared_ptr< Result> vl) {
        result_ = vl;
    }

    boost::shared_ptr<Concrete_syntax_name> P_context_result_list_sequence_of::concrete_syntax_name__new() {
        return concrete_syntax_name_ = boost::shared_ptr<Concrete_syntax_name>(new Concrete_syntax_name());
    }

    void P_context_result_list_sequence_of::concrete_syntax_name(const Concrete_syntax_name& vl) {
        concrete_syntax_name_ = boost::shared_ptr<Concrete_syntax_name>(new Concrete_syntax_name(vl));
    }

    boost::shared_ptr<int> P_context_result_list_sequence_of::provider_reason__new() {
        return provider_reason_ = boost::shared_ptr<int>(new int());
    }

    void P_context_result_list_sequence_of::provider_reason(const int& vl) {
        provider_reason_ = boost::shared_ptr<int>(new int(vl));
    }


    const Result Result_acceptance = 0;
    const Result Result_user_rejection = 1;
    const Result Result_provider_rejection = 2;

    const Associate_result Associate_result_accepted = 0;
    const Associate_result Associate_result_rejected_permanent = 1;
    const Associate_result Associate_result_rejected_transient = 2;

    // choice Associate-source-diagnostic
    const int Associate_source_diagnostic::acse_service_user_null = 0;
    const int Associate_source_diagnostic::acse_service_user_no_reason_given = 1;
    const int Associate_source_diagnostic::acse_service_user_application_context_name_not_supported = 2;
    const int Associate_source_diagnostic::acse_service_user_calling_AP_title_not_recognized = 3;
    const int Associate_source_diagnostic::acse_service_user_calling_AP_invocation_identifier_not_recognized = 4;
    const int Associate_source_diagnostic::acse_service_user_calling_AE_qualifier_not_recognized = 5;
    const int Associate_source_diagnostic::acse_service_user_calling_AE_invocation_identifier_not_recognized = 6;
    const int Associate_source_diagnostic::acse_service_user_called_AP_title_not_recognized = 7;
    const int Associate_source_diagnostic::acse_service_user_called_AP_invocation_identifier_not_recognized = 8;
    const int Associate_source_diagnostic::acse_service_user_called_AE_qualifier_not_recognized = 9;
    const int Associate_source_diagnostic::acse_service_user_called_AE_invocation_identifier_not_recognized = 10;
    const int Associate_source_diagnostic::acse_service_user_authentication_mechanism_name_not_recognized = 11;
    const int Associate_source_diagnostic::acse_service_user_authentication_mechanism_name_required = 12;
    const int Associate_source_diagnostic::acse_service_user_authentication_failure = 13;
    const int Associate_source_diagnostic::acse_service_user_authentication_required = 14;

    const int Associate_source_diagnostic::acse_service_provider_null = 0;
    const int Associate_source_diagnostic::acse_service_provider_no_reason_given = 1;
    const int Associate_source_diagnostic::acse_service_provider_no_common_acse_version = 2;

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Associate_source_diagnostic_acse_service_user:
            {
                ITU_T_EXPLICIT_TAG(value<int > (false, Associate_source_diagnostic_acse_service_user), 1);
                break;
            }
            case Associate_source_diagnostic_acse_service_provider:
            {
                ITU_T_EXPLICIT_TAG(value<int > (false, Associate_source_diagnostic_acse_service_provider), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Associate_source_diagnostic::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 1:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<int > (true, Associate_source_diagnostic_acse_service_user), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<int > (true, Associate_source_diagnostic_acse_service_provider), 2)) return;
                        else free();
                        break;
                    }
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
            }
        }
    }


    // choice User-Data

    template<> void User_Data::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case User_Data_user_information:
            {
                ITU_T_BIND_TAG(value<User_information > (false, User_Data_user_information));
                break;
            }
            case User_Data_simply_encoded_data:
            {
                ITU_T_BIND_TAG(value<Simply_encoded_data > (false, User_Data_simply_encoded_data));
                break;
            }
            case User_Data_fully_encoded_data:
            {
                ITU_T_EXPLICIT_TAG(value<PDV_list > (false, User_Data_fully_encoded_data), 0);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void User_Data::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<PDV_list > (true, User_Data_fully_encoded_data), 0)) return;
                        else free();
                        break;
                    }
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
                if (ITU_T_BIND_TAG(value<User_information > (true, User_Data_user_information))) return;
                else free();
                if (ITU_T_BIND_TAG(value<Simply_encoded_data > (true, User_Data_simply_encoded_data))) return;
                else free();
            }
        }
    }


    // sequence PDV-list

    PDV_list::PDV_list() : presentation_context_identifier_(), presentation_data_values_() {
    };

    PDV_list::PDV_list(const Presentation_context_identifier& arg__presentation_context_identifier,
            const presentation_data_values_type& arg__presentation_data_values) :
    presentation_context_identifier_(arg__presentation_context_identifier),
    presentation_data_values_(arg__presentation_data_values) {
    };

    PDV_list::PDV_list(boost::shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
            boost::shared_ptr< Presentation_context_identifier> arg__presentation_context_identifier,
            boost::shared_ptr< presentation_data_values_type> arg__presentation_data_values) :
    transfer_syntax_name_(arg__transfer_syntax_name),
    presentation_context_identifier_(arg__presentation_context_identifier),
    presentation_data_values_(arg__presentation_data_values) {
    };

    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case presentation_data_values_type_simple_ASN1_type:
            {
                ITU_T_EXPLICIT_TAG(value<any_type > (false, presentation_data_values_type_simple_ASN1_type), 0);
                break;
            }
            case presentation_data_values_type_octet_aligned:
            {
                ITU_T_IMPLICIT_TAG(value<octetstring_type > (false, presentation_data_values_type_octet_aligned), 1);
                break;
            }
            case presentation_data_values_type_arbitrary:
            {
                ITU_T_IMPLICIT_TAG(value<bitstring_type > (false, presentation_data_values_type_arbitrary), 2);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_EXPLICIT_TAG(value<any_type > (true, presentation_data_values_type_simple_ASN1_type), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<octetstring_type > (true, presentation_data_values_type_octet_aligned), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<bitstring_type > (true, presentation_data_values_type_arbitrary), 2)) return;
                        else free();
                        break;
                    }
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
            }
        }
    }

    template<> void PDV_list::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(transfer_syntax_name_);
        ITU_T_BIND_TAG(presentation_context_identifier_);
        ITU_T_CHOICE(presentation_data_values_);
    }

    template<> void PDV_list::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(transfer_syntax_name_);
        ITU_T_BIND_TAG(presentation_context_identifier_);
        ITU_T_CHOICE(presentation_data_values_);
    }

    boost::shared_ptr<Transfer_syntax_name> PDV_list::transfer_syntax_name__new() {
        return transfer_syntax_name_ = boost::shared_ptr<Transfer_syntax_name>(new Transfer_syntax_name());
    }

    void PDV_list::transfer_syntax_name(const Transfer_syntax_name& vl) {
        transfer_syntax_name_ = boost::shared_ptr<Transfer_syntax_name>(new Transfer_syntax_name(vl));
    }

    Presentation_context_identifier& PDV_list::presentation_context_identifier() {
        return *presentation_context_identifier_;
    }

    const Presentation_context_identifier& PDV_list::presentation_context_identifier() const {
        return *presentation_context_identifier_;
    }

    void PDV_list::presentation_context_identifier(const Presentation_context_identifier& vl) {
        presentation_context_identifier_ = vl;
    }

    void PDV_list::presentation_context_identifier(boost::shared_ptr< Presentation_context_identifier> vl) {
        presentation_context_identifier_ = vl;
    }

    PDV_list::presentation_data_values_type& PDV_list::presentation_data_values() {
        return *presentation_data_values_;
    }

    const PDV_list::presentation_data_values_type& PDV_list::presentation_data_values() const {
        return *presentation_data_values_;
    }

    void PDV_list::presentation_data_values(const presentation_data_values_type& vl) {
        presentation_data_values_ = vl;
    }

    void PDV_list::presentation_data_values(boost::shared_ptr< presentation_data_values_type> vl) {
        presentation_data_values_ = vl;
    }


    // choice Authentication-value

    Authentication_value::other_type::other_type() : other_mechanism_name_(), other_mechanism_value_() {
    };

    Authentication_value::other_type::other_type(const any_type& arg__other_mechanism_name,
            const any_type& arg__other_mechanism_value) :
    other_mechanism_name_(arg__other_mechanism_name),
    other_mechanism_value_(arg__other_mechanism_value) {
    };

    template<> void Authentication_value::other_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(other_mechanism_name_);
        ITU_T_BIND_TAG(other_mechanism_value_);
    }

    template<> void Authentication_value::other_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(other_mechanism_name_);
        ITU_T_BIND_TAG(other_mechanism_value_);
    }

    any_type& Authentication_value::other_type::other_mechanism_name() {
        return *other_mechanism_name_;
    }

    const any_type& Authentication_value::other_type::other_mechanism_name() const {
        return *other_mechanism_name_;
    }

    void Authentication_value::other_type::other_mechanism_name(const any_type& vl) {
        other_mechanism_name_ = vl;
    }

    void Authentication_value::other_type::other_mechanism_name(boost::shared_ptr< any_type> vl) {
        other_mechanism_name_ = vl;
    }

    any_type& Authentication_value::other_type::other_mechanism_value() {
        return *other_mechanism_value_;
    }

    const any_type& Authentication_value::other_type::other_mechanism_value() const {
        return *other_mechanism_value_;
    }

    void Authentication_value::other_type::other_mechanism_value(const any_type& vl) {
        other_mechanism_value_ = vl;
    }

    void Authentication_value::other_type::other_mechanism_value(boost::shared_ptr< any_type> vl) {
        other_mechanism_value_ = vl;
    }

    template<> void Authentication_value::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Authentication_value_charstring:
            {
                ITU_T_IMPLICIT_TAG(value<graphicstring_type > (false, Authentication_value_charstring), 0);
                break;
            }
            case Authentication_value_bitstring:
            {
                ITU_T_IMPLICIT_TAG(value<bitstring_type > (false, Authentication_value_bitstring), 1);
                break;
            }
            case Authentication_value_external:
            {
                ITU_T_IMPLICIT_TAG(value<external_type > (false, Authentication_value_external), 2);
                break;
            }
            case Authentication_value_other:
            {
                ITU_T_IMPLICIT_TAG(value<other_type > (false, Authentication_value_other), 3);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Authentication_value::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<graphicstring_type > (true, Authentication_value_charstring), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<bitstring_type > (true, Authentication_value_bitstring), 1)) return;
                        else free();
                        break;
                    }
                    case 2:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<external_type > (true, Authentication_value_external), 2)) return;
                        else free();
                        break;
                    }
                    case 3:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<other_type > (true, Authentication_value_other), 3)) return;
                        else free();
                        break;
                    }
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
            }
        }
    }


    const Release_request_reason Release_request_reason_normal = 0;
    const Release_request_reason Release_request_reason_urgent = 1;
    const Release_request_reason Release_request_reason_user_defined = 30;

    const Release_response_reason Release_response_reason_normal = 0;
    const Release_response_reason Release_response_reason_not_finished = 1;
    const Release_response_reason Release_response_reason_user_defined = 30;

}
