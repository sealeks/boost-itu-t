#include "ISO8823-PRESENTATION.hpp"

namespace ISO8823_PRESENTATION {

    // set CP-type

    CP_type::CP_type() : mode_selector_() {
    };

    CP_type::CP_type(const Mode_selector& arg__mode_selector) :
    mode_selector_(arg__mode_selector) {
    };

    CP_type::CP_type(boost::shared_ptr< Mode_selector> arg__mode_selector,
            boost::shared_ptr< x410_mode_parameters_type> arg__x410_mode_parameters,
            boost::shared_ptr< normal_mode_parameters_type> arg__normal_mode_parameters) :
    mode_selector_(arg__mode_selector),
    x410_mode_parameters_(arg__x410_mode_parameters),
    normal_mode_parameters_(arg__normal_mode_parameters) {
    };


    const int CP_type::x410_mode_parameters_type::dialogueMode_monologue = 0;
    const int CP_type::x410_mode_parameters_type::dialogueMode_twa = 1;

    CP_type::x410_mode_parameters_type::x410_mode_parameters_type() : connectionDataRQ_() {
    };

    CP_type::x410_mode_parameters_type::x410_mode_parameters_type(const Reliable_Transfer_APDU::ConnectionData& arg__connectionDataRQ) :
    connectionDataRQ_(arg__connectionDataRQ) {
    };

    CP_type::x410_mode_parameters_type::x410_mode_parameters_type(boost::shared_ptr< int> arg__checkpointSize,
            boost::shared_ptr< int> arg__windowSize,
            boost::shared_ptr< int> arg__dialogueMode,
            boost::shared_ptr< Reliable_Transfer_APDU::ConnectionData> arg__connectionDataRQ,
            boost::shared_ptr< int> arg__applicationProtocol) :
    checkpointSize_(arg__checkpointSize),
    windowSize_(arg__windowSize),
    dialogueMode_(arg__dialogueMode),
    connectionDataRQ_(arg__connectionDataRQ),
    applicationProtocol_(arg__applicationProtocol) {
    };

    const int CP_type::x410_mode_parameters_type::checkpointSize__default = 0;

    const int CP_type::x410_mode_parameters_type::windowSize__default = 3;

    const int CP_type::x410_mode_parameters_type::dialogueMode__default = 0;

    template<> void CP_type::x410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_IMPLICIT_TAG(dialogueMode_, 2);
        ITU_T_CHOICE_TAG(connectionDataRQ_, 3);
        ITU_T_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    template<> void CP_type::x410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_IMPLICIT_TAG(dialogueMode_, 2);
        ITU_T_CHOICE_TAG(connectionDataRQ_, 3);
        ITU_T_IMPLICIT_TAG(applicationProtocol_, 4);
    }

    const int& CP_type::x410_mode_parameters_type::checkpointSize() const {
        return *checkpointSize_;
    }

    void CP_type::x410_mode_parameters_type::checkpointSize(const int& vl) {
        checkpointSize_ = vl;
    }

    void CP_type::x410_mode_parameters_type::checkpointSize(boost::shared_ptr< int> vl) {
        checkpointSize_ = vl;
    }

    const int& CP_type::x410_mode_parameters_type::windowSize() const {
        return *windowSize_;
    }

    void CP_type::x410_mode_parameters_type::windowSize(const int& vl) {
        windowSize_ = vl;
    }

    void CP_type::x410_mode_parameters_type::windowSize(boost::shared_ptr< int> vl) {
        windowSize_ = vl;
    }

    const int& CP_type::x410_mode_parameters_type::dialogueMode() const {
        return *dialogueMode_;
    }

    void CP_type::x410_mode_parameters_type::dialogueMode(const int& vl) {
        dialogueMode_ = vl;
    }

    void CP_type::x410_mode_parameters_type::dialogueMode(boost::shared_ptr< int> vl) {
        dialogueMode_ = vl;
    }

    Reliable_Transfer_APDU::ConnectionData& CP_type::x410_mode_parameters_type::connectionDataRQ() {
        return *connectionDataRQ_;
    }

    const Reliable_Transfer_APDU::ConnectionData& CP_type::x410_mode_parameters_type::connectionDataRQ() const {
        return *connectionDataRQ_;
    }

    void CP_type::x410_mode_parameters_type::connectionDataRQ(const Reliable_Transfer_APDU::ConnectionData& vl) {
        connectionDataRQ_ = vl;
    }

    void CP_type::x410_mode_parameters_type::connectionDataRQ(boost::shared_ptr< Reliable_Transfer_APDU::ConnectionData> vl) {
        connectionDataRQ_ = vl;
    }

    boost::shared_ptr<int> CP_type::x410_mode_parameters_type::applicationProtocol__new() {
        return applicationProtocol_ = boost::shared_ptr<int>(new int());
    }

    void CP_type::x410_mode_parameters_type::applicationProtocol(const int& vl) {
        applicationProtocol_ = boost::shared_ptr<int>(new int(vl));
    }

    CP_type::normal_mode_parameters_type::normal_mode_parameters_type() {
    };

    CP_type::normal_mode_parameters_type::normal_mode_parameters_type(boost::shared_ptr< Protocol_version> arg__protocol_version,
            boost::shared_ptr< Calling_presentation_selector> arg__calling_presentation_selector,
            boost::shared_ptr< Called_presentation_selector> arg__called_presentation_selector,
            boost::shared_ptr< Presentation_context_definition_list> arg__presentation_context_definition_list,
            boost::shared_ptr< Default_context_name> arg__default_context_name,
            boost::shared_ptr< Presentation_requirements> arg__presentation_requirements,
            boost::shared_ptr< User_session_requirements> arg__user_session_requirements,
            boost::shared_ptr< Protocol_options> arg__protocol_options,
            boost::shared_ptr< Presentation_context_identifier> arg__initiators_nominated_context,
            boost::shared_ptr< extensions_type> arg__extensions,
            boost::shared_ptr< User_data> arg__user_data) :
    protocol_version_(arg__protocol_version),
    calling_presentation_selector_(arg__calling_presentation_selector),
    called_presentation_selector_(arg__called_presentation_selector),
    presentation_context_definition_list_(arg__presentation_context_definition_list),
    default_context_name_(arg__default_context_name),
    presentation_requirements_(arg__presentation_requirements),
    user_session_requirements_(arg__user_session_requirements),
    protocol_options_(arg__protocol_options),
    initiators_nominated_context_(arg__initiators_nominated_context),
    extensions_(arg__extensions),
    user_data_(arg__user_data) {
    };

    CP_type::normal_mode_parameters_type::extensions_type::extensions_type() {
    };

    template<> void CP_type::normal_mode_parameters_type::extensions_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_EXTENTION;
    }

    template<> void CP_type::normal_mode_parameters_type::extensions_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_EXTENTION;
    }


    const Protocol_version CP_type::normal_mode_parameters_type::protocol_version__default = Protocol_version(Protocol_version_version_1);

    const Protocol_options CP_type::normal_mode_parameters_type::protocol_options__default = Protocol_options();

    template<> void CP_type::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(calling_presentation_selector_, 1);
        ITU_T_IMPLICIT_TAG(called_presentation_selector_, 2);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_list_, 4);
        ITU_T_IMPLICIT_TAG(default_context_name_, 6);
        ITU_T_IMPLICIT_TAG(presentation_requirements_, 8);
        ITU_T_IMPLICIT_TAG(user_session_requirements_, 9);
        ITU_T_EXPLICIT_TAG(protocol_options_, 11);
        ITU_T_EXPLICIT_TAG(initiators_nominated_context_, 12);
        ITU_T_EXPLICIT_TAG(extensions_, 14);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CP_type::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(calling_presentation_selector_, 1);
        ITU_T_IMPLICIT_TAG(called_presentation_selector_, 2);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_list_, 4);
        ITU_T_IMPLICIT_TAG(default_context_name_, 6);
        ITU_T_IMPLICIT_TAG(presentation_requirements_, 8);
        ITU_T_IMPLICIT_TAG(user_session_requirements_, 9);
        ITU_T_EXPLICIT_TAG(protocol_options_, 11);
        ITU_T_EXPLICIT_TAG(initiators_nominated_context_, 12);
        ITU_T_EXPLICIT_TAG(extensions_, 14);
        ITU_T_BIND_CHOICE(user_data_);
    }

    const Protocol_version& CP_type::normal_mode_parameters_type::protocol_version() const {
        return *protocol_version_;
    }

    void CP_type::normal_mode_parameters_type::protocol_version(const Protocol_version& vl) {
        protocol_version_ = vl;
    }

    void CP_type::normal_mode_parameters_type::protocol_version(boost::shared_ptr< Protocol_version> vl) {
        protocol_version_ = vl;
    }

    boost::shared_ptr<Calling_presentation_selector> CP_type::normal_mode_parameters_type::calling_presentation_selector__new() {
        return calling_presentation_selector_ = boost::shared_ptr<Calling_presentation_selector>(new Calling_presentation_selector());
    }

    void CP_type::normal_mode_parameters_type::calling_presentation_selector(const Calling_presentation_selector& vl) {
        calling_presentation_selector_ = boost::shared_ptr<Calling_presentation_selector>(new Calling_presentation_selector(vl));
    }

    boost::shared_ptr<Called_presentation_selector> CP_type::normal_mode_parameters_type::called_presentation_selector__new() {
        return called_presentation_selector_ = boost::shared_ptr<Called_presentation_selector>(new Called_presentation_selector());
    }

    void CP_type::normal_mode_parameters_type::called_presentation_selector(const Called_presentation_selector& vl) {
        called_presentation_selector_ = boost::shared_ptr<Called_presentation_selector>(new Called_presentation_selector(vl));
    }

    boost::shared_ptr<Presentation_context_definition_list> CP_type::normal_mode_parameters_type::presentation_context_definition_list__new() {
        return presentation_context_definition_list_ = boost::shared_ptr<Presentation_context_definition_list>(new Presentation_context_definition_list());
    }

    void CP_type::normal_mode_parameters_type::presentation_context_definition_list(const Presentation_context_definition_list& vl) {
        presentation_context_definition_list_ = boost::shared_ptr<Presentation_context_definition_list>(new Presentation_context_definition_list(vl));
    }

    boost::shared_ptr<Default_context_name> CP_type::normal_mode_parameters_type::default_context_name__new() {
        return default_context_name_ = boost::shared_ptr<Default_context_name>(new Default_context_name());
    }

    void CP_type::normal_mode_parameters_type::default_context_name(const Default_context_name& vl) {
        default_context_name_ = boost::shared_ptr<Default_context_name>(new Default_context_name(vl));
    }

    boost::shared_ptr<Presentation_requirements> CP_type::normal_mode_parameters_type::presentation_requirements__new() {
        return presentation_requirements_ = boost::shared_ptr<Presentation_requirements>(new Presentation_requirements());
    }

    void CP_type::normal_mode_parameters_type::presentation_requirements(const Presentation_requirements& vl) {
        presentation_requirements_ = boost::shared_ptr<Presentation_requirements>(new Presentation_requirements(vl));
    }

    boost::shared_ptr<User_session_requirements> CP_type::normal_mode_parameters_type::user_session_requirements__new() {
        return user_session_requirements_ = boost::shared_ptr<User_session_requirements>(new User_session_requirements());
    }

    void CP_type::normal_mode_parameters_type::user_session_requirements(const User_session_requirements& vl) {
        user_session_requirements_ = boost::shared_ptr<User_session_requirements>(new User_session_requirements(vl));
    }

    const Protocol_options& CP_type::normal_mode_parameters_type::protocol_options() const {
        return *protocol_options_;
    }

    void CP_type::normal_mode_parameters_type::protocol_options(const Protocol_options& vl) {
        protocol_options_ = vl;
    }

    void CP_type::normal_mode_parameters_type::protocol_options(boost::shared_ptr< Protocol_options> vl) {
        protocol_options_ = vl;
    }

    boost::shared_ptr<Presentation_context_identifier> CP_type::normal_mode_parameters_type::initiators_nominated_context__new() {
        return initiators_nominated_context_ = boost::shared_ptr<Presentation_context_identifier>(new Presentation_context_identifier());
    }

    void CP_type::normal_mode_parameters_type::initiators_nominated_context(const Presentation_context_identifier& vl) {
        initiators_nominated_context_ = boost::shared_ptr<Presentation_context_identifier>(new Presentation_context_identifier(vl));
    }

    boost::shared_ptr<CP_type::normal_mode_parameters_type::extensions_type> CP_type::normal_mode_parameters_type::extensions__new() {
        return extensions_ = boost::shared_ptr<extensions_type>(new extensions_type());
    }

    void CP_type::normal_mode_parameters_type::extensions(const extensions_type& vl) {
        extensions_ = boost::shared_ptr<extensions_type>(new extensions_type(vl));
    }

    boost::shared_ptr<User_data> CP_type::normal_mode_parameters_type::user_data__new() {
        return user_data_ = boost::shared_ptr<User_data>(new User_data());
    }

    void CP_type::normal_mode_parameters_type::user_data(const User_data& vl) {
        user_data_ = boost::shared_ptr<User_data>(new User_data(vl));
    }

    template<> void CP_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mode_selector_, 0);
        ITU_T_IMPLICIT_TAG(x410_mode_parameters_, 1);
        ITU_T_IMPLICIT_TAG(normal_mode_parameters_, 2);
    }

    template<> void CP_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mode_selector_, 0);
        ITU_T_IMPLICIT_TAG(x410_mode_parameters_, 1);
        ITU_T_IMPLICIT_TAG(normal_mode_parameters_, 2);
    }

    Mode_selector& CP_type::mode_selector() {
        return *mode_selector_;
    }

    const Mode_selector& CP_type::mode_selector() const {
        return *mode_selector_;
    }

    void CP_type::mode_selector(const Mode_selector& vl) {
        mode_selector_ = vl;
    }

    void CP_type::mode_selector(boost::shared_ptr< Mode_selector> vl) {
        mode_selector_ = vl;
    }

    boost::shared_ptr<CP_type::x410_mode_parameters_type> CP_type::x410_mode_parameters__new() {
        return x410_mode_parameters_ = boost::shared_ptr<x410_mode_parameters_type>(new x410_mode_parameters_type());
    }

    void CP_type::x410_mode_parameters(const x410_mode_parameters_type& vl) {
        x410_mode_parameters_ = boost::shared_ptr<x410_mode_parameters_type>(new x410_mode_parameters_type(vl));
    }

    boost::shared_ptr<CP_type::normal_mode_parameters_type> CP_type::normal_mode_parameters__new() {
        return normal_mode_parameters_ = boost::shared_ptr<normal_mode_parameters_type>(new normal_mode_parameters_type());
    }

    void CP_type::normal_mode_parameters(const normal_mode_parameters_type& vl) {
        normal_mode_parameters_ = boost::shared_ptr<normal_mode_parameters_type>(new normal_mode_parameters_type(vl));
    }


    // set CPA-PPDU

    CPA_PPDU::CPA_PPDU() : mode_selector_() {
    };

    CPA_PPDU::CPA_PPDU(const Mode_selector& arg__mode_selector) :
    mode_selector_(arg__mode_selector) {
    };

    CPA_PPDU::CPA_PPDU(boost::shared_ptr< Mode_selector> arg__mode_selector,
            boost::shared_ptr< x410_mode_parameters_type> arg__x410_mode_parameters,
            boost::shared_ptr< normal_mode_parameters_type> arg__normal_mode_parameters) :
    mode_selector_(arg__mode_selector),
    x410_mode_parameters_(arg__x410_mode_parameters),
    normal_mode_parameters_(arg__normal_mode_parameters) {
    };

    CPA_PPDU::x410_mode_parameters_type::x410_mode_parameters_type() : connectionDataAC_() {
    };

    CPA_PPDU::x410_mode_parameters_type::x410_mode_parameters_type(const Reliable_Transfer_APDU::ConnectionData& arg__connectionDataAC) :
    connectionDataAC_(arg__connectionDataAC) {
    };

    CPA_PPDU::x410_mode_parameters_type::x410_mode_parameters_type(boost::shared_ptr< int> arg__checkpointSize,
            boost::shared_ptr< int> arg__windowSize,
            boost::shared_ptr< Reliable_Transfer_APDU::ConnectionData> arg__connectionDataAC) :
    checkpointSize_(arg__checkpointSize),
    windowSize_(arg__windowSize),
    connectionDataAC_(arg__connectionDataAC) {
    };

    const int CPA_PPDU::x410_mode_parameters_type::checkpointSize__default = 0;

    const int CPA_PPDU::x410_mode_parameters_type::windowSize__default = 3;

    template<> void CPA_PPDU::x410_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_CHOICE_TAG(connectionDataAC_, 2);
    }

    template<> void CPA_PPDU::x410_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(checkpointSize_, 0);
        ITU_T_IMPLICIT_TAG(windowSize_, 1);
        ITU_T_CHOICE_TAG(connectionDataAC_, 2);
    }

    const int& CPA_PPDU::x410_mode_parameters_type::checkpointSize() const {
        return *checkpointSize_;
    }

    void CPA_PPDU::x410_mode_parameters_type::checkpointSize(const int& vl) {
        checkpointSize_ = vl;
    }

    void CPA_PPDU::x410_mode_parameters_type::checkpointSize(boost::shared_ptr< int> vl) {
        checkpointSize_ = vl;
    }

    const int& CPA_PPDU::x410_mode_parameters_type::windowSize() const {
        return *windowSize_;
    }

    void CPA_PPDU::x410_mode_parameters_type::windowSize(const int& vl) {
        windowSize_ = vl;
    }

    void CPA_PPDU::x410_mode_parameters_type::windowSize(boost::shared_ptr< int> vl) {
        windowSize_ = vl;
    }

    Reliable_Transfer_APDU::ConnectionData& CPA_PPDU::x410_mode_parameters_type::connectionDataAC() {
        return *connectionDataAC_;
    }

    const Reliable_Transfer_APDU::ConnectionData& CPA_PPDU::x410_mode_parameters_type::connectionDataAC() const {
        return *connectionDataAC_;
    }

    void CPA_PPDU::x410_mode_parameters_type::connectionDataAC(const Reliable_Transfer_APDU::ConnectionData& vl) {
        connectionDataAC_ = vl;
    }

    void CPA_PPDU::x410_mode_parameters_type::connectionDataAC(boost::shared_ptr< Reliable_Transfer_APDU::ConnectionData> vl) {
        connectionDataAC_ = vl;
    }

    CPA_PPDU::normal_mode_parameters_type::normal_mode_parameters_type() {
    };

    CPA_PPDU::normal_mode_parameters_type::normal_mode_parameters_type(boost::shared_ptr< Protocol_version> arg__protocol_version,
            boost::shared_ptr< Responding_presentation_selector> arg__responding_presentation_selector,
            boost::shared_ptr< Presentation_context_definition_result_list> arg__presentation_context_definition_result_list,
            boost::shared_ptr< Presentation_requirements> arg__presentation_requirements,
            boost::shared_ptr< User_session_requirements> arg__user_session_requirements,
            boost::shared_ptr< Protocol_options> arg__protocol_options,
            boost::shared_ptr< Presentation_context_identifier> arg__responders_nominated_context,
            boost::shared_ptr< User_data> arg__user_data) :
    protocol_version_(arg__protocol_version),
    responding_presentation_selector_(arg__responding_presentation_selector),
    presentation_context_definition_result_list_(arg__presentation_context_definition_result_list),
    presentation_requirements_(arg__presentation_requirements),
    user_session_requirements_(arg__user_session_requirements),
    protocol_options_(arg__protocol_options),
    responders_nominated_context_(arg__responders_nominated_context),
    user_data_(arg__user_data) {
    };

    const Protocol_version CPA_PPDU::normal_mode_parameters_type::protocol_version__default = Protocol_version(Protocol_version_version_1);

    const Protocol_options CPA_PPDU::normal_mode_parameters_type::protocol_options__default = Protocol_options();

    template<> void CPA_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(responding_presentation_selector_, 3);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_result_list_, 5);
        ITU_T_IMPLICIT_TAG(presentation_requirements_, 8);
        ITU_T_IMPLICIT_TAG(user_session_requirements_, 9);
        ITU_T_EXPLICIT_TAG(protocol_options_, 11);
        ITU_T_EXPLICIT_TAG(responders_nominated_context_, 13);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CPA_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(responding_presentation_selector_, 3);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_result_list_, 5);
        ITU_T_IMPLICIT_TAG(presentation_requirements_, 8);
        ITU_T_IMPLICIT_TAG(user_session_requirements_, 9);
        ITU_T_EXPLICIT_TAG(protocol_options_, 11);
        ITU_T_EXPLICIT_TAG(responders_nominated_context_, 13);
        ITU_T_BIND_CHOICE(user_data_);
    }

    const Protocol_version& CPA_PPDU::normal_mode_parameters_type::protocol_version() const {
        return *protocol_version_;
    }

    void CPA_PPDU::normal_mode_parameters_type::protocol_version(const Protocol_version& vl) {
        protocol_version_ = vl;
    }

    void CPA_PPDU::normal_mode_parameters_type::protocol_version(boost::shared_ptr< Protocol_version> vl) {
        protocol_version_ = vl;
    }

    boost::shared_ptr<Responding_presentation_selector> CPA_PPDU::normal_mode_parameters_type::responding_presentation_selector__new() {
        return responding_presentation_selector_ = boost::shared_ptr<Responding_presentation_selector>(new Responding_presentation_selector());
    }

    void CPA_PPDU::normal_mode_parameters_type::responding_presentation_selector(const Responding_presentation_selector& vl) {
        responding_presentation_selector_ = boost::shared_ptr<Responding_presentation_selector>(new Responding_presentation_selector(vl));
    }

    boost::shared_ptr<Presentation_context_definition_result_list> CPA_PPDU::normal_mode_parameters_type::presentation_context_definition_result_list__new() {
        return presentation_context_definition_result_list_ = boost::shared_ptr<Presentation_context_definition_result_list>(new Presentation_context_definition_result_list());
    }

    void CPA_PPDU::normal_mode_parameters_type::presentation_context_definition_result_list(const Presentation_context_definition_result_list& vl) {
        presentation_context_definition_result_list_ = boost::shared_ptr<Presentation_context_definition_result_list>(new Presentation_context_definition_result_list(vl));
    }

    boost::shared_ptr<Presentation_requirements> CPA_PPDU::normal_mode_parameters_type::presentation_requirements__new() {
        return presentation_requirements_ = boost::shared_ptr<Presentation_requirements>(new Presentation_requirements());
    }

    void CPA_PPDU::normal_mode_parameters_type::presentation_requirements(const Presentation_requirements& vl) {
        presentation_requirements_ = boost::shared_ptr<Presentation_requirements>(new Presentation_requirements(vl));
    }

    boost::shared_ptr<User_session_requirements> CPA_PPDU::normal_mode_parameters_type::user_session_requirements__new() {
        return user_session_requirements_ = boost::shared_ptr<User_session_requirements>(new User_session_requirements());
    }

    void CPA_PPDU::normal_mode_parameters_type::user_session_requirements(const User_session_requirements& vl) {
        user_session_requirements_ = boost::shared_ptr<User_session_requirements>(new User_session_requirements(vl));
    }

    const Protocol_options& CPA_PPDU::normal_mode_parameters_type::protocol_options() const {
        return *protocol_options_;
    }

    void CPA_PPDU::normal_mode_parameters_type::protocol_options(const Protocol_options& vl) {
        protocol_options_ = vl;
    }

    void CPA_PPDU::normal_mode_parameters_type::protocol_options(boost::shared_ptr< Protocol_options> vl) {
        protocol_options_ = vl;
    }

    boost::shared_ptr<Presentation_context_identifier> CPA_PPDU::normal_mode_parameters_type::responders_nominated_context__new() {
        return responders_nominated_context_ = boost::shared_ptr<Presentation_context_identifier>(new Presentation_context_identifier());
    }

    void CPA_PPDU::normal_mode_parameters_type::responders_nominated_context(const Presentation_context_identifier& vl) {
        responders_nominated_context_ = boost::shared_ptr<Presentation_context_identifier>(new Presentation_context_identifier(vl));
    }

    boost::shared_ptr<User_data> CPA_PPDU::normal_mode_parameters_type::user_data__new() {
        return user_data_ = boost::shared_ptr<User_data>(new User_data());
    }

    void CPA_PPDU::normal_mode_parameters_type::user_data(const User_data& vl) {
        user_data_ = boost::shared_ptr<User_data>(new User_data(vl));
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mode_selector_, 0);
        ITU_T_IMPLICIT_TAG(x410_mode_parameters_, 1);
        ITU_T_IMPLICIT_TAG(normal_mode_parameters_, 2);
    }

    template<> void CPA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mode_selector_, 0);
        ITU_T_IMPLICIT_TAG(x410_mode_parameters_, 1);
        ITU_T_IMPLICIT_TAG(normal_mode_parameters_, 2);
    }

    Mode_selector& CPA_PPDU::mode_selector() {
        return *mode_selector_;
    }

    const Mode_selector& CPA_PPDU::mode_selector() const {
        return *mode_selector_;
    }

    void CPA_PPDU::mode_selector(const Mode_selector& vl) {
        mode_selector_ = vl;
    }

    void CPA_PPDU::mode_selector(boost::shared_ptr< Mode_selector> vl) {
        mode_selector_ = vl;
    }

    boost::shared_ptr<CPA_PPDU::x410_mode_parameters_type> CPA_PPDU::x410_mode_parameters__new() {
        return x410_mode_parameters_ = boost::shared_ptr<x410_mode_parameters_type>(new x410_mode_parameters_type());
    }

    void CPA_PPDU::x410_mode_parameters(const x410_mode_parameters_type& vl) {
        x410_mode_parameters_ = boost::shared_ptr<x410_mode_parameters_type>(new x410_mode_parameters_type(vl));
    }

    boost::shared_ptr<CPA_PPDU::normal_mode_parameters_type> CPA_PPDU::normal_mode_parameters__new() {
        return normal_mode_parameters_ = boost::shared_ptr<normal_mode_parameters_type>(new normal_mode_parameters_type());
    }

    void CPA_PPDU::normal_mode_parameters(const normal_mode_parameters_type& vl) {
        normal_mode_parameters_ = boost::shared_ptr<normal_mode_parameters_type>(new normal_mode_parameters_type(vl));
    }


    // choice CPR-PPDU

    CPR_PPDU::x400_mode_parameters_type::x400_mode_parameters_type() {
    };

    CPR_PPDU::x400_mode_parameters_type::x400_mode_parameters_type(boost::shared_ptr< Reliable_Transfer_APDU::RefuseReason> arg__refuseReason,
            boost::shared_ptr< any_type> arg__userDataRJ) :
    refuseReason_(arg__refuseReason),
    userDataRJ_(arg__userDataRJ) {
    };

    template<> void CPR_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(refuseReason_, 0);
        ITU_T_EXPLICIT_TAG(userDataRJ_, 1);
    }

    template<> void CPR_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(refuseReason_, 0);
        ITU_T_EXPLICIT_TAG(userDataRJ_, 1);
    }

    boost::shared_ptr<Reliable_Transfer_APDU::RefuseReason> CPR_PPDU::x400_mode_parameters_type::refuseReason__new() {
        return refuseReason_ = boost::shared_ptr<Reliable_Transfer_APDU::RefuseReason>(new Reliable_Transfer_APDU::RefuseReason());
    }

    void CPR_PPDU::x400_mode_parameters_type::refuseReason(const Reliable_Transfer_APDU::RefuseReason& vl) {
        refuseReason_ = boost::shared_ptr<Reliable_Transfer_APDU::RefuseReason>(new Reliable_Transfer_APDU::RefuseReason(vl));
    }

    boost::shared_ptr<any_type> CPR_PPDU::x400_mode_parameters_type::userDataRJ__new() {
        return userDataRJ_ = boost::shared_ptr<any_type>(new any_type());
    }

    void CPR_PPDU::x400_mode_parameters_type::userDataRJ(const any_type& vl) {
        userDataRJ_ = boost::shared_ptr<any_type>(new any_type(vl));
    }

    CPR_PPDU::normal_mode_parameters_type::normal_mode_parameters_type() {
    };

    CPR_PPDU::normal_mode_parameters_type::normal_mode_parameters_type(boost::shared_ptr< Protocol_version> arg__protocol_version,
            boost::shared_ptr< Responding_presentation_selector> arg__responding_presentation_selector,
            boost::shared_ptr< Presentation_context_definition_result_list> arg__presentation_context_definition_result_list,
            boost::shared_ptr< Default_context_result> arg__default_context_result,
            boost::shared_ptr< Provider_reason> arg__provider_reason,
            boost::shared_ptr< User_data> arg__user_data) :
    protocol_version_(arg__protocol_version),
    responding_presentation_selector_(arg__responding_presentation_selector),
    presentation_context_definition_result_list_(arg__presentation_context_definition_result_list),
    default_context_result_(arg__default_context_result),
    provider_reason_(arg__provider_reason),
    user_data_(arg__user_data) {
    };

    const Protocol_version CPR_PPDU::normal_mode_parameters_type::protocol_version__default = Protocol_version(Protocol_version_version_1);

    template<> void CPR_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(responding_presentation_selector_, 3);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_result_list_, 5);
        ITU_T_IMPLICIT_TAG(default_context_result_, 7);
        ITU_T_IMPLICIT_TAG(provider_reason_, 10);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void CPR_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(protocol_version_, 0);
        ITU_T_IMPLICIT_TAG(responding_presentation_selector_, 3);
        ITU_T_IMPLICIT_TAG(presentation_context_definition_result_list_, 5);
        ITU_T_IMPLICIT_TAG(default_context_result_, 7);
        ITU_T_IMPLICIT_TAG(provider_reason_, 10);
        ITU_T_BIND_CHOICE(user_data_);
    }

    const Protocol_version& CPR_PPDU::normal_mode_parameters_type::protocol_version() const {
        return *protocol_version_;
    }

    void CPR_PPDU::normal_mode_parameters_type::protocol_version(const Protocol_version& vl) {
        protocol_version_ = vl;
    }

    void CPR_PPDU::normal_mode_parameters_type::protocol_version(boost::shared_ptr< Protocol_version> vl) {
        protocol_version_ = vl;
    }

    boost::shared_ptr<Responding_presentation_selector> CPR_PPDU::normal_mode_parameters_type::responding_presentation_selector__new() {
        return responding_presentation_selector_ = boost::shared_ptr<Responding_presentation_selector>(new Responding_presentation_selector());
    }

    void CPR_PPDU::normal_mode_parameters_type::responding_presentation_selector(const Responding_presentation_selector& vl) {
        responding_presentation_selector_ = boost::shared_ptr<Responding_presentation_selector>(new Responding_presentation_selector(vl));
    }

    boost::shared_ptr<Presentation_context_definition_result_list> CPR_PPDU::normal_mode_parameters_type::presentation_context_definition_result_list__new() {
        return presentation_context_definition_result_list_ = boost::shared_ptr<Presentation_context_definition_result_list>(new Presentation_context_definition_result_list());
    }

    void CPR_PPDU::normal_mode_parameters_type::presentation_context_definition_result_list(const Presentation_context_definition_result_list& vl) {
        presentation_context_definition_result_list_ = boost::shared_ptr<Presentation_context_definition_result_list>(new Presentation_context_definition_result_list(vl));
    }

    boost::shared_ptr<Default_context_result> CPR_PPDU::normal_mode_parameters_type::default_context_result__new() {
        return default_context_result_ = boost::shared_ptr<Default_context_result>(new Default_context_result());
    }

    void CPR_PPDU::normal_mode_parameters_type::default_context_result(const Default_context_result& vl) {
        default_context_result_ = boost::shared_ptr<Default_context_result>(new Default_context_result(vl));
    }

    boost::shared_ptr<Provider_reason> CPR_PPDU::normal_mode_parameters_type::provider_reason__new() {
        return provider_reason_ = boost::shared_ptr<Provider_reason>(new Provider_reason());
    }

    void CPR_PPDU::normal_mode_parameters_type::provider_reason(const Provider_reason& vl) {
        provider_reason_ = boost::shared_ptr<Provider_reason>(new Provider_reason(vl));
    }

    boost::shared_ptr<User_data> CPR_PPDU::normal_mode_parameters_type::user_data__new() {
        return user_data_ = boost::shared_ptr<User_data>(new User_data());
    }

    void CPR_PPDU::normal_mode_parameters_type::user_data(const User_data& vl) {
        user_data_ = boost::shared_ptr<User_data>(new User_data(vl));
    }

    template<> void CPR_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case CPR_PPDU_x400_mode_parameters:
            {
                ITU_T_BIND_TAG(value<x400_mode_parameters_type > (false, CPR_PPDU_x400_mode_parameters));
                break;
            }
            case CPR_PPDU_normal_mode_parameters:
            {
                ITU_T_BIND_TAG(value<normal_mode_parameters_type > (false, CPR_PPDU_normal_mode_parameters));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void CPR_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_TAG(value<x400_mode_parameters_type > (true, CPR_PPDU_x400_mode_parameters))) return;
                else free();
                if (ITU_T_BIND_TAG(value<normal_mode_parameters_type > (true, CPR_PPDU_normal_mode_parameters))) return;
                else free();
            }
        }
    }


    // choice Abort-type

    template<> void Abort_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Abort_type_aru_ppdu:
            {
                ITU_T_BIND_CHOICE(value<ARU_PPDU > (false, Abort_type_aru_ppdu));
                break;
            }
            case Abort_type_arp_ppdu:
            {
                ITU_T_BIND_TAG(value<ARP_PPDU > (false, Abort_type_arp_ppdu));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Abort_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                if (ITU_T_BIND_CHOICE(value<ARU_PPDU > (true, Abort_type_aru_ppdu))) return;
                else free();
                if (ITU_T_BIND_TAG(value<ARP_PPDU > (true, Abort_type_arp_ppdu))) return;
                else free();
            }
        }
    }


    // choice ARU-PPDU

    ARU_PPDU::x400_mode_parameters_type::x400_mode_parameters_type() {
    };

    ARU_PPDU::x400_mode_parameters_type::x400_mode_parameters_type(boost::shared_ptr< Reliable_Transfer_APDU::AbortReason> arg__abortReason,
            boost::shared_ptr< bitstring_type> arg__reflectedParameter,
            boost::shared_ptr< any_type> arg__userdataAB) :
    abortReason_(arg__abortReason),
    reflectedParameter_(arg__reflectedParameter),
    userdataAB_(arg__userdataAB) {
    };

    template<> void ARU_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(abortReason_, 0);
        ITU_T_IMPLICIT_TAG(reflectedParameter_, 1);
        ITU_T_EXPLICIT_TAG(userdataAB_, 2);
    }

    template<> void ARU_PPDU::x400_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(abortReason_, 0);
        ITU_T_IMPLICIT_TAG(reflectedParameter_, 1);
        ITU_T_EXPLICIT_TAG(userdataAB_, 2);
    }

    boost::shared_ptr<Reliable_Transfer_APDU::AbortReason> ARU_PPDU::x400_mode_parameters_type::abortReason__new() {
        return abortReason_ = boost::shared_ptr<Reliable_Transfer_APDU::AbortReason>(new Reliable_Transfer_APDU::AbortReason());
    }

    void ARU_PPDU::x400_mode_parameters_type::abortReason(const Reliable_Transfer_APDU::AbortReason& vl) {
        abortReason_ = boost::shared_ptr<Reliable_Transfer_APDU::AbortReason>(new Reliable_Transfer_APDU::AbortReason(vl));
    }

    boost::shared_ptr<bitstring_type> ARU_PPDU::x400_mode_parameters_type::reflectedParameter__new() {
        return reflectedParameter_ = boost::shared_ptr<bitstring_type>(new bitstring_type());
    }

    void ARU_PPDU::x400_mode_parameters_type::reflectedParameter(const bitstring_type& vl) {
        reflectedParameter_ = boost::shared_ptr<bitstring_type>(new bitstring_type(vl));
    }

    boost::shared_ptr<any_type> ARU_PPDU::x400_mode_parameters_type::userdataAB__new() {
        return userdataAB_ = boost::shared_ptr<any_type>(new any_type());
    }

    void ARU_PPDU::x400_mode_parameters_type::userdataAB(const any_type& vl) {
        userdataAB_ = boost::shared_ptr<any_type>(new any_type(vl));
    }

    ARU_PPDU::normal_mode_parameters_type::normal_mode_parameters_type() {
    };

    ARU_PPDU::normal_mode_parameters_type::normal_mode_parameters_type(boost::shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
            boost::shared_ptr< User_data> arg__user_data) :
    presentation_context_identifier_list_(arg__presentation_context_identifier_list),
    user_data_(arg__user_data) {
    };

    template<> void ARU_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void ARU_PPDU::normal_mode_parameters_type::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    boost::shared_ptr<Presentation_context_identifier_list> ARU_PPDU::normal_mode_parameters_type::presentation_context_identifier_list__new() {
        return presentation_context_identifier_list_ = boost::shared_ptr<Presentation_context_identifier_list>(new Presentation_context_identifier_list());
    }

    void ARU_PPDU::normal_mode_parameters_type::presentation_context_identifier_list(const Presentation_context_identifier_list& vl) {
        presentation_context_identifier_list_ = boost::shared_ptr<Presentation_context_identifier_list>(new Presentation_context_identifier_list(vl));
    }

    boost::shared_ptr<User_data> ARU_PPDU::normal_mode_parameters_type::user_data__new() {
        return user_data_ = boost::shared_ptr<User_data>(new User_data());
    }

    void ARU_PPDU::normal_mode_parameters_type::user_data(const User_data& vl) {
        user_data_ = boost::shared_ptr<User_data>(new User_data(vl));
    }

    template<> void ARU_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case ARU_PPDU_x400_mode_parameters:
            {
                ITU_T_BIND_TAG(value<x400_mode_parameters_type > (false, ARU_PPDU_x400_mode_parameters));
                break;
            }
            case ARU_PPDU_normal_mode_parameters:
            {
                ITU_T_IMPLICIT_TAG(value<normal_mode_parameters_type > (false, ARU_PPDU_normal_mode_parameters), 0);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void ARU_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(value<normal_mode_parameters_type > (true, ARU_PPDU_normal_mode_parameters), 0)) return;
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
                if (ITU_T_BIND_TAG(value<x400_mode_parameters_type > (true, ARU_PPDU_x400_mode_parameters))) return;
                else free();
            }
        }
    }


    // sequence ARP-PPDU

    ARP_PPDU::ARP_PPDU() {
    };

    ARP_PPDU::ARP_PPDU(boost::shared_ptr< Abort_reason> arg__provider_reason,
            boost::shared_ptr< Event_identifier> arg__event_identifier) :
    provider_reason_(arg__provider_reason),
    event_identifier_(arg__event_identifier) {
    };

    template<> void ARP_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(provider_reason_, 0);
        ITU_T_IMPLICIT_TAG(event_identifier_, 1);
    }

    template<> void ARP_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(provider_reason_, 0);
        ITU_T_IMPLICIT_TAG(event_identifier_, 1);
    }

    boost::shared_ptr<Abort_reason> ARP_PPDU::provider_reason__new() {
        return provider_reason_ = boost::shared_ptr<Abort_reason>(new Abort_reason());
    }

    void ARP_PPDU::provider_reason(const Abort_reason& vl) {
        provider_reason_ = boost::shared_ptr<Abort_reason>(new Abort_reason(vl));
    }

    boost::shared_ptr<Event_identifier> ARP_PPDU::event_identifier__new() {
        return event_identifier_ = boost::shared_ptr<Event_identifier>(new Event_identifier());
    }

    void ARP_PPDU::event_identifier(const Event_identifier& vl) {
        event_identifier_ = boost::shared_ptr<Event_identifier>(new Event_identifier(vl));
    }


    // choice Typed-data-type

    template<> void Typed_data_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case Typed_data_type_acPPDU:
            {
                ITU_T_IMPLICIT_TAG(value<AC_PPDU > (false, Typed_data_type_acPPDU), 0);
                break;
            }
            case Typed_data_type_acaPPDU:
            {
                ITU_T_IMPLICIT_TAG(value<ACA_PPDU > (false, Typed_data_type_acaPPDU), 1);
                break;
            }
            case Typed_data_type_ttdPPDU:
            {
                ITU_T_BIND_CHOICE(value<User_data > (false, Typed_data_type_ttdPPDU));
                break;
            }
            default:
            {
            }
        }
    }

    template<> void Typed_data_type::serialize(boost::asn1::x690::input_coder& arch) {
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
                        if (ITU_T_IMPLICIT_TAG(value<AC_PPDU > (true, Typed_data_type_acPPDU), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_TAG(value<ACA_PPDU > (true, Typed_data_type_acaPPDU), 1)) return;
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
                if (ITU_T_BIND_CHOICE(value<User_data > (true, Typed_data_type_ttdPPDU))) return;
                else free();
            }
        }
    }


    // sequence AC-PPDU

    AC_PPDU::AC_PPDU() {
    };

    AC_PPDU::AC_PPDU(boost::shared_ptr< Presentation_context_addition_list> arg__presentation_context_addition_list,
            boost::shared_ptr< Presentation_context_deletion_list> arg__presentation_context_deletion_list,
            boost::shared_ptr< User_data> arg__user_data) :
    presentation_context_addition_list_(arg__presentation_context_addition_list),
    presentation_context_deletion_list_(arg__presentation_context_deletion_list),
    user_data_(arg__user_data) {
    };

    template<> void AC_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_addition_list_, 0);
        ITU_T_IMPLICIT_TAG(presentation_context_deletion_list_, 1);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void AC_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_addition_list_, 0);
        ITU_T_IMPLICIT_TAG(presentation_context_deletion_list_, 1);
        ITU_T_BIND_CHOICE(user_data_);
    }

    boost::shared_ptr<Presentation_context_addition_list> AC_PPDU::presentation_context_addition_list__new() {
        return presentation_context_addition_list_ = boost::shared_ptr<Presentation_context_addition_list>(new Presentation_context_addition_list());
    }

    void AC_PPDU::presentation_context_addition_list(const Presentation_context_addition_list& vl) {
        presentation_context_addition_list_ = boost::shared_ptr<Presentation_context_addition_list>(new Presentation_context_addition_list(vl));
    }

    boost::shared_ptr<Presentation_context_deletion_list> AC_PPDU::presentation_context_deletion_list__new() {
        return presentation_context_deletion_list_ = boost::shared_ptr<Presentation_context_deletion_list>(new Presentation_context_deletion_list());
    }

    void AC_PPDU::presentation_context_deletion_list(const Presentation_context_deletion_list& vl) {
        presentation_context_deletion_list_ = boost::shared_ptr<Presentation_context_deletion_list>(new Presentation_context_deletion_list(vl));
    }

    boost::shared_ptr<User_data> AC_PPDU::user_data__new() {
        return user_data_ = boost::shared_ptr<User_data>(new User_data());
    }

    void AC_PPDU::user_data(const User_data& vl) {
        user_data_ = boost::shared_ptr<User_data>(new User_data(vl));
    }


    // sequence ACA-PPDU

    ACA_PPDU::ACA_PPDU() {
    };

    ACA_PPDU::ACA_PPDU(boost::shared_ptr< Presentation_context_addition_result_list> arg__presentation_context_addition_result_list,
            boost::shared_ptr< Presentation_context_deletion_result_list> arg__presentation_context_deletion_result_list,
            boost::shared_ptr< User_data> arg__user_data) :
    presentation_context_addition_result_list_(arg__presentation_context_addition_result_list),
    presentation_context_deletion_result_list_(arg__presentation_context_deletion_result_list),
    user_data_(arg__user_data) {
    };

    template<> void ACA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_addition_result_list_, 0);
        ITU_T_IMPLICIT_TAG(presentation_context_deletion_result_list_, 1);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void ACA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_addition_result_list_, 0);
        ITU_T_IMPLICIT_TAG(presentation_context_deletion_result_list_, 1);
        ITU_T_BIND_CHOICE(user_data_);
    }

    boost::shared_ptr<Presentation_context_addition_result_list> ACA_PPDU::presentation_context_addition_result_list__new() {
        return presentation_context_addition_result_list_ = boost::shared_ptr<Presentation_context_addition_result_list>(new Presentation_context_addition_result_list());
    }

    void ACA_PPDU::presentation_context_addition_result_list(const Presentation_context_addition_result_list& vl) {
        presentation_context_addition_result_list_ = boost::shared_ptr<Presentation_context_addition_result_list>(new Presentation_context_addition_result_list(vl));
    }

    boost::shared_ptr<Presentation_context_deletion_result_list> ACA_PPDU::presentation_context_deletion_result_list__new() {
        return presentation_context_deletion_result_list_ = boost::shared_ptr<Presentation_context_deletion_result_list>(new Presentation_context_deletion_result_list());
    }

    void ACA_PPDU::presentation_context_deletion_result_list(const Presentation_context_deletion_result_list& vl) {
        presentation_context_deletion_result_list_ = boost::shared_ptr<Presentation_context_deletion_result_list>(new Presentation_context_deletion_result_list(vl));
    }

    boost::shared_ptr<User_data> ACA_PPDU::user_data__new() {
        return user_data_ = boost::shared_ptr<User_data>(new User_data());
    }

    void ACA_PPDU::user_data(const User_data& vl) {
        user_data_ = boost::shared_ptr<User_data>(new User_data(vl));
    }


    // sequence RS-PPDU

    RS_PPDU::RS_PPDU() {
    };

    RS_PPDU::RS_PPDU(boost::shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
            boost::shared_ptr< User_data> arg__user_data) :
    presentation_context_identifier_list_(arg__presentation_context_identifier_list),
    user_data_(arg__user_data) {
    };

    template<> void RS_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void RS_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    boost::shared_ptr<Presentation_context_identifier_list> RS_PPDU::presentation_context_identifier_list__new() {
        return presentation_context_identifier_list_ = boost::shared_ptr<Presentation_context_identifier_list>(new Presentation_context_identifier_list());
    }

    void RS_PPDU::presentation_context_identifier_list(const Presentation_context_identifier_list& vl) {
        presentation_context_identifier_list_ = boost::shared_ptr<Presentation_context_identifier_list>(new Presentation_context_identifier_list(vl));
    }

    boost::shared_ptr<User_data> RS_PPDU::user_data__new() {
        return user_data_ = boost::shared_ptr<User_data>(new User_data());
    }

    void RS_PPDU::user_data(const User_data& vl) {
        user_data_ = boost::shared_ptr<User_data>(new User_data(vl));
    }


    // sequence RSA-PPDU

    RSA_PPDU::RSA_PPDU() {
    };

    RSA_PPDU::RSA_PPDU(boost::shared_ptr< Presentation_context_identifier_list> arg__presentation_context_identifier_list,
            boost::shared_ptr< User_data> arg__user_data) :
    presentation_context_identifier_list_(arg__presentation_context_identifier_list),
    user_data_(arg__user_data) {
    };

    template<> void RSA_PPDU::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    template<> void RSA_PPDU::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(presentation_context_identifier_list_, 0);
        ITU_T_BIND_CHOICE(user_data_);
    }

    boost::shared_ptr<Presentation_context_identifier_list> RSA_PPDU::presentation_context_identifier_list__new() {
        return presentation_context_identifier_list_ = boost::shared_ptr<Presentation_context_identifier_list>(new Presentation_context_identifier_list());
    }

    void RSA_PPDU::presentation_context_identifier_list(const Presentation_context_identifier_list& vl) {
        presentation_context_identifier_list_ = boost::shared_ptr<Presentation_context_identifier_list>(new Presentation_context_identifier_list(vl));
    }

    boost::shared_ptr<User_data> RSA_PPDU::user_data__new() {
        return user_data_ = boost::shared_ptr<User_data>(new User_data());
    }

    void RSA_PPDU::user_data(const User_data& vl) {
        user_data_ = boost::shared_ptr<User_data>(new User_data(vl));
    }


    const Abort_reason Abort_reason_reason_not_specified = 0;
    const Abort_reason Abort_reason_unrecognized_ppdu = 1;
    const Abort_reason Abort_reason_unexpected_ppdu = 2;
    const Abort_reason Abort_reason_unexpected_session_service_primitive = 3;
    const Abort_reason Abort_reason_unrecognized_ppdu_parameter = 4;
    const Abort_reason Abort_reason_unexpected_ppdu_parameter = 5;
    const Abort_reason Abort_reason_invalid_ppdu_parameter_value = 6;

    Context_list_sequence_of::Context_list_sequence_of() : presentation_context_identifier_(), abstract_syntax_name_(), transfer_syntax_name_list_() {
    };

    Context_list_sequence_of::Context_list_sequence_of(const Presentation_context_identifier& arg__presentation_context_identifier,
            const Abstract_syntax_name& arg__abstract_syntax_name,
            const transfer_syntax_name_list_type& arg__transfer_syntax_name_list) :
    presentation_context_identifier_(arg__presentation_context_identifier),
    abstract_syntax_name_(arg__abstract_syntax_name),
    transfer_syntax_name_list_(arg__transfer_syntax_name_list) {
    };

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(presentation_context_identifier_);
        ITU_T_BIND_TAG(abstract_syntax_name_);
        ITU_T_BIND_TAG(transfer_syntax_name_list_);
    }

    template<> void Context_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(presentation_context_identifier_);
        ITU_T_BIND_TAG(abstract_syntax_name_);
        ITU_T_BIND_TAG(transfer_syntax_name_list_);
    }

    Presentation_context_identifier& Context_list_sequence_of::presentation_context_identifier() {
        return *presentation_context_identifier_;
    }

    const Presentation_context_identifier& Context_list_sequence_of::presentation_context_identifier() const {
        return *presentation_context_identifier_;
    }

    void Context_list_sequence_of::presentation_context_identifier(const Presentation_context_identifier& vl) {
        presentation_context_identifier_ = vl;
    }

    void Context_list_sequence_of::presentation_context_identifier(boost::shared_ptr< Presentation_context_identifier> vl) {
        presentation_context_identifier_ = vl;
    }

    Abstract_syntax_name& Context_list_sequence_of::abstract_syntax_name() {
        return *abstract_syntax_name_;
    }

    const Abstract_syntax_name& Context_list_sequence_of::abstract_syntax_name() const {
        return *abstract_syntax_name_;
    }

    void Context_list_sequence_of::abstract_syntax_name(const Abstract_syntax_name& vl) {
        abstract_syntax_name_ = vl;
    }

    void Context_list_sequence_of::abstract_syntax_name(boost::shared_ptr< Abstract_syntax_name> vl) {
        abstract_syntax_name_ = vl;
    }

    Context_list_sequence_of::transfer_syntax_name_list_type& Context_list_sequence_of::transfer_syntax_name_list() {
        return *transfer_syntax_name_list_;
    }

    const Context_list_sequence_of::transfer_syntax_name_list_type& Context_list_sequence_of::transfer_syntax_name_list() const {
        return *transfer_syntax_name_list_;
    }

    void Context_list_sequence_of::transfer_syntax_name_list(const transfer_syntax_name_list_type& vl) {
        transfer_syntax_name_list_ = vl;
    }

    void Context_list_sequence_of::transfer_syntax_name_list(boost::shared_ptr< transfer_syntax_name_list_type> vl) {
        transfer_syntax_name_list_ = vl;
    }


    // sequence Default-context-name

    Default_context_name::Default_context_name() : abstract_syntax_name_(), transfer_syntax_name_() {
    };

    Default_context_name::Default_context_name(const Abstract_syntax_name& arg__abstract_syntax_name,
            const Transfer_syntax_name& arg__transfer_syntax_name) :
    abstract_syntax_name_(arg__abstract_syntax_name),
    transfer_syntax_name_(arg__transfer_syntax_name) {
    };

    template<> void Default_context_name::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(abstract_syntax_name_, 0);
        ITU_T_IMPLICIT_TAG(transfer_syntax_name_, 1);
    }

    template<> void Default_context_name::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(abstract_syntax_name_, 0);
        ITU_T_IMPLICIT_TAG(transfer_syntax_name_, 1);
    }

    Abstract_syntax_name& Default_context_name::abstract_syntax_name() {
        return *abstract_syntax_name_;
    }

    const Abstract_syntax_name& Default_context_name::abstract_syntax_name() const {
        return *abstract_syntax_name_;
    }

    void Default_context_name::abstract_syntax_name(const Abstract_syntax_name& vl) {
        abstract_syntax_name_ = vl;
    }

    void Default_context_name::abstract_syntax_name(boost::shared_ptr< Abstract_syntax_name> vl) {
        abstract_syntax_name_ = vl;
    }

    Transfer_syntax_name& Default_context_name::transfer_syntax_name() {
        return *transfer_syntax_name_;
    }

    const Transfer_syntax_name& Default_context_name::transfer_syntax_name() const {
        return *transfer_syntax_name_;
    }

    void Default_context_name::transfer_syntax_name(const Transfer_syntax_name& vl) {
        transfer_syntax_name_ = vl;
    }

    void Default_context_name::transfer_syntax_name(boost::shared_ptr< Transfer_syntax_name> vl) {
        transfer_syntax_name_ = vl;
    }


    const Event_identifier Event_identifier_cp_PPDU = 0;
    const Event_identifier Event_identifier_cpa_PPDU = 1;
    const Event_identifier Event_identifier_cpr_PPDU = 2;
    const Event_identifier Event_identifier_aru_PPDU = 3;
    const Event_identifier Event_identifier_arp_PPDU = 4;
    const Event_identifier Event_identifier_ac_PPDU = 5;
    const Event_identifier Event_identifier_aca_PPDU = 6;
    const Event_identifier Event_identifier_td_PPDU = 7;
    const Event_identifier Event_identifier_ttd_PPDU = 8;
    const Event_identifier Event_identifier_te_PPDU = 9;
    const Event_identifier Event_identifier_tc_PPDU = 10;
    const Event_identifier Event_identifier_tcc_PPDU = 11;
    const Event_identifier Event_identifier_rs_PPDU = 12;
    const Event_identifier Event_identifier_rsa_PPDU = 13;
    const Event_identifier Event_identifier_s_release_indication = 14;
    const Event_identifier Event_identifier_s_release_confirm = 15;
    const Event_identifier Event_identifier_s_token_give_indication = 16;
    const Event_identifier Event_identifier_s_token_please_indication = 17;
    const Event_identifier Event_identifier_s_control_give_indication = 18;
    const Event_identifier Event_identifier_s_sync_minor_indication = 19;
    const Event_identifier Event_identifier_s_sync_minor_confirm = 20;
    const Event_identifier Event_identifier_s_sync_major_indication = 21;
    const Event_identifier Event_identifier_s_sync_major_confirm = 22;
    const Event_identifier Event_identifier_s_p_exception_report_indication = 23;
    const Event_identifier Event_identifier_s_u_exception_report_indication = 24;
    const Event_identifier Event_identifier_s_activity_start_indication = 25;
    const Event_identifier Event_identifier_s_activity_resume_indication = 26;
    const Event_identifier Event_identifier_s_activity_interrupt_indication = 27;
    const Event_identifier Event_identifier_s_activity_interrupt_confirm = 28;
    const Event_identifier Event_identifier_s_activity_discard_indication = 29;
    const Event_identifier Event_identifier_s_activity_discard_confirm = 30;
    const Event_identifier Event_identifier_s_activity_end_indication = 31;
    const Event_identifier Event_identifier_s_activity_end_confirm = 32;

    // set Mode-selector
    const int Mode_selector::mode_value_x410_1984_mode = 0;
    const int Mode_selector::mode_value_normal_mode = 1;

    Mode_selector::Mode_selector() : mode_value_() {
    };

    Mode_selector::Mode_selector(const int& arg__mode_value) :
    mode_value_(arg__mode_value) {
    };

    template<> void Mode_selector::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(mode_value_, 0);
    }

    template<> void Mode_selector::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(mode_value_, 0);
    }

    int& Mode_selector::mode_value() {
        return *mode_value_;
    }

    const int& Mode_selector::mode_value() const {
        return *mode_value_;
    }

    void Mode_selector::mode_value(const int& vl) {
        mode_value_ = vl;
    }

    void Mode_selector::mode_value(boost::shared_ptr< int> vl) {
        mode_value_ = vl;
    }

    Presentation_context_identifier_list_sequence_of::Presentation_context_identifier_list_sequence_of() : presentation_context_identifier_(), transfer_syntax_name_() {
    };

    Presentation_context_identifier_list_sequence_of::Presentation_context_identifier_list_sequence_of(const Presentation_context_identifier& arg__presentation_context_identifier,
            const Transfer_syntax_name& arg__transfer_syntax_name) :
    presentation_context_identifier_(arg__presentation_context_identifier),
    transfer_syntax_name_(arg__transfer_syntax_name) {
    };

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_BIND_TAG(presentation_context_identifier_);
        ITU_T_BIND_TAG(transfer_syntax_name_);
    }

    template<> void Presentation_context_identifier_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(presentation_context_identifier_);
        ITU_T_BIND_TAG(transfer_syntax_name_);
    }

    Presentation_context_identifier& Presentation_context_identifier_list_sequence_of::presentation_context_identifier() {
        return *presentation_context_identifier_;
    }

    const Presentation_context_identifier& Presentation_context_identifier_list_sequence_of::presentation_context_identifier() const {
        return *presentation_context_identifier_;
    }

    void Presentation_context_identifier_list_sequence_of::presentation_context_identifier(const Presentation_context_identifier& vl) {
        presentation_context_identifier_ = vl;
    }

    void Presentation_context_identifier_list_sequence_of::presentation_context_identifier(boost::shared_ptr< Presentation_context_identifier> vl) {
        presentation_context_identifier_ = vl;
    }

    Transfer_syntax_name& Presentation_context_identifier_list_sequence_of::transfer_syntax_name() {
        return *transfer_syntax_name_;
    }

    const Transfer_syntax_name& Presentation_context_identifier_list_sequence_of::transfer_syntax_name() const {
        return *transfer_syntax_name_;
    }

    void Presentation_context_identifier_list_sequence_of::transfer_syntax_name(const Transfer_syntax_name& vl) {
        transfer_syntax_name_ = vl;
    }

    void Presentation_context_identifier_list_sequence_of::transfer_syntax_name(boost::shared_ptr< Transfer_syntax_name> vl) {
        transfer_syntax_name_ = vl;
    }


    const Presentation_requirements Presentation_requirements_context_management = bitstring_type(true, 0);
    const Presentation_requirements Presentation_requirements_restoration = bitstring_type(true, 1);

    const Protocol_options Protocol_options_nominated_context = bitstring_type(true, 0);
    const Protocol_options Protocol_options_short_encoding = bitstring_type(true, 1);
    const Protocol_options Protocol_options_packed_encoding_rules = bitstring_type(true, 2);

    const Protocol_version Protocol_version_version_1 = bitstring_type(true, 0);

    const Provider_reason Provider_reason_reason_not_specified = 0;
    const Provider_reason Provider_reason_temporary_congestion = 1;
    const Provider_reason Provider_reason_local_limit_exceeded = 2;
    const Provider_reason Provider_reason_called_presentation_address_unknown = 3;
    const Provider_reason Provider_reason_protocol_version_not_supported = 4;
    const Provider_reason Provider_reason_default_context_not_supported = 5;
    const Provider_reason Provider_reason_user_data_not_readable = 6;
    const Provider_reason Provider_reason_no_PSAP_available = 7;

    const Result Result_acceptance = 0;
    const Result Result_user_rejection = 1;
    const Result Result_provider_rejection = 2;


    const int Result_list_sequence_of::provider_reason_reason_not_specified = 0;
    const int Result_list_sequence_of::provider_reason_abstract_syntax_not_supported = 1;
    const int Result_list_sequence_of::provider_reason_proposed_transfer_syntaxes_not_supported = 2;
    const int Result_list_sequence_of::provider_reason_local_limit_on_DCS_exceeded = 3;

    Result_list_sequence_of::Result_list_sequence_of() : result_() {
    };

    Result_list_sequence_of::Result_list_sequence_of(const Result& arg__result) :
    result_(arg__result) {
    };

    Result_list_sequence_of::Result_list_sequence_of(boost::shared_ptr< Result> arg__result,
            boost::shared_ptr< Transfer_syntax_name> arg__transfer_syntax_name,
            boost::shared_ptr< int> arg__provider_reason) :
    result_(arg__result),
    transfer_syntax_name_(arg__transfer_syntax_name),
    provider_reason_(arg__provider_reason) {
    };

    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::output_coder& arch) {
        ITU_T_IMPLICIT_TAG(result_, 0);
        ITU_T_IMPLICIT_TAG(transfer_syntax_name_, 1);
        ITU_T_IMPLICIT_TAG(provider_reason_, 2);
    }

    template<> void Result_list_sequence_of::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_IMPLICIT_TAG(result_, 0);
        ITU_T_IMPLICIT_TAG(transfer_syntax_name_, 1);
        ITU_T_IMPLICIT_TAG(provider_reason_, 2);
    }

    Result& Result_list_sequence_of::result() {
        return *result_;
    }

    const Result& Result_list_sequence_of::result() const {
        return *result_;
    }

    void Result_list_sequence_of::result(const Result& vl) {
        result_ = vl;
    }

    void Result_list_sequence_of::result(boost::shared_ptr< Result> vl) {
        result_ = vl;
    }

    boost::shared_ptr<Transfer_syntax_name> Result_list_sequence_of::transfer_syntax_name__new() {
        return transfer_syntax_name_ = boost::shared_ptr<Transfer_syntax_name>(new Transfer_syntax_name());
    }

    void Result_list_sequence_of::transfer_syntax_name(const Transfer_syntax_name& vl) {
        transfer_syntax_name_ = boost::shared_ptr<Transfer_syntax_name>(new Transfer_syntax_name(vl));
    }

    boost::shared_ptr<int> Result_list_sequence_of::provider_reason__new() {
        return provider_reason_ = boost::shared_ptr<int>(new int());
    }

    void Result_list_sequence_of::provider_reason(const int& vl) {
        provider_reason_ = boost::shared_ptr<int>(new int(vl));
    }


    // choice User-data

    void User_data::simply_encoded_data(const Simply_encoded_data& vl) {
        set<Simply_encoded_data>(new Simply_encoded_data(vl), User_data_simply_encoded_data);
    }

    template<> void User_data::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case User_data_simply_encoded_data:
            {
                ITU_T_IMPLICIT_APPLICATION_TAG(value<Simply_encoded_data > (false, User_data_simply_encoded_data), 0);
                break;
            }
            case User_data_fully_encoded_data:
            {
                ITU_T_IMPLICIT_APPLICATION_TAG(value<Fully_encoded_data > (false, User_data_fully_encoded_data), 1);
                break;
            }
            default:
            {
            }
        }
    }

    template<> void User_data::serialize(boost::asn1::x690::input_coder& arch) {
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
                    case 0:
                    {
                        if (ITU_T_IMPLICIT_APPLICATION_TAG(value<Simply_encoded_data > (true, User_data_simply_encoded_data), 0)) return;
                        else free();
                        break;
                    }
                    case 1:
                    {
                        if (ITU_T_IMPLICIT_APPLICATION_TAG(value<Fully_encoded_data > (true, User_data_fully_encoded_data), 1)) return;
                        else free();
                        break;
                    }
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

    void PDV_list::presentation_data_values_type::single_ASN1_type(const any_type& vl) {
        set<any_type>(new any_type(vl), presentation_data_values_type_single_ASN1_type);
    }

    void PDV_list::presentation_data_values_type::octet_aligned(const octetstring_type& vl) {
        set<octetstring_type>(new octetstring_type(vl), presentation_data_values_type_octet_aligned);
    }

    void PDV_list::presentation_data_values_type::arbitrary(const bitstring_type& vl) {
        set<bitstring_type>(new bitstring_type(vl), presentation_data_values_type_arbitrary);
    }

    template<> void PDV_list::presentation_data_values_type::serialize(boost::asn1::x690::output_coder& arch) {
        switch (type()) {
            case presentation_data_values_type_single_ASN1_type:
            {
                ITU_T_EXPLICIT_TAG(value<any_type > (false, presentation_data_values_type_single_ASN1_type), 0);
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
                        if (ITU_T_EXPLICIT_TAG(value<any_type > (true, presentation_data_values_type_single_ASN1_type), 0)) return;
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
        ITU_T_BIND_CHOICE(presentation_data_values_);
    }

    template<> void PDV_list::serialize(boost::asn1::x690::input_coder& arch) {
        ITU_T_BIND_TAG(transfer_syntax_name_);
        ITU_T_BIND_TAG(presentation_context_identifier_);
        ITU_T_BIND_CHOICE(presentation_data_values_);
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


    const User_session_requirements User_session_requirements_half_duplex = bitstring_type(true, 0);
    const User_session_requirements User_session_requirements_duplex = bitstring_type(true, 1);
    const User_session_requirements User_session_requirements_expedited_data = bitstring_type(true, 2);
    const User_session_requirements User_session_requirements_minor_synchronize = bitstring_type(true, 3);
    const User_session_requirements User_session_requirements_major_synchronize = bitstring_type(true, 4);
    const User_session_requirements User_session_requirements_resynchronize = bitstring_type(true, 5);
    const User_session_requirements User_session_requirements_activity_management = bitstring_type(true, 6);
    const User_session_requirements User_session_requirements_negotiated_release = bitstring_type(true, 7);
    const User_session_requirements User_session_requirements_capability_data = bitstring_type(true, 8);
    const User_session_requirements User_session_requirements_exceptions = bitstring_type(true, 9);
    const User_session_requirements User_session_requirements_typed_data = bitstring_type(true, 10);
    const User_session_requirements User_session_requirements_symmetric_synchronize = bitstring_type(true, 11);
    const User_session_requirements User_session_requirements_data_separation = bitstring_type(true, 12);

}
