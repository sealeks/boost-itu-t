//  Copyright 2013 Alexeev Sergey sealeks@mail.ru

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#ifndef         _ITU_X225_SESS_IMPLEMENTATIUON_H_
#define _ITU_X225_SESS_IMPLEMENTATIUON_H_

#include <boost/itu/rfc1006/rfc1006.hpp>

namespace boost {
    namespace itu {
        namespace x225impl {

            //#define SEGMENTATION_TEST   

#if  defined(SEGMENTATION_TEST) && !(defined(DEBUG) || defined(_DEBUG_))
#error "SEGMENTATION_TEST  = DEBUG MACROS MUST DEFINED"
#endif                

#ifdef  SEGMENTATION_TEST           
#define SEGMENTATION_TEST_TO 128
#define SEGMENTATION_TEST_FROM 128
#endif



            // ref X225 = ITU-T Rec. X.225(1995 E)           

            using boost::asio::basic_socket;
            using boost::asio::basic_socket_acceptor;


            typedef uint8_t spdu_type;
            typedef uint16_t valuelenth_type;
            typedef uint8_t varid_type;

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   x225 utill   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     


            // SPDU identifier  *ref X225 5.6  Table 3 Р В Р’В Р В РІР‚В Р В Р’В Р Р†Р вЂљРЎв„ўР В Р вЂ Р В РІР‚С™Р РЋРЎв„ў Functional units (only kernel and half-duplex implemented here)
            // Kernel FU
            const spdu_type CN_SPDU_ID = 13; //CONNECT SPDU *ref X225 8.3.1.1
            const spdu_type OA_SPDU_ID = 16; //OVERFLOW ACCEPT *ref X225 8.3.2.1
            const spdu_type CDO_SPDU_ID = 15; //CONNECT DATA OVERFLOW *ref X225 8.3.3.1
            const spdu_type AC_SPDU_ID = 14; //ACCEPT*ref X225 8.3.4.1
            const spdu_type RF_SPDU_ID = 12; //REFUSE *ref X225 8.3.5.1
            const spdu_type FN_SPDU_ID = 9; //FINISH *ref X225 8.3.6.1
            const spdu_type DN_SPDU_ID = 10; //DISCONNECT *ref X225 8.3.7.1
            const spdu_type NF_SPDU_ID = 8; //NOT FINISHED *ref X225 8.3.8.1
            const spdu_type AB_SPDU_ID = 25; //ABORT *ref X225 8.3.9.1
            const spdu_type AA_SPDU_ID = 26; //ABORT ACCEPT *ref X225 8.3.10.1
            const spdu_type DT_SPDU_ID = 1; //DATA TRANSFER *ref X225 8.3.11.1
            const spdu_type PR_SPDU_ID = 7; //PREPARE *ref X225 8.3.26.1

            //  Negotiated realease
            // GIVE TOKENS , PLEASE TOKENS             

            //Half-duplex FU
            const spdu_type GT_SPDU_ID = 1; // GIVE TOKENS  *ref X225 8.3.16.1
            const spdu_type PT_SPDU_ID = 2; //PLEASE TOKENS  *ref X225 8.3.17.1             

            //Duplex FU    
            //

            //Expedited data FU
            const spdu_type EX_SPDU_ID = 5; //EXPEDITED *ref X225 8.3.12.1  

            //Typed data FU
            const spdu_type TD_SPDU_ID = 33; //TYPED DATA *ref X225 8.3.13.1  

            //Capability data exchange FU
            const spdu_type CD_SPDU_ID = 61; //CAPABILITY DATA *ref X225 8.3.14.1  
            const spdu_type CDA_SPDU_ID = 62; //CAPABILITY DATA ACK *ref X225 8.3.15.1  

            // Minor synchronize FU
            const spdu_type MIP_SPDU_ID = 49; //MINOR SYNC POINT  *ref X225 8.3.20.1
            const spdu_type MIA_SPDU_ID = 50; //MINOR SYNC ACK *ref X225 8.3.21.1
            // GIVE TOKENS , PLEASE TOKENS

            // Symmetric synchronize FU                
            // MINOR SYNC POINT , MINOR SYNC ACK 

            //Major synchronize FU
            const spdu_type MAP_SPDU_ID = 41; //MAJOR SYNC POINT *ref X225 8.3.22.1 
            const spdu_type MAA_SPDU_ID = 42; //MAJOR SYNC ACK  *ref X225 8.3.23.1
            // PREPARE ,GIVE TOKENS, PLEASE TOKENS   

            // Resynchronize FU     
            const spdu_type RS_SPDU_ID = 53; //RESYNCHRONIZE MINOR  *ref X225 8.3.24.1    
            const spdu_type RA_SPDU_ID = 34; //RESYNCHRONIZE ACK   *ref X225 8.3.25.1
            // PREPARE 

            // Exceptions FU                 
            const spdu_type ER_SPDU_ID = 0; //EXCEPTION REPORT   *ref X225 8.3.27.1
            const spdu_type ED_SPDU_ID = 48; //EXCEPTION DATA  *ref X225 8.3.28.1

            // Activity management FU
            const spdu_type AS_SPDU_ID = 45; //ACTIVITY START   *ref X225 8.3.29.1
            const spdu_type AR_SPDU_ID = 29; //ACTIVITY RESUME  *ref X225 8.3.30.1       
            const spdu_type AI_SPDU_ID = 25; //ACTIVITY INTERRUPT  *ref X225 8.3.31.1               
            const spdu_type AIA_SPDU_ID = 26; //ACTIVITY INTERRUPT ACK  *ref X225 8.3.32.1 
            const spdu_type AD_SPDU_ID = 57; //ACTIVITY DISCARD   *ref X225 8.3.33.1
            const spdu_type ADA_SPDU_ID = 58; //ACTIVITY DISCARD ACK   *ref X225 8.3.34.1
            const spdu_type AE_SPDU_ID = 41; //ACTIVITY END   *ref X225 8.3.35.1
            const spdu_type AEA_SPDU_ID = 42; //ACTIVITY END ACK   *ref X225 8.3.36.1            
            const spdu_type GTC_SPDU_ID = 21; //GIVE TOKENS CONFIRM *ref X225 8.3.18.1
            const spdu_type GTA_SPDU_ID = 22; //GIVE TOKENS ACK *ref X225 8.3.19.1
            //GIVE TOKENS, PLEASE TOKENS, PREPARE   


            // PGI Connection Identifier *ref X225 Tab 11, 14, 15
            const varid_type PGI_CONN_ID = 1;
            // PGI Connect/Accept Item *ref X225 Tab 11, 14           
            const varid_type PGI_CONN_ACC = 5;
            // PGI Linking Information *ref X225 Tab 38
            const varid_type PGI_LINK_INF = 33;
            // PGI  User Data *ref X225 Tab 11 .. 46          
            const varid_type PGI_USERDATA = 193; // pi here
            // PGI  Extended User Data *ref X225 Tab 11           
            const varid_type PGI_EXUSERDATA = 194; // pi here  

            //  User data limitation  *ref X225 8.3.1.19
            const std::size_t SIMPLE_USERDATA_LIMIT = 512;
            const std::size_t EXTEDED_USERDATA_LIMIT = 10240;
            const std::size_t MINAVAIL_MAX_TPDU = 64;
            const std::size_t SERVICE_SPDU_CONSTRAINTS = 65539 - MINAVAIL_MAX_TPDU; //( reserved);



            // PI Session User Requirements *ref X225 Tab 11, 14, 15
            const varid_type PI_SES_USERREQ = 20;

            //  Session User Requirements mask *ref X225 8.3.1.16 , 7.1.1 c), 7.4.1 d), 7.5.1 c)
            const int16_t FU_HALFDUPLEX = 0x1; //half-duplex FU            
            const int16_t FU_DUPLEX = 0x2; // duplex FU
            const int16_t FU_EXPDATA = 0x4; //expedited data FU            
            const int16_t FU_MINORSYNC = 0x8; // minor synchronize FU
            const int16_t FU_MAJORORSYNC = 0x10; //major synchronize FU         
            const int16_t FU_RESYNC = 0x20; // resynchronize FU;
            const int16_t FU_ACTIVEMG = 0x40; //activity management FU            
            const int16_t FU_NEGOTREL = 0x80; // negotiated release FU               
            const int16_t FU_CAPABDATA = 0x100; //capability data exchange FU
            const int16_t FU_EXCEPTION = 0x200; //exceptions FU 
            const int16_t FU_TYPEDDATA = 0x400; //typed data FU 
            const int16_t FU_SYMSYNC = 0x800; //symmetric synchronize FU  
            const int16_t FU_DATASEP = 0x1000; //data separation FU     

            const int16_t FU_WORK = FU_DUPLEX; // this implementation
            const int16_t FU_DEFAULT = FU_HALFDUPLEX | FU_MINORSYNC | FU_ACTIVEMG | FU_CAPABDATA | FU_EXCEPTION; //default *ref X225 8.3.1.16       


            // PI Version Number *ref X225 Tab 11, 12 , 14, 15
            const varid_type PI_VERSION = 22;

            // Version Number *ref X225 8.3.1.9 
            const octet_type VERSION1 = 1;
            const octet_type VERSION2 = 2;

            const octet_type WORK_PROT_VERSION = 3; // both version implemented here


            // PI Protocol Options Selector *ref X225 Tab 11 , 14 and 8.3.1.7            
            const varid_type PI_PROTOCOL_OPTION = 19;

            const octet_type NOEXTENDED_SPDU = 0;
            const octet_type EXTENDED_SPDU = 1;


            // PI Calling Session Selector *ref X225 Tab 11,  14  and 8.3.1.17
            const varid_type PI_CALLING = 51;


            // PI Called Session Selector *ref X225 Tab 11 and 8.3.1.18
            const varid_type PI_CALLED = 52;


            // PI TSDU Maximum Size *ref X225 Tab 11 , 14 and 8.3.1.8
            const varid_type PI_TSDUMAX = 21;


            // PI Data Overflow *ref X225 Tab 11 and 8.3.1.19
            const varid_type PI_DATAOVERFLOW = 60;


            // PI Data Overflow *ref X225 Tab 11 and 8.3.1.19
            const octet_type MORE_DATA = 1;


            // PI Enclosure Item *ref X225 Tab 13 .. 46 and 8.3.3.3            
            const varid_type PI_ENCLOSURE = 25;
            const octet_type ENCLOSURE_MIDLE = 0;
            const octet_type ENCLOSURE_BEGIN = 1;
            const octet_type ENCLOSURE_END = 2;
            const octet_type ENCLOSURE_SINGLE = 3;


            // PI Transport Disconnect *ref X225 Tab 15, 16, 19  and 8.3.5.6            
            const varid_type PI_TRANSPORT_DC = 17;

            // Transport Disconnect *ref X225 8.3.5.6             
            const octet_type KEEP_TRANSPORT = 0;
            const octet_type RELEASE_TRANSPORT = 1;


            // Refuse Reason Code *ref X225 Tab 15 and  8.3.5.10   
            const varid_type PI_REASON = 50;

            // see Disconnection  REASON CODE  iso.h




            const octet_type SEND_HEADERarr[] = {'\x1', '\x0', '\x1', '\x0'};
            const octet_sequnce SEND_HEADER = octet_sequnce(SEND_HEADERarr, SEND_HEADERarr + 4);

            const octet_type SEND_HEADER_F_arr[] = {'\x1', '\x0', '\x1', '\x3', PI_ENCLOSURE, '\x1', ENCLOSURE_BEGIN};
            const octet_sequnce SEND_HEADER_F = octet_sequnce(SEND_HEADER_F_arr, SEND_HEADER_F_arr + 7);

            const octet_type SEND_HEADER_M_arr[] = {'\x1', '\x0', '\x1', '\x3', PI_ENCLOSURE, '\x1', ENCLOSURE_MIDLE};
            const octet_sequnce SEND_HEADER_M = octet_sequnce(SEND_HEADER_M_arr, SEND_HEADER_M_arr + 7);

            const octet_type SEND_HEADER_E_arr[] = {'\x1', '\x0', '\x1', '\x3', PI_ENCLOSURE, '\x1', ENCLOSURE_END};
            const octet_sequnce SEND_HEADER_E = octet_sequnce(SEND_HEADER_E_arr, SEND_HEADER_E_arr + 7);



            const octet_type ECHO_NEGOTIATEarr[] = {'e', 'c', 'h', 'o', ':', ' '};
            const octet_sequnce ECHO_NEGOTIATE = octet_sequnce(ECHO_NEGOTIATEarr, ECHO_NEGOTIATEarr + 6);

            enum release_type {
                SESSION_FN_RELEASE = FN_SPDU_ID,
                SESSION_AB_RELEASE = AB_SPDU_ID
            };

            inline static spdu_type release_type_to_spdu(release_type vl) {
                return static_cast<spdu_type> (vl);
            }

            const std::size_t triple_npos = static_cast<std::size_t> (0xFFFF + 1);

            inline static octet_sequnce to_triple_size(std::size_t val) {
                if (val < 0xFF)
                    return inttype_to_raw(static_cast<uint8_t> (val));
                octet_sequnce rslt(1, '\xFF');
                raw_back_insert(rslt, inttype_to_raw(endiancnv_copy(static_cast<uint16_t> (val))));
                return rslt;
            }

            inline static bool valid_triple_size(const octet_sequnce& val) {
                return !((val.empty()) || (val[0] == '\xFF' && val.size() < 3));
            }

            // return triple_npos if no success
            std::size_t from_triple_size(const octet_sequnce& val, std::size_t& it);


            typedef std::pair<varid_type, octet_sequnce> pi_type;
            typedef std::map<varid_type, octet_sequnce > pgi_type;
            typedef std::pair<varid_type, pgi_type> pgis_type;
            typedef std::map<varid_type, pgi_type> spdudata_type; // (it->first==0 contain pi_type in vector






            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   spdudata utill   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                 

            class spdudata {
                typedef boost::shared_ptr<spdudata_type> spdudata_type_ptr;

            public:

                spdudata() : value_(new spdudata_type()), type_(0), error_(false) {
                }

                explicit spdudata(spdu_type spdu) : value_(new spdudata_type()), type_(spdu), error_(false) {
                }

                explicit spdudata(const const_buffer& vl) : value_(new spdudata_type()), seq_(), type_(0), error_(false) {
                    parse_vars(buffer_to_raw(vl));
                }

                spdu_type type() const {
                    return type_;
                }

                bool error() const {
                    return error_;
                }

                void setPGI(varid_type cod1, varid_type cod2, const octet_sequnce& val = NULL_OCTET_SEQUENCE);

                void setPGI(varid_type cod1, varid_type cod2, int8_t val);

                void setPGI(varid_type cod1, varid_type cod2, uint8_t val);

                void setPGI(varid_type cod1, varid_type cod2, int16_t val);

                void setPGI(varid_type cod1, varid_type cod2, uint16_t val);


                void setPI(varid_type cod, const octet_sequnce& val = NULL_OCTET_SEQUENCE);

                void setPI(varid_type cod, int8_t val);

                void setPI(varid_type cod, uint8_t val);

                void setPI(varid_type cod, int16_t val);

                void setPI(varid_type cod, uint16_t val);


                const octet_sequnce& getPGI(varid_type cod1, varid_type cod2) const;

                octet_sequnce& getPGI(varid_type cod1, varid_type cod2);

                bool getPGI(varid_type cod1, varid_type cod2, int8_t& val, int8_t def = 0) const;

                bool getPGI(varid_type cod1, varid_type cod2, uint8_t& val, uint8_t def = 0) const;

                bool getPGI(varid_type cod1, varid_type cod2, int16_t& val, int16_t def = 0) const;

                bool getPGI(varid_type cod1, varid_type cod2, uint16_t& val, uint16_t def = 0) const;

                const octet_sequnce& getPI(varid_type cod) const;

                octet_sequnce& getPI(varid_type cod);

                bool getPI(varid_type cod, int8_t& val, int8_t def = 0) const;

                bool getPI(varid_type cod, uint8_t& val, uint8_t def = 0) const;

                bool getPI(varid_type cod, int16_t& val, int16_t def = 0) const;

                bool getPI(varid_type cod, uint16_t& val, uint16_t def = 0) const;


                bool existPGI(varid_type cod1, varid_type cod2) const;

                bool existPI(varid_type cod) const;

                bool nullPGI(varid_type cod1, varid_type cod2) const;

                bool nullPI(varid_type cod) const;

                asn_coder_ptr sequence(asn_coder_ptr seq, std::size_t segment_size, bool first) const;

            private:

                bool error(bool val) {
                    return error_ = val;
                }

                bool parse();
                bool parse_vars(const octet_sequnce& vl);
                bool parse_pgi(varid_type tp, const octet_sequnce& vl);

                spdudata_type_ptr value_;
                mutable octet_sequnce seq_;
                spdu_type type_;
                bool error_;
                octet_sequnce null_val;
            };




            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   protocol_options   //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                

            struct protocol_options {
                typedef boost::shared_ptr<spdudata> spdudata_ptr;

                protocol_options() : vars_(new spdudata()) {
                }

                protocol_options(const const_buffer & vl) : vars_(new spdudata(vl)) {
                }

                protocol_options(const octet_sequnce& called, const octet_sequnce& calling = NULL_OCTET_SEQUENCE);

                protocol_options(const session_selector & ssel);

                const octet_sequnce & calling() const;

                void calling(const octet_sequnce & val);

                const octet_sequnce & called() const;

                void called(const octet_sequnce & val);

                const octet_sequnce & data() const;

                octet_sequnce & data();

                octet_type accept_version() const;

                void accept_version(octet_type vl);

                octet_type reject_version() const;

                void reject_version(octet_type vl);

                int16_t user_requirement() const;

                void user_requirement(int16_t vl);

                bool extendedSPDU() const;

                void extendedSPDU(bool vl);

                bool beginSPDU() const;

                bool endSPDU() const;

                void endSPDU(bool end, bool beg);

                bool overflow() const;

                void overflow(bool val);

                void refuse_reason(octet_type rsn, const octet_sequnce& val = NULL_OCTET_SEQUENCE);

                octet_type refuse_reason() const;

                uint16_t maxTPDU_to() const;

                uint16_t maxTPDU_from() const;

                void maxTPDU(uint16_t self, uint16_t dist);

            private:
                spdudata_ptr vars_;
            };

            const protocol_options NULL_PROTOCOL_OPTION = protocol_options();

#if defined(ITUX200_DEBUG) 

            std::ostream& operator<<(std::ostream& stream, const protocol_options& self);

#endif           



            //negotiate_x225impl_option

            inline static bool negotiate_x225impl_option(const protocol_options& self, const protocol_options& dist, octet_type& errorreason) {

                if (!(dist.user_requirement() & FU_WORK) ||
                        //dist.extendedSPDU() ||
                        (dist.maxTPDU_from() && (dist.maxTPDU_from() < MINAVAIL_MAX_TPDU)) ||
                        (dist.maxTPDU_to() && (dist.maxTPDU_to() < MINAVAIL_MAX_TPDU))) {
                    errorreason = DR_REASON_NEGOT;
                    return false;
                }

#ifndef CHECK_ISO_SELECTOR        
                if (!self.called().empty() && self.called() != dist.called()) {
                    errorreason = DR_REASON_ADDRESS;
                    return false;
                }
#endif                      
                return true;
            }




            std::size_t generate_header_CN(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //CONNECT SPDU

            std::size_t generate_header_OA(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //OVERFLOW ACCEPT SPDU

            std::size_t generate_header_CDO(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //CONNECT DATA OVERFLOW SPDU            

            std::size_t generate_header_AC(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //ACCEPT SPDU

            std::size_t generate_header_RF(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //REFUSE  SPDU        

            std::size_t generate_header_FN(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //FINISH SPDU            

            std::size_t generate_header_DN(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //DISCONNECT  SPDU          

            std::size_t generate_header_AB(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //ABORT SPDU                     

            std::size_t generate_header_AA(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //ABORT ACCEPT  SPDU                              

            std::size_t generate_header_NF(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //NOT FINISH  SPDU                      

            std::size_t generate_header_DT(const protocol_options& opt, asn_coder_ptr data, std::size_t segment_size, bool first); //DATA TRANSFER  SPDU   



            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   data_sender_sequences    //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////           

            template <typename ConstBufferSequence>
            class data_sender_sequences : public basic_sender_sequences {
            public:

                data_sender_sequences(const ConstBufferSequence& bf) : basic_sender_sequences() {
                    construct(bf);
                }

                void construct(const ConstBufferSequence& bf) {

                    typename ConstBufferSequence::const_iterator it = bf.begin();
                    typename ConstBufferSequence::const_iterator end = bf.end();
                    typename ConstBufferSequence::value_type val;

                    buff().push_back(const_buffer(&SEND_HEADER[0], SEND_HEADER.size()));

                    while (it != end) {
                        buff().push_back(const_buffer(*it));
                        it++;
                    }

                }

            };


            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  optimized data_sender_sequences    //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////               

            template<>
            class data_sender_sequences<const_sequences> : public basic_sender_sequences {
            public:

                data_sender_sequences<const_sequences>(const const_sequences& bf) :
                basic_sender_sequences(const_cast<const_sequences&> (bf)) {
                    construct();
                }

                void construct() {
                    buff().insert(buff().begin(), const_buffer(&SEND_HEADER[0], SEND_HEADER.size()));
                }

            };



            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   x225 sender  //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////              

            class sender {
            public:

                sender(spdu_type type) : type_(type), segment_size(0), option(NULL_PROTOCOL_OPTION) {
                }

                sender(spdu_type type, const protocol_options& opt, asn_coder_ptr data, std::size_t segmentsize = 0);

                virtual ~sender() {
                }

                bool ready() const {
                    if (segment_size)
                        return (buf_->ready() && !buf_->overflowed());
                    return buf_->ready();
                }

                const const_sequences& pop() {
                    return buf_ ? buf_->pop() : NULL_CONST_SEQUENCE;
                }

                std::size_t size(std::size_t sz) {
                    if (!segment_size)
                        return ready() ? 0 : buf_->size(sz);
                    std::size_t rslt = 0;
                    if (!buf_->ready())
                        rslt = buf_->size(sz);
                    if (!buf_->ready())
                        return rslt;
                    else {
                        if (buf_->overflowed()) {
                            construct();
                        }
                    }
                    return rslt;
                }

                spdu_type type() const {
                    return type_;
                }

                std::size_t constraint() const {
                    return buf_ ? buf_->constraint() : 0;
                }


            protected:

                void construct(bool first = false);

                void constructCN(bool first) {
                    std::size_t inc_size = generate_header_CN(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size ? segment_size : (EXTEDED_USERDATA_LIMIT + inc_size)));
                    segment_size = 0; // no segmentation
                }

                void constructOA(bool first) {
                    segment_size = 0; // no segmentation
                    generate_header_OA(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }

                void constructCDO(bool first) {
                    generate_header_CDO(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }

                void constructAC(bool first) {
                    generate_header_AC(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }

                void constructRF(bool first) {
                    generate_header_RF(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }

                void constructFN(bool first) {
                    generate_header_FN(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }

                void constructAB(bool first) {
                    generate_header_AB(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }

                void constructDN(bool first) {
                    generate_header_DN(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }

                void constructAA(bool first) {
                    segment_size = 0; // no segmentation
                    generate_header_AA(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }

                void constructDT(bool first) {
                    generate_header_DT(option, coder, segment_size, first);
                    buf_ = sender_sequnces_ptr(new basic_itu_sequences(coder, segment_size));
                }


                spdu_type type_;
                sender_sequnces_ptr buf_;
                std::size_t segment_size;
                asn_coder_ptr coder;
                const protocol_options& option;

            };








            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   x225 data_sender  //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                

            template <typename ConstBufferSequence >
            class data_sender : public sender {
            public:

                data_sender(const ConstBufferSequence& buff) : sender(DN_SPDU_ID) {
                    constructDT(buff);
                }

            protected:

                void constructDT(const ConstBufferSequence& buff) {
                    buf_ = sender_sequnces_ptr(new data_sender_sequences<ConstBufferSequence > (buff));
                }

            };





            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //   x225 receiver  //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

            const std::size_t SI_WITH_LI = 2;
            const std::size_t HDR_LI = 2;

            class receiver {
            public:

                typedef boost::shared_ptr< protocol_options > protocol_options_ptr;

                enum operation_state {
                    waittype,
                    waitsize,
                    waitheader,
                    waitdata,
                    complete,
                    error
                };

                receiver(const mutable_buffer& buff);

                receiver();

                mutable_buffer buffer();

                void put(std::size_t sz);

                bool ready() const {
                    return (state_ == error || state_ == complete);
                }

                operation_state state() const {
                    return state_;
                }

                spdu_type type() const {
                    return type_;
                }

                std::size_t datasize() const {
                    return datasize_;
                }

                octet_type class_option() const {
                    return class_option_;
                }

                octet_type reject_reason() const {
                    return reject_reason_;
                }

                const protocol_options& options() const {
                    return options_ ? *options_ : NULL_PROTOCOL_OPTION;
                }

                error_code errcode() const {
                    return errcode_;
                }

                error_code errcode(const error_code& err);

                bool has_next() const {
                    return has_next_;
                }

            private:

                operation_state state(operation_state val);

                void reject_reason(octet_type val);

                error_code check_type();

                error_code check_size();

                error_code check_header();



                operation_state state_;
                std::size_t size_;
                std::size_t estimatesize_;
                std::size_t datasize_;
                spdu_type type_;
                bool first_in_seq_;
                octet_type class_option_;
                octet_type reject_reason_;
                protocol_options_ptr options_;
                error_code errcode_;


                octet_sequnce_ptr type_data;
                mutable_buffer type_buff_;
                octet_sequnce_ptr header_data;
                mutable_buffer header_buff_;
                mutable_buffer userbuff_;
                bool has_next_;
            };













            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  x225 itu_socket  //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            class itu_socket : protected boost::itu::rfc1006::socket {
                static const std::size_t RESPONSE_BUFFER_SIZE = 1024;

                typedef boost::itu::rfc1006::socket super_type;
                typedef boost::itu::asn_coder_templ<> default_coder_type;

                typedef boost::shared_ptr<receiver> receiver_ptr;
                typedef boost::shared_ptr<sender> sender_ptr;

                friend class socket_acceptor;

            public:

                typedef super_type::protocol_type protocol_type;
                typedef super_type::lowest_layer_type lowest_layer_type;
                typedef super_type::native_handle_type native_handle_type;
                typedef super_type::native_type native_type;
                typedef super_type::message_flags message_flags;
                typedef super_type::endpoint_type endpoint_type;
                typedef super_type::service_type service_type;
                typedef super_type::shutdown_type shutdown_type;
                typedef super_type::implementation_type implementation_type;


                using super_type::assign;
                using super_type::at_mark;
                using super_type::available;
                using super_type::bind;
                using super_type::cancel;
                using super_type::close;
                using super_type::get_io_service;
                using super_type::get_option;
                using super_type::io_control;
                using super_type::is_open;
                using super_type::lowest_layer;
                using super_type::native;
                using super_type::native_handle;
                using super_type::native_non_blocking;
                using super_type::non_blocking;
                using super_type::open;
                using super_type::remote_endpoint;
                using super_type::set_option;
                using super_type::shutdown;

                //using super_type::ready;
                using super_type::is_acceptor;


            protected:


                using super_type::get_service;
                using super_type::get_implementation;

            public:



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Constructors  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

                explicit itu_socket(boost::asio::io_service& io_service, const session_selector& ssel = NULL_SESSION_SELECTOR,
                        asn_coder_ptr coder = asn_coder_ptr(new default_coder_type()))
                : boost::itu::rfc1006::socket(io_service, ssel.tselector()), option_(ssel.called(), ssel.calling()), rootcoder_(coder),
                session_version_(VERSION2), user_requirement_(FU_WORK), segmentsize_to_(0), segmentsize_from_(0), eof_state_(true) {
#ifdef  SEGMENTATION_TEST
#ifndef _MSC_VER                    
#warning "Segmentation test"     
#endif                  
                    segmentation_set(SEGMENTATION_TEST_TO, SEGMENTATION_TEST_FROM);
                    option_.maxTPDU(segmentsize_to_, segmentsize_from_);
#endif                   
                }

                itu_socket(boost::asio::io_service& io_service,
                        const endpoint_type& endpoint, const session_selector& ssel = NULL_SESSION_SELECTOR,
                        asn_coder_ptr coder = asn_coder_ptr(new default_coder_type()))
                : boost::itu::rfc1006::socket(io_service, ssel.tselector()), option_(ssel.called(), ssel.calling()), rootcoder_(coder),
                session_version_(VERSION2), user_requirement_(FU_WORK), segmentsize_to_(0), segmentsize_from_(0), eof_state_(true) {

#ifdef  SEGMENTATION_TEST
#ifndef _MSC_VER                    
#warning "Segmentation test"     
#endif                  
                    segmentation_set(SEGMENTATION_TEST_TO, SEGMENTATION_TEST_FROM);
                    option_.maxTPDU(segmentsize_to_, segmentsize_from_);
#endif  
                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Connnect operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

                void connect(const endpoint_type& peer_endpoint) {
                    error_code ec;
                    connect(peer_endpoint, ec);
                    boost::asio::detail::throw_error(ec, "connect");
                }

                error_code connect(const endpoint_type& peer_endpoint,
                        error_code& ec) {
                    rootcoder()->in()->clear();
                    return connect_impl(peer_endpoint, ec);
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            private:

                template <typename ConnectHandler>
                class connect_operation {
                    typedef connect_operation <ConnectHandler> operation_type;

                    enum stateconnection {
                        request,
                        response,
                        refuse
                    };

                public:

                    connect_operation(itu_socket& sock, ConnectHandler handlr) :
                    socket(sock),
                    handler(handlr),
                    state_(request),
                    sender_(sender_ptr(new sender(CN_SPDU_ID, sock.session_option(), sock.rootcoder(), sock.segmentsize_to()))),
                    receiver_(new receiver()) {

                    }

                    void start(const error_code& ec) {
                        if (!ec) {
                            if (!socket.check_size_constraints(CN_SPDU_ID)) {
                                state(refuse);
                                receiver_->errcode(ER_NOBUFFER);
                            }
                            operator()(ec, 0);
                        }
                        else
                            exit_handler(ec);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            switch (state_) {
                                case request:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this, sender_->constraint());
                                        return;
                                    }
                                    else {
                                        state(response);
                                        operator()(ec, 0);
                                        return;
                                    }
                                }
                                case response:
                                {
                                    receiver_->put(bytes_transferred);
                                    if (!receiver_->ready()) {
                                        socket.super_type::async_receive(boost::asio::buffer(receiver_->buffer()), 0, *this);
                                        return;
                                    }
                                    parse_response(ec);
                                    return;
                                }
                                case refuse:
                                {
                                    socket.super_type::async_release(
                                            boost::bind(&operation_type::disconnect, * this,
                                            boost::asio::placeholders::error));
                                    return;
                                }
                            }
                        }
                        exit_handler(ec);
                    }

                    void disconnect(const error_code& ec) {
                        exit_handler(receiver_->reject_reason() ? errorcode_by_reason(receiver_->reject_reason()) : ER_REFUSE);
                    }

                private:

                    void parse_response(const error_code& ec) {

                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case AC_SPDU_ID:
                                    {
                                        // Accepted. Negotiate options *ref X225 7.4.3
                                        socket.session_version(receiver_->options().accept_version());
                                        //if (receiver_->options().maxTPDU_to() || receiver_->options().maxTPDU_from())
                                        //    socket.segmentation_set( receiver_->options().maxTPDU_to(), receiver_->options().maxTPDU_from());  
                                        //socket.user_requirement(receiver_->options().user_requirement());
                                        socket.rootcoder()->in()->add(receiver_->options().data());
                                        exit_handler(ec);
                                        return;
                                        break;
                                    }
                                    case RF_SPDU_ID:
                                    {
                                        // Refuse. *ref X225 7.5.3
                                        // allways  transport disconnect
                                        state(refuse);
                                        operator()(ec, 0);
                                        return;
                                        break;
                                    }
                                    case OA_SPDU_ID:
                                    {
                                        //if (receiver_->options().maxTPDU_to() || receiver_->options().maxTPDU_from())
                                        //    socket.segmentation_set(receiver_->options().maxTPDU_to(), receiver_->options().maxTPDU_from()); 
                                        sender_ = sender_ptr(new sender(CDO_SPDU_ID, socket.session_option(), socket.rootcoder(), socket.segmentsize_to()));
                                        receiver_ = receiver_ptr(new receiver());
                                        state(request);
                                        operator()(ec, 0);
                                        return;
                                    }
                                }
                                break;
                            }
                        }
                        // allways  transport disconnect
                        state(refuse);
                        operator()(ec, 0);
                    }

                    void exit_handler(const error_code& ec) {
                        socket.rootcoder()->out()->clear();
                        handler(ec);
                    }

                    void state(stateconnection st) {
                        if (state_ != st)
                            state_ = st;
                    }

                    itu_socket& socket;
                    ConnectHandler handler;
                    stateconnection state_;
                    sender_ptr sender_;
                    receiver_ptr receiver_;

                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            public:

                template <typename ConnectHandler>
                void async_connect(const endpoint_type& peer_endpoint,
                        BOOST_ASIO_MOVE_ARG(ConnectHandler) handler) {

                    //BOOST_ASIO_CONNECT_HANDLER_CHECK(ConnectHandler, handler) type_check;

                    typedef connect_operation<ConnectHandler> connect_operation_type;

                    rootcoder()->in()->clear();
                    super_type::async_connect(peer_endpoint, boost::bind(&connect_operation_type::start,
                            connect_operation_type(*this, handler), boost::asio::placeholders::error));
                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Release operation  //
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

                void release() {

                    error_code ec;
                    release(ec);
                    boost::asio::detail::throw_error(ec, "release");
                }

                error_code release(error_code& ec) {
                    rootcoder()->in()->clear();
                    return release_impl(SESSION_FN_RELEASE, ec);
                }

                void abort() {

                    error_code ec;
                    release(ec);
                    boost::asio::detail::throw_error(ec, "abort");
                }

                error_code abort(error_code& ec) {
                    rootcoder()->in()->clear();
                    return release_impl(SESSION_AB_RELEASE, ec);
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    

            private:

                template <typename ReleaseHandler>
                class release_operation {
                    typedef release_operation<ReleaseHandler> operation_type;

                    enum stateconnection {
                        request,
                        response,
                        refuse
                    };

                public:

                    release_operation(itu_socket& sock, ReleaseHandler handlr, release_type type) :
                    socket(sock),
                    handler(handlr),
                    sender_(sender_ptr(new sender(release_type_to_spdu(type), sock.session_option(), sock.rootcoder(), sock.segmentsize_to()))),
                    receiver_(new receiver()),
                    type_(type),
                    state_(request),
                    errorrelease_(),
                    collision_(false) {
                    }

                    void start() {
                        error_code ec;
                        operator()(ec, 0);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            switch (state_) {
                                case request:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this, sender_->constraint());
                                        return;
                                    }
                                    // no keep transport  it dont wait AA *ref X225 7.9.2
                                    state((collision_ || type_ == SESSION_AB_RELEASE) ? refuse : response);
                                    operator()(ec, 0);
                                    return;
                                }
                                case response:
                                {
                                    receiver_->put(bytes_transferred);
                                    if (!receiver_->ready()) {
                                        socket.super_type::async_receive(boost::asio::buffer(receiver_->buffer()), 0, *this);
                                        return;
                                    }
                                    parse_response(ec);
                                    return;
                                }
                                case refuse:
                                {
                                    socket.super_type::async_release(
                                            boost::bind(&operation_type::disconnect, * this,
                                            boost::asio::placeholders::error));
                                    return;
                                }
                            }

                        }
                        exit_handler(ec);
                    }

                    void disconnect(const error_code& ec) {
                        // ignore transport refuse error
                        exit_handler(errorrelease_);
                    }


                private:

                    void parse_response(const error_code& ec) {
                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case DN_SPDU_ID:
                                    {
                                        if (type_ == SESSION_FN_RELEASE) {
                                            //Accepted disconnect. *ref X225 7.7
                                            socket.rootcoder()->in()->add(receiver_->options().data());
                                        }
                                        else {
                                            // unexpected;
                                            errorrelease_ = ER_PROTOCOL;
                                        }
                                        break;
                                    }
                                    case AA_SPDU_ID:
                                    {
                                        //Accepted abort. *ref X225 7.10 
                                        if (type_ != SESSION_AB_RELEASE) {
                                            // unexpected;
                                            errorrelease_ = ER_PROTOCOL;
                                        }
                                        break;
                                    }
                                    case RF_SPDU_ID:
                                    {
                                        // collision /. *ref X225 7.6
                                        if (type_ == SESSION_FN_RELEASE) {
                                            // initiators preference
                                            if (socket.is_acceptor()) {
                                                socket.rootcoder()->in()->clear();
                                                socket.rootcoder()->in()->add(receiver_->options().data());
                                                socket.negotiate_session_release();
                                                sender_ = sender_ptr(new sender(DN_SPDU_ID, socket.session_option(), socket.rootcoder(), socket.segmentsize_to()));
                                                state(request);
                                                operator()(ec, 0);
                                                collision_ = true;
                                                return;
                                            }
                                            // abort or  initiators release colision preference
                                        }
                                        break;
                                    }
                                    case AB_SPDU_ID:
                                    {
                                        // collision /. *ref X225 7.9
                                        if (type_ == SESSION_FN_RELEASE) {
                                            // abort colision
                                            // abort preference
                                            socket.rootcoder()->in()->clear();
                                            socket.rootcoder()->in()->add(receiver_->options().data());
                                            socket.negotiate_session_abort();
                                        }
                                        else {
                                            // initiators preference
                                            if (socket.is_acceptor()) {
                                                socket.rootcoder()->in()->clear();
                                                socket.rootcoder()->in()->add(receiver_->options().data());
                                                socket.negotiate_session_abort();
                                            }
                                            // abort colision
                                            // abort preference
                                        }
                                        break;
                                    }
                                    default:
                                    {
                                        errorrelease_ = ER_PROTOCOL;
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                errorrelease_ = ER_PROTOCOL;
                            }
                        }
                        state(refuse);
                        operator()(ec, 0);
                    }

                    void exit_handler(const error_code& ec) {
                        //socket.rootcoder()->out()->clear();
                        handler(ec);
                    }

                    void state(stateconnection st) {
                        if (state_ != st) {
                            state_ = st;
                        }
                    }

                    itu_socket& socket;
                    ReleaseHandler handler;
                    sender_ptr sender_;
                    receiver_ptr receiver_;
                    release_type type_;
                    stateconnection state_;
                    error_code errorrelease_;
                    bool collision_;

                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                   


            public:

                template <typename ReleaseHandler>
                void async_release(BOOST_ASIO_MOVE_ARG(ReleaseHandler) handler) {

                    typedef release_operation<ReleaseHandler > release_operation_type;

                    rootcoder()->in()->clear();

                    get_io_service().post(boost::bind(&release_operation_type::start,
                            release_operation<ReleaseHandler > (*this, handler, SESSION_FN_RELEASE)));

                }

                template <typename ReleaseHandler>
                void async_abort(BOOST_ASIO_MOVE_ARG(ReleaseHandler) handler) {

                    typedef release_operation<ReleaseHandler > release_operation_type;

                    rootcoder()->in()->clear();

                    get_io_service().post(boost::bind(&release_operation_type::start,
                            release_operation_type(*this, handler, SESSION_AB_RELEASE)));

                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Check accept operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

            protected:

                void check_accept() {

                    error_code ec;
                    check_accept(ec);
                    boost::asio::detail::throw_error(ec, "connect");
                }

                error_code check_accept(error_code& ec) {

                    rootcoder()->in()->clear();
                    return check_accept_imp(ec);
                }


            private:

                template <typename CheckAcceptHandler>
                class check_accept_operation {
                    typedef check_accept_operation<CheckAcceptHandler> operation_type;

                    enum stateconnection {
                        response,
                        request,
                        overflow,
                        reject,
                        refuse
                    };

                public:

                    check_accept_operation(itu_socket& sock, CheckAcceptHandler handlr) :
                    socket(sock),
                    handler(handlr),
                    state_(response),
                    sender_(),
                    receiver_(new receiver()),
                    errorrefuse_() {
                    }

                    void start() {

                        error_code ec;
                        operator()(ec, 0);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            switch (state_) {
                                case response:
                                {
                                    receiver_->put(bytes_transferred);
                                    if (!receiver_->ready()) {
                                        socket.super_type::async_receive(boost::asio::buffer(receiver_->buffer()), 0, *this);
                                        return;
                                    }
                                    parse_response(ec);
                                    return;
                                }
                                case request:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this, sender_->constraint());
                                        return;
                                    }
                                    exit_handler(ec);
                                    return;
                                }
                                case overflow:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this, sender_->constraint());
                                        return;
                                    }
                                    state(response);
                                    operator()(ec, 0);
                                    return;
                                }
                                case reject:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this, sender_->constraint());
                                        return;
                                    }
                                    state(refuse);
                                    operator()(ec, 0);
                                    return;
                                }
                                case refuse:
                                {
                                    socket.super_type::async_release(
                                            boost::bind(&operation_type::disconnect, * this,
                                            boost::asio::placeholders::error));
                                    return;
                                }
                            }
                        }
                        exit_handler(ec);
                    }

                    void disconnect(const error_code& ec) {
                        // ignore transport refuse error
                        exit_handler(errorrefuse_ ? errorrefuse_ : ER_PROTOCOL);
                    }




                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   


                private:

                    void parse_response(const error_code& ec) {
                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                        //Connect response. *ref X225 7.1
                                    case CN_SPDU_ID:
                                    {
                                        bool nouserreject = true;
                                        octet_type errorreason = 0;

                                        socket.rootcoder()->in()->add(receiver_->options().data());

                                        bool continiue_ = receiver_->options().overflow();

                                        if (!negotiate_x225impl_option(socket.session_option(), receiver_->options(), errorreason) ||
                                                !(nouserreject = (continiue_ ? true : socket.negotiate_session_accept()))) {
                                            // Netotiation fail send RF
                                            protocol_options options_ = socket.session_option();
                                            if (!nouserreject)
                                                options_.refuse_reason(DR_REASON_USER);
                                            else
                                                options_.refuse_reason(errorreason);
                                            sender_ = sender_ptr(new sender(RF_SPDU_ID, options_, socket.rootcoder(), socket.segmentsize_to()));
                                            state(reject);
                                            errorrefuse_ = ER_PROTOPT;
                                            operator()(ec, 0);
                                            return;
                                        }

                                        // Netotiation success send AC
                                        socket.session_version(receiver_->options().accept_version());
                                        if (receiver_->options().maxTPDU_from() || receiver_->options().maxTPDU_to())
                                            socket.segmentation_set(receiver_->options().maxTPDU_from(), receiver_->options().maxTPDU_to());

                                        //socket.user_requirement(receiver_->options().user_requirement());

                                        if (receiver_->options().overflow()) {
                                            sender_ = sender_ptr(new sender(OA_SPDU_ID, socket.session_option(), socket.rootcoder(), socket.segmentsize_to()));
                                            receiver_ = receiver_ptr(new receiver());
                                            state(overflow);

                                            operator()(ec, 0);
                                            return;
                                        }

                                        sender_ = sender_ptr(new sender(AC_SPDU_ID, socket.session_option(), socket.rootcoder(), socket.segmentsize_to()));
                                        state(request);
                                        operator()(ec, 0);
                                        return;
                                        break;
                                    }
                                    case CDO_SPDU_ID:
                                    {

                                        socket.rootcoder()->in()->add(receiver_->options().data());

                                        if (!socket.negotiate_session_accept()) {
                                            protocol_options options_ = socket.session_option();
                                            options_.refuse_reason(DR_REASON_USER);

                                            sender_ = sender_ptr(new sender(RF_SPDU_ID, options_, socket.rootcoder(), socket.segmentsize_to()));
                                            state(reject);
                                            errorrefuse_ = ER_PROTOPT;
                                            operator()(ec, 0);
                                            return;
                                        }
                                        sender_ = sender_ptr(new sender(AC_SPDU_ID, socket.session_option(), socket.rootcoder(), socket.segmentsize_to()));
                                        state(request);
                                        operator()(ec, 0);
                                        return;
                                    }
                                }
                                break;
                            }
                        }
                        // unexpected
                        state(refuse);
                        errorrefuse_ = ER_PROTOCOL;
                        operator()(ec, 0);
                    }

                    void exit_handler(const error_code& ec) {
                        socket.rootcoder()->out()->clear();
                        handler(ec);
                    }

                    void state(stateconnection st) {

                        if (state_ != st)
                            state_ = st;
                    }



                    itu_socket& socket;
                    CheckAcceptHandler handler;
                    stateconnection state_;
                    sender_ptr sender_;
                    receiver_ptr receiver_;
                    error_code errorrefuse_;

                };


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

            protected:

                template <typename CheckAcceptHandler>
                void async_check_accept(BOOST_ASIO_MOVE_ARG(CheckAcceptHandler) handler) {

                    typedef check_accept_operation<CheckAcceptHandler > check_accept_operation_type;

                    rootcoder()->in()->clear();
                    get_io_service().post(boost::bind(&check_accept_operation_type::start,
                            check_accept_operation_type(*this, handler)));
                }








                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Send operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

            public:

                template <typename ConstBufferSequence>
                std::size_t send(const ConstBufferSequence& buffers) {

                    return send(buffers, 0);
                }

                template <typename ConstBufferSequence>
                std::size_t send(const ConstBufferSequence& buffers,
                        message_flags flags) {
                    error_code ec;
                    std::size_t s = send(buffers, flags, ec);
                    boost::asio::detail::throw_error(ec, "send");

                    return s;
                }

                template <typename ConstBufferSequence>
                std::size_t write_some(const ConstBufferSequence& buffers) {
                    error_code ec;
                    std::size_t s = send(buffers, 0, ec);
                    boost::asio::detail::throw_error(ec, "write_some");

                    return s;
                }

                template <typename ConstBufferSequence>
                std::size_t write_some(const ConstBufferSequence& buffers,
                        error_code& ec) {

                    return send(buffers, 0, ec);
                }

                template <typename ConstBufferSequence>
                std::size_t send(const ConstBufferSequence& buffers,
                        message_flags flags, error_code& ec) {

                    return send_impl(buffers, flags, ec);
                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       

            private:

                template <typename SendHandler, typename ConstBufferSequence>
                class send_operation {
                    typedef send_operation<SendHandler, ConstBufferSequence> operation_type;

                public:

                    send_operation(itu_socket& sock, SendHandler handlr,
                            const ConstBufferSequence& buffers, message_flags flags) :
                    socket(sock),
                    handler(handlr),
                    sendersize(boost::asio::buffer_size(buffers)),
                    sender_(sender_ptr(new data_sender<ConstBufferSequence>(buffers))),
                    flags_(flags) {
                    }

                    send_operation(itu_socket& sock, SendHandler handlr, std::size_t buffsize) :
                    socket(sock),
                    handler(handlr),
                    sendersize(buffsize),
                    flags_() {
                    }

                    void start() {

                        error_code ec;
                        operator()(ec, 0);
                    }

                    void execute(const error_code& ec) {
                        handler(ec, ec ? 0 : sendersize);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            sender_->size(bytes_transferred);
                            if (!sender_->ready()) {
                                socket.super_type::async_send(sender_->pop(), flags_, * this);
                                return;
                            }
                        }
                        handler(ec, ec ? 0 : static_cast<std::size_t> (sendersize));
                    }


                private:

                    itu_socket& socket;
                    SendHandler handler;
                    std::size_t sendersize;
                    sender_ptr sender_;
                    message_flags flags_;

                };




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       


            public:

                template <typename ConstBufferSequence, typename WriteHandler>
                void async_send(const ConstBufferSequence& buffers,
                        BOOST_ASIO_MOVE_ARG(WriteHandler) handler) {

                    async_send(buffers, 0, handler);
                }

                template <typename ConstBufferSequence, typename WriteHandler>
                void async_write_some(const ConstBufferSequence& buffers,
                        BOOST_ASIO_MOVE_ARG(WriteHandler) handler) {

                    async_send<ConstBufferSequence, WriteHandler > (buffers, 0, handler);
                }

                template <typename ConstBufferSequence, typename WriteHandler>
                void async_send(const ConstBufferSequence& buffers,
                        message_flags flags,
                        BOOST_ASIO_MOVE_ARG(WriteHandler) handler) {

                    //BOOST_ASIO_WRITE_HANDLER_CHECK(WriteHandler, handler) type_check;

                    typedef send_operation<WriteHandler, ConstBufferSequence> send_operation_type;

                    if (segmentation_to()) {

                        std::size_t rslt = buffer_to_coder(buffers);
                        async_request(boost::bind(&send_operation_type::execute,
                                send_operation_type(*this, handler, rslt), boost::asio::placeholders::error));

                    }
                    else {
                        get_io_service().post(boost::bind(&send_operation_type::start,
                                send_operation_type(*this, handler, buffers, flags)));
                    }

                }



                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Request operation from coder  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       

            public:

                error_code& request(error_code& ec) {

                    rootcoder()->in()->clear();
                    std::size_t sendsize = rootcoder()->out()->size();
                    if (!sendsize)
                        return ec;
                    sender_ptr sender_(new sender(DT_SPDU_ID, session_option(), rootcoder(), segmentsize_to()));
                    sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                    while (!ec && !sender_->ready())
                        sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                    rootcoder()->out()->clear();
                    return ec;
                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       

            private:

                template <typename RequestHandler>
                class request_operation {
                    typedef request_operation<RequestHandler> operation_type;

                public:

                    request_operation(itu_socket& sock, RequestHandler handlr) :
                    socket(sock),
                    handler(handlr),
                    sender_(sender_ptr(new sender(DT_SPDU_ID, sock.session_option(), sock.rootcoder(), sock.segmentsize_to()))),
                    sendsize(sock.rootcoder()->out()->size()) {
                    }

                    void start() {
                        error_code ec;
                        if (!sendsize)
                            return exit_handler(ec);
                        else
                            operator()(ec, 0);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            sender_->size(bytes_transferred);
                            if (!sender_->ready()) {
                                socket.super_type::async_send(sender_->pop(), 0, * this, sender_->constraint());
                                return;
                            }
                        }
                        exit_handler(ec);
                    }


                private:

                    void exit_handler(const error_code& ec) {
                        socket.rootcoder()->out()->clear();
                        handler(ec);
                    }

                    itu_socket& socket;
                    RequestHandler handler;
                    sender_ptr sender_;
                    std::size_t sendsize;
                };




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       


            public:

                template <typename RequestHandler>
                void async_request(BOOST_ASIO_MOVE_ARG(RequestHandler) handler) {

                    typedef request_operation<RequestHandler> request_operation_type;

                    rootcoder()->in()->clear();

                    get_io_service().post(boost::bind(&request_operation_type::start,
                            request_operation_type(*this, handler)));

                }








                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Receive  operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

                template <typename MutableBufferSequence>
                std::size_t receive(const MutableBufferSequence& buffers) {
                    return receive<MutableBufferSequence > (buffers, 0);
                }

                template <typename MutableBufferSequence>
                std::size_t receive(const MutableBufferSequence& buffers,
                        message_flags flags) {
                    error_code ec;
                    std::size_t s = receive(buffers, flags, ec);
                    boost::asio::detail::throw_error(ec, "receive");
                    return s;
                }

                template <typename MutableBufferSequence>
                std::size_t read_some(const MutableBufferSequence& buffers,
                        error_code& ec) {

                    return receive(buffers, 0, ec);
                }

                template <typename MutableBufferSequence>
                std::size_t read_some(const MutableBufferSequence& buffers) {
                    error_code ec;
                    std::size_t s = receive(buffers, 0, ec);
                    boost::asio::detail::throw_error(ec, "read_some");

                    return s;
                }

                template <typename MutableBufferSequence>
                std::size_t receive(const MutableBufferSequence& buffers,
                        message_flags flags, error_code& ec) {

                    return receive_impl(buffers, flags, ec);
                }





                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    

            private:

                template <typename ReceiveHandler, typename Mutable_Buffers>
                class receive_operation {
                    typedef receive_operation<ReceiveHandler, Mutable_Buffers> operation_type;

                    enum stateconnection {
                        request,
                        response,
                        refuse
                    };



                public:

                    receive_operation(itu_socket& sock, ReceiveHandler handlr,
                            receiver_ptr receive, const Mutable_Buffers& buff, message_flags flags) :
                    socket(sock),
                    handler(handlr),
                    receiver_(receive),
                    buff_(buff),
                    sender_(),
                    state_(response),
                    flags_(flags),
                    errorrefuse_() {
                    }

                    void start() {
                        error_code ec;
                        operator()(ec, 0);
                    }

                    void operator()(const error_code& ec, std::size_t bytes_transferred) {
                        if (!ec) {
                            switch (state_) {
                                case response:
                                {
                                    receiver_->put(bytes_transferred);
                                    if (!receiver_->ready()) {
                                        socket.super_type::async_receive(boost::asio::buffer(receiver_->buffer()), flags_, *this);
                                        return;
                                    }
                                    if (!success(ec)) return;
                                    break;
                                }
                                case request:
                                {
                                    sender_->size(bytes_transferred);
                                    if (!sender_->ready()) {
                                        socket.super_type::async_send(sender_->pop(), 0, *this, sender_->constraint());
                                        return;
                                    }
                                    state(refuse);
                                    start();
                                    return;
                                }
                                case refuse:
                                {
                                    socket.super_type::async_release(
                                            boost::bind(&operation_type::disconnect, * this,
                                            boost::asio::placeholders::error));
                                    return;
                                }
                            }
                        }
                        handler(ec, ec ? 0 : static_cast<std::size_t> (receiver_->datasize()));
                    }

                    void disconnect(const error_code& ec) {
                        handler(errorrefuse_ ? errorrefuse_ : ER_PROTOCOL, 0);
                    }


                private:

                    bool success(const error_code& ec) {
                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case DT_SPDU_ID:
                                    {
                                        socket.eof_state_ = socket.segmentation_from() ? !receiver_->has_next() : true;
                                        return true;
                                    }
                                    case FN_SPDU_ID:
                                    {
                                        socket.rootcoder()->in()->clear();
                                        socket.rootcoder()->in()->add(receiver_->options().data());
                                        socket.negotiate_session_release();
                                        sender_ = sender_ptr(new sender(DN_SPDU_ID, socket.session_option(), socket.rootcoder(), socket.segmentsize_to()));
                                        state(request);
                                        errorrefuse_ = ER_RELEASE;
                                        operator()(ec, 0);
                                        return false;
                                    }
                                    case AB_SPDU_ID:
                                    {
                                        socket.rootcoder()->in()->clear();
                                        socket.rootcoder()->in()->add(receiver_->options().data());
                                        socket.negotiate_session_abort();
                                        state(refuse);
                                        errorrefuse_ = ER_ABORT;
                                        operator()(ec, 0);
                                        return false;
                                    }
                                }
                                break;
                            }
                        }
                        // unexpected
                        errorrefuse_ = ER_PROTOCOL;
                        state(refuse);
                        operator()(ec, 0);
                        return false;
                    }

                    void state(stateconnection st) {
                        if (state_ != st) {
                            state_ = st;
                        }
                    }

                    itu_socket& socket;
                    ReceiveHandler handler;
                    const Mutable_Buffers& buff_;
                    receiver_ptr receiver_;
                    sender_ptr sender_;
                    stateconnection state_;
                    message_flags flags_;
                    error_code errorrefuse_;
                };





                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                     

            public:

                template <typename MutableBufferSequence, typename ReadHandler>
                void async_receive(const MutableBufferSequence& buffers,
                        BOOST_ASIO_MOVE_ARG(ReadHandler) handler) {

                    async_receive<MutableBufferSequence, ReadHandler > (buffers, handler, 0);
                }

                template <typename MutableBufferSequence, typename ReadHandler>
                void async_read_some(const MutableBufferSequence& buffers,
                        BOOST_ASIO_MOVE_ARG(ReadHandler) handler) {

                    async_receive<MutableBufferSequence, ReadHandler > (buffers, 0, handler);
                }

                template <typename MutableBufferSequence, typename ReadHandler>
                void async_receive(const MutableBufferSequence& buffers,
                        message_flags flags,
                        BOOST_ASIO_MOVE_ARG(ReadHandler) handler) {

                    //BOOST_ASIO_READ_HANDLER_CHECK(ReadHandler, handler) type_check;

                    if (super_type::ready()) {

                        typedef receive_operation<ReadHandler, MutableBufferSequence> receive_operation_type;
                        typedef boost::asio::detail::buffer_sequence_adapter< mutable_buffer, MutableBufferSequence> sequence_adapter_type;

                        get_io_service().post(boost::bind(&receive_operation_type::start, receive_operation_type(*this, handler,
                                receiver_ptr(new receiver(sequence_adapter_type::first(buffers))), buffers, flags)));
                    }
                    else
                        super_type::async_receive(buffers, flags, handler);

                }








                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Response operation from coder  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       

            public:

                error_code& response(error_code& ec) {
                    rootcoder()->in()->clear();
                    std::size_t bytes_transferred = read_some(boost::asio::buffer(response_buffer()), ec);
                    if (!ec) {
                        octet_type* begin = boost::asio::buffer_cast<octet_type*>(response_buffer());
                        bytes_transferred = (bytes_transferred > RESPONSE_BUFFER_SIZE) ? RESPONSE_BUFFER_SIZE : bytes_transferred;
                        rootcoder()->in()->add(octet_sequnce(begin, begin + bytes_transferred));

                        while (!ec && !ready()) {
                            bytes_transferred = read_some(boost::asio::buffer(response_buffer()), ec);
                            if (!ec) {
                                begin = boost::asio::buffer_cast<octet_type*>(response_buffer());
                                bytes_transferred = (bytes_transferred > RESPONSE_BUFFER_SIZE) ? RESPONSE_BUFFER_SIZE : bytes_transferred;
                                rootcoder()->in()->add(octet_sequnce(begin, begin + bytes_transferred));
                            }
                        }
                    }
                    return ec;
                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       

            private:

                template <typename ResponseHandler>
                class response_operation {
                    typedef response_operation<ResponseHandler> operation_type;

                public:

                    response_operation(itu_socket& sock, ResponseHandler handlr) :
                    socket(sock),
                    handler(handlr) {
                    }

                    void start(const error_code& ec, size_t bytes_transferred) {
                        operator()(ec, bytes_transferred);
                    }

                    void operator()(const error_code& ec, size_t bytes_transferred) {
                        if (!ec) {
                            bytes_transferred = (bytes_transferred > RESPONSE_BUFFER_SIZE) ? RESPONSE_BUFFER_SIZE : bytes_transferred;
                            octet_type* begin = boost::asio::buffer_cast<octet_type*>(socket.response_buffer());
                            socket.rootcoder()->in()->add(octet_sequnce(begin, begin + bytes_transferred));

                            if (!socket.ready()) {
                                socket.async_read_some(boost::asio::buffer(socket.response_buffer()), *this);
                                return;
                            }
                        }
                        handler(ec);
                    }


                private:

                    itu_socket& socket;
                    ResponseHandler handler;
                };




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       


            public:

                template <typename ResponseHandler>
                void async_response(BOOST_ASIO_MOVE_ARG(ResponseHandler) handler) {

                    typedef response_operation<ResponseHandler> response_operation_type;

                    rootcoder()->in()->clear();
                    async_read_some(boost::asio::buffer(response_buffer()),
                            boost::bind(&response_operation_type::start,
                            response_operation_type(*this, handler), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

                }








                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Conversation (request-response) operation from coder  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       

            public:

                error_code& conversation(error_code& ec) {
                    if (!rootcoder()->out()->size())
                        return ec;
                    request(ec);
                    if (!ec) {
                        rootcoder()->out()->clear();
                        response(ec);
                    }
                    return ec;
                }

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       

            private:

                template <typename ConversationHandler>
                class conversation_operation {
                    typedef conversation_operation<ConversationHandler> operation_type;

                public:

                    conversation_operation(itu_socket& sock, ConversationHandler handlr) :
                    socket(sock),
                    handler(handlr),
                    sendsize(sock.rootcoder()->out()->size()) {
                    }

                    void start() {
                        error_code ec;
                        if (!sendsize)
                            return handler(ec);
                        else
                            socket.async_request(* this);
                    }

                    void operator()(const error_code& ec) {
                        if (!ec) {
                            socket.rootcoder()->out()->clear();
                            socket.async_response(
                                    boost::bind(&operation_type::exit_handler, * this,
                                    boost::asio::placeholders::error));
                            return;
                        }
                        handler(ec);
                    }

                    void exit_handler(const error_code& ec) {
                        handler(ec);
                    }


                private:

                    itu_socket& socket;
                    ConversationHandler handler;
                    sender_ptr sender_;
                    std::size_t sendsize;
                };




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       


            public:

                template <typename ConversationHandler>
                void async_conversation(BOOST_ASIO_MOVE_ARG(ConversationHandler) handler) {

                    typedef conversation_operation<ConversationHandler> conversation_operation_type;

                    //rootcoder()->in()->clear();

                    get_io_service().post(boost::bind(&conversation_operation_type::start,
                            conversation_operation_type(*this, handler)));

                }

                asn_coder_ptr rootcoder() {
                    return rootcoder_;
                }

                asn_coder_ptr rootcoder() const {
                    return rootcoder_;
                }

                bool ready() const {
                    return segmentation_from() ? (super_type::ready() && eof_state_) : (super_type::ready());
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  protected member  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                     

            protected:

                virtual bool negotiate_session_accept() {
                    rootcoder()->out()->clear();
                    rootcoder()->out()->add(ECHO_NEGOTIATE);
                    rootcoder()->out()->add(rootcoder()->in()->buffers());
                    return true;
                }

                virtual bool negotiate_session_release() {
                    rootcoder()->out()->clear();
                    rootcoder()->out()->add(ECHO_NEGOTIATE);
                    rootcoder()->out()->add(rootcoder()->in()->buffers());
                    return true;
                }

                virtual bool negotiate_session_abort() {
                    return true;
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  private member  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                       

            private:

                const protocol_options& session_option() const {
                    return option_;
                }

                void session_option(const session_selector& ssel) {
                    option_.called(ssel.called());
                    option_.calling(ssel.calling());
                }

                octet_type session_version() const {
                    return session_version_;
                }

                void session_version(octet_type val) {
                    session_version_ = (val & VERSION2) ? VERSION2 : VERSION1;
                    option_.accept_version(session_version_);
                }

                int16_t user_requirement() const {
                    return user_requirement_;
                }

                void user_requirement(int16_t val) {
                    user_requirement_ = val & FU_WORK;
                    option_.user_requirement(user_requirement_);
                }

                std::size_t segmentsize_to() const {
                    return static_cast<std::size_t> (segmentsize_to_ ?
                            ((segmentsize_to_ < MINAVAIL_MAX_TPDU) ? MINAVAIL_MAX_TPDU : segmentsize_to_) : 0);
                }

                std::size_t segmentsize_from() const {
                    return static_cast<std::size_t> (segmentsize_from_ ?
                            ((segmentsize_from_ < MINAVAIL_MAX_TPDU) ? MINAVAIL_MAX_TPDU : segmentsize_from_) : 0);
                }

                void segmentation_set(uint16_t to_, uint16_t from_) {
                    if (to_ && to_ < MINAVAIL_MAX_TPDU)
                        to_ = MINAVAIL_MAX_TPDU;
                    if (from_ && from_ < MINAVAIL_MAX_TPDU)
                        from_ = MINAVAIL_MAX_TPDU;
                    segmentsize_to_ = to_;
                    segmentsize_from_ = from_;
                    option_.maxTPDU(segmentsize_to_, segmentsize_from_);
                }

                bool segmentation_from() const {
                    return segmentsize_from_;
                }

                bool segmentation_to() const {
                    return segmentsize_to_;
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  private implementator  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

                template <typename ConstBufferSequence>
                std::size_t buffer_to_coder(const ConstBufferSequence& buffers) {

                    rootcoder()->out()->clear();

                    typename ConstBufferSequence::const_iterator it = buffers.begin();
                    typename ConstBufferSequence::const_iterator end = buffers.end();

                    while (it != end) {
                        rootcoder()->out()->add(buffer_to_raw(const_buffer(*it)));
                        it++;
                    }

                    return rootcoder()->out()->size();
                }

                error_code connect_impl(const endpoint_type& peer_endpoint,
                        error_code& ec) {

                    if (!check_size_constraints(CN_SPDU_ID)) {
                        return connect_impl_exit(ER_NOBUFFER);
                    }

                    if (super_type::connect(peer_endpoint, ec))
                        return connect_impl_exit(ec);

                    sender_ptr sender_(sender_ptr(new sender(CN_SPDU_ID, session_option(), rootcoder(), segmentsize_to())));
                    while (!ec && !sender_->ready())
                        sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));

                    if (!ec) {
                        receiver_ptr receiver_(receiver_ptr(new receiver()));
                        while (!ec && !receiver_->ready())
                            receiver_->put(super_type::receive(boost::asio::buffer(receiver_->buffer()), 0, ec));

                        while (!ec) {
                            switch (receiver_->state()) {
                                case receiver::complete:
                                {
                                    switch (receiver_->type()) {
                                        case AC_SPDU_ID:
                                        {
                                            // Accepted. Negotiate options *ref X225 7.4.3
                                            session_version(receiver_->options().accept_version());
                                            //if (receiver_->options().maxTPDU_to() || receiver_->options().maxTPDU_from())
                                            //segmentation_set(receiver_->options().maxTPDU_to(), receiver_->options().maxTPDU_from())
                                            //socket.user_requirement(receiver_->options().user_requirement());
                                            rootcoder()->in()->add(receiver_->options().data());
                                            return connect_impl_exit(ec);
                                        }
                                        case RF_SPDU_ID:
                                        {
                                            // Refuse. *ref X225 7.5.3
                                            // allways  transport disconnect
                                            super_type::release(ec);
                                            return connect_impl_exit(receiver_->reject_reason() ? errorcode_by_reason(receiver_->reject_reason()) : ER_REFUSE);
                                        }
                                        case OA_SPDU_ID:
                                        {
                                            //if (receiver_->options().maxTPDU_to() || receiver_->options().maxTPDU_from())
                                            //segmentation_set(receiver_->options().maxTPDU_to(), receiver_->options().maxTPDU_from())
                                            sender_ = sender_ptr(new sender(CDO_SPDU_ID, session_option(), rootcoder(), segmentsize_to()));
                                            receiver_ = receiver_ptr(new receiver());
                                            while (!ec && !sender_->ready())
                                                sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                                            if (ec)
                                                break;
                                            while (!ec && !receiver_->ready())
                                                receiver_->put(super_type::receive(boost::asio::buffer(receiver_->buffer()), 0, ec));
                                            break;
                                        }
                                        default:
                                        {
                                            ec = ER_PROTOCOL;
                                        }
                                    }
                                }
                            }
                        }
                        // allways  transport disconnect
                        super_type::release(ec);
                        return connect_impl_exit(receiver_->reject_reason() ? errorcode_by_reason(receiver_->reject_reason()) : ER_REFUSE);

                    }
                    super_type::release(ec);
                    return connect_impl_exit(ec);
                }

                const error_code& connect_impl_exit(const error_code& err) {
                    rootcoder()->out()->clear();
                    return err;
                }

                error_code release_impl(release_type type, error_code& ec) {

                    sender_ptr sender_(new sender(release_type_to_spdu(type), session_option(), rootcoder(), segmentsize_to()));
                    while (!ec && !sender_->ready())
                        sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                    // no keep transport  it dont wait AA *ref X225 7.9.2
                    if (!ec && (type == SESSION_FN_RELEASE)) {
                        receiver_ptr receiver_(receiver_ptr(new receiver()));
                        while (!ec && !receiver_->ready())
                            receiver_->put(super_type::receive(boost::asio::buffer(receiver_->buffer()), 0, ec));
                        if (!ec) {
                            switch (receiver_->state()) {
                                case receiver::complete:
                                {
                                    switch (receiver_->type()) {
                                        case DN_SPDU_ID:
                                        {
                                            if (type == SESSION_FN_RELEASE) {
                                                //Accepted disconnect. *ref X225 7.7
                                                rootcoder()->in()->add(receiver_->options().data());
                                            }
                                            else {
                                                // unexpected;
                                                ec = ER_PROTOCOL;
                                            }
                                            break;
                                        }
                                        case AA_SPDU_ID:
                                        {
                                            //Accepted abort. *ref X225 7.10 
                                            if (type != SESSION_AB_RELEASE) {
                                                // unexpected;
                                                ec = ER_PROTOCOL;
                                            }
                                            break;
                                        }
                                        case RF_SPDU_ID:
                                        {
                                            // collision /. *ref X225 7.6
                                            if (type == SESSION_FN_RELEASE) {
                                                // initiators preference
                                                if (is_acceptor()) {
                                                    rootcoder()->in()->clear();
                                                    rootcoder()->in()->add(receiver_->options().data());
                                                    negotiate_session_release();
                                                    sender_ = sender_ptr(new sender(DN_SPDU_ID, session_option(), rootcoder(), segmentsize_to()));
                                                    while (!ec && !sender_->ready())
                                                        sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                                                }
                                                // abort or  initiators release colision preference
                                            }
                                            break;
                                        }
                                        case AB_SPDU_ID:
                                        {
                                            // collision /. *ref X225 7.9
                                            if (type == SESSION_FN_RELEASE) {
                                                // abort colision
                                                // abort preference
                                                rootcoder()->in()->clear();
                                                rootcoder()->in()->add(receiver_->options().data());
                                                negotiate_session_abort();
                                            }
                                            else {
                                                // initiators preference
                                                if (is_acceptor()) {
                                                    rootcoder()->in()->clear();
                                                    rootcoder()->in()->add(receiver_->options().data());
                                                    negotiate_session_abort();
                                                }
                                                // abort colision
                                                // abort preference
                                            }
                                            break;
                                        }
                                        default:
                                        {
                                            ec = ER_PROTOCOL;
                                        }
                                    }
                                    break;
                                }
                                default:
                                {
                                    ec = ER_PROTOCOL;
                                }
                            }
                            error_code ecc;
                            super_type::release(ecc);
                            return connect_impl_exit(ec);
                        }
                    }
                    error_code ecc;
                    super_type::release(ecc);
                    return connect_impl_exit(ec);
                }

                const error_code& release_impl_exit(const error_code& err) {
                    rootcoder()->out()->clear();
                    return err;
                }

                error_code check_accept_imp(error_code& ec) {
                    receiver_ptr receiver_(receiver_ptr(new receiver()));
                    while (!ec && !receiver_->ready()) {
                        receiver_->put(super_type::receive(boost::asio::buffer(receiver_->buffer()), 0, ec));
                    }
                    while (!ec) {

                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                sender_ptr sender_;
                                switch (receiver_->type()) {
                                        //Connect response. *ref X225 7.1
                                    case CN_SPDU_ID:
                                    {
                                        bool nouserreject = true;
                                        octet_type errorreason = 0;

                                        rootcoder()->in()->add(receiver_->options().data());

                                        bool continiue_ = receiver_->options().overflow();

                                        if (!negotiate_x225impl_option(session_option(), receiver_->options(), errorreason) ||
                                                !(nouserreject = (continiue_ ? true : negotiate_session_accept()))) {
                                            // Netotiation fail send RF
                                            protocol_options options_ = session_option();
                                            if (!nouserreject)
                                                options_.refuse_reason(DR_REASON_USER);
                                            else
                                                options_.refuse_reason(errorreason);
                                            sender_ = sender_ptr(new sender(RF_SPDU_ID, options_, rootcoder(), segmentsize_to()));
                                            while (!ec && !sender_->ready())
                                                sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                                            ec = ER_PROTOPT;
                                            break;
                                        }

                                        // Netotiation success send AC
                                        session_version(receiver_->options().accept_version());
                                        if (receiver_->options().maxTPDU_from() || receiver_->options().maxTPDU_to())
                                            segmentation_set(receiver_->options().maxTPDU_from(), receiver_->options().maxTPDU_to());
                                        //user_requirement(receiver_->options().user_requirement());

                                        if (receiver_->options().overflow()) {
                                            sender_ = sender_ptr(new sender(OA_SPDU_ID, session_option(), rootcoder(), segmentsize_to()));
                                            while (!ec && !sender_->ready())
                                                sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                                            if (ec)
                                                break;
                                            receiver_ = receiver_ptr(new receiver());
                                            while (!ec && !receiver_->ready())
                                                receiver_->put(super_type::receive(boost::asio::buffer(receiver_->buffer()), 0, ec));
                                            break;
                                        }


                                        sender_ = sender_ptr(new sender(AC_SPDU_ID, session_option(), rootcoder(), segmentsize_to()));
                                        while (!ec && !sender_->ready())
                                            sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                                        if (!ec)
                                            return check_accept_imp_exit(ec);
                                        break;
                                    }
                                    case CDO_SPDU_ID:
                                    {

                                        rootcoder()->in()->add(receiver_->options().data());

                                        if (!negotiate_session_accept()) {
                                            protocol_options options_ = session_option();
                                            options_.refuse_reason(DR_REASON_USER);

                                            sender_ = sender_ptr(new sender(RF_SPDU_ID, options_, rootcoder(), segmentsize_to()));
                                            while (!ec && !sender_->ready())
                                                sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                                            if (ec)
                                                break;
                                            ec = ER_PROTOPT;
                                            break;
                                        }
                                        sender_ = sender_ptr(new sender(AC_SPDU_ID, session_option(), rootcoder(), segmentsize_to()));
                                        while (!ec && !sender_->ready())
                                            sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                                        if (!ec)
                                            return check_accept_imp_exit(ec);

                                        break;
                                    }
                                    default:
                                    {
                                        ec = ER_PROTOCOL;
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                ec = ER_PROTOCOL;
                            }
                        }
                    }
                    error_code ecc;
                    super_type::release(ecc);
                    return check_accept_imp_exit(ec ? ec : ER_PROTOCOL);
                }

                const error_code& check_accept_imp_exit(const error_code& err) {
                    rootcoder()->out()->clear();
                    return err;
                }

                template <typename ConstBufferSequence>
                std::size_t send_impl(const ConstBufferSequence& buffers,
                        message_flags flags, error_code& ec) {

                    if (segmentation_to()) {

                        std::size_t rslt = buffer_to_coder(buffers);
                        if (request(ec))
                            rslt = 0;
                        return rslt;

                    }
                    else {

                        sender_ptr sender_(new data_sender<ConstBufferSequence > (buffers));
                        while (!ec && !sender_->ready())
                            sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                        return ec ? 0 : boost::asio::buffer_size(buffers);

                    }
                }

                template <typename MutableBufferSequence>
                std::size_t receive_impl(const MutableBufferSequence& buffers,
                        message_flags flags, error_code& ec) {

                    if (!super_type::ready())
                        return super_type::receive(boost::asio::buffer(buffers), flags, ec);

                    receiver_ptr receiver_(new receiver(boost::asio::detail::buffer_sequence_adapter< boost::asio::mutable_buffer, MutableBufferSequence>::first(buffers)));
                    while (!ec && !receiver_->ready())
                        receiver_->put(super_type::receive(boost::asio::buffer(receiver_->buffer()), 0, ec));

                    if (!ec) {
                        switch (receiver_->state()) {
                            case receiver::complete:
                            {
                                switch (receiver_->type()) {
                                    case DT_SPDU_ID:
                                    {
                                        eof_state_ = segmentation_from() ? !receiver_->has_next() : true;
                                        return receiver_->datasize();
                                    }
                                    case FN_SPDU_ID:
                                    {
                                        sender_ptr sender_;
                                        rootcoder()->in()->clear();
                                        rootcoder()->in()->add(receiver_->options().data());
                                        negotiate_session_release();
                                        sender_ = sender_ptr(new sender(DN_SPDU_ID, session_option(), rootcoder(), segmentsize_to()));
                                        while (!ec && !sender_->ready())
                                            sender_->size(super_type::send(sender_->pop(), 0, ec, sender_->constraint()));
                                        ec = ER_RELEASE;
                                        break;
                                    }
                                    case AB_SPDU_ID:
                                    {
                                        rootcoder()->in()->clear();
                                        rootcoder()->in()->add(receiver_->options().data());
                                        negotiate_session_abort();
                                        ec = ER_ABORT;
                                        break;
                                    }
                                    default:
                                    {
                                        ec = ER_PROTOCOL;
                                    }
                                }
                                break;
                            }
                            default:
                            {
                                ec = ER_PROTOCOL;
                            }
                        }
                    }
                    error_code ecc;
                    super_type::release(ecc);
                    return 0;
                }

                bool check_size_constraints(spdu_type tp) {
                    if (tp == DT_SPDU_ID) return true;
                    if (tp == CN_SPDU_ID)
                        return rootcoder()->out()->size() <= (SERVICE_SPDU_CONSTRAINTS + EXTEDED_USERDATA_LIMIT);
                    return rootcoder()->out()->size() <= SERVICE_SPDU_CONSTRAINTS;
                }

                mutable_buffer response_buffer() {
                    if (response_buffer_)
                        return boost::asio::buffer(*response_buffer_);
                    response_buffer_ = octet_sequnce_ptr(new octet_sequnce(RESPONSE_BUFFER_SIZE));
                    return boost::asio::buffer(*response_buffer_);
                }



                protocol_options option_;
                asn_coder_ptr rootcoder_;
                octet_type session_version_;
                int16_t user_requirement_;
                uint16_t segmentsize_to_;
                uint16_t segmentsize_from_;
                octet_sequnce_ptr response_buffer_;
                bool eof_state_;

            };






            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //  x225 socket_acceptor_service //
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            class socket_acceptor : protected boost::itu::rfc1006impl::socket_acceptor {
                typedef boost::itu::rfc1006impl::socket_acceptor super_type;

                friend class itu_socket;

            public:

                typedef super_type::protocol_type protocol_type;
                typedef super_type::endpoint_type endpoint_type;
                typedef super_type::implementation_type implementation_type;
                typedef super_type::service_type service_type;
                typedef super_type::message_flags message_flags;
                typedef super_type::native_handle_type native_handle_type;
                typedef super_type::native_type native_type;

                using super_type::assign;
                using super_type::bind;
                using super_type::cancel;
                using super_type::close;
                using super_type::get_io_service;
                using super_type::get_option;
                using super_type::io_control;
                using super_type::is_open;
                using super_type::listen;
                using super_type::local_endpoint;
                using super_type::native;
                using super_type::native_handle;
                using super_type::native_non_blocking;
                using super_type::non_blocking;
                using super_type::open;
                using super_type::set_option;


            protected:

                using super_type::get_service;
                using super_type::get_implementation;


            public:

                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Constructors  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                                

                explicit socket_acceptor(boost::asio::io_service& io_service, const session_selector& ssel = NULL_SESSION_SELECTOR)
                : boost::itu::rfc1006impl::socket_acceptor(io_service, ssel.tselector()), session_selector_(ssel) {
                }

                socket_acceptor(boost::asio::io_service& io_service,
                        const endpoint_type& endpoint, const session_selector& ssel = NULL_SESSION_SELECTOR, bool reuse_addr = true)
                : boost::itu::rfc1006impl::socket_acceptor(io_service, endpoint, ssel.tselector(), reuse_addr), session_selector_(ssel) {
                }




                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                //  Accept operation  //
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////            

                void accept(itu_socket& peer) {
                    error_code ec;
                    accept_impl(peer, ec);
                    boost::asio::detail::throw_error(ec, "accept");
                }

                error_code accept(
                        itu_socket& peer,
                        error_code& ec) {
                    return accept_impl(peer, ec);
                }

                void accept(itu_socket& peer,
                        endpoint_type& peer_endpoint) {
                    error_code ec;
                    accept_impl(peer, peer_endpoint, ec);
                    boost::asio::detail::throw_error(ec, "accept");
                }

                error_code accept(
                        itu_socket & peer,
                        endpoint_type& peer_endpoint, error_code& ec) {
                    return accept_impl(peer, peer_endpoint, ec);
                }

                template <typename AcceptHandler>
                void async_accept(itu_socket& peer,
                        endpoint_type& peer_endpoint,
                        BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {

                    async_accept_impl(peer, peer_endpoint, handler);
                }

                template <typename AcceptHandler>
                void async_accept(itu_socket& peer,
                        BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {

                    async_accept_impl(peer, handler);
                }


                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                     

            private:

                template <typename AcceptHandler>
                class accept_operation {
                    typedef accept_operation<AcceptHandler> operation_type;

                public:

                    accept_operation(AcceptHandler handlr, itu_socket& sock)
                    : handler(handlr), socket(sock) {
                    }

                    void execute(const error_code& ec) {
                        if (!ec)
                            socket.async_check_accept(boost::bind(&operation_type::accept_result, *this,
                                boost::asio::placeholders::error));
                        else
                            handler(ec);
                    }

                    void accept_result(const error_code& ec) {
                        handler(ec);
                    }

                private:
                    AcceptHandler handler;
                    itu_socket& socket;
                };



                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

                template <typename AcceptHandler>
                void async_accept_impl(itu_socket& peer,
                        endpoint_type& peer_endpoint, BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {

                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;

                    typedef accept_operation<AcceptHandler > accept_operation_type;

                    peer.session_option(session_selector_);
                    super_type::async_accept(peer, peer_endpoint, boost::bind(&accept_operation_type::execute,
                            accept_operation_type(handler, peer), boost::asio::placeholders::error));

                }

                template <typename AcceptHandler>
                void async_accept_impl(itu_socket& peer,
                        BOOST_ASIO_MOVE_ARG(AcceptHandler) handler) {

                    //BOOST_ASIO_ACCEPT_HANDLER_CHECK(AcceptHandler, handler) type_check;

                    typedef accept_operation<AcceptHandler > accept_operation_type;

                    peer.session_option(session_selector_);
                    super_type::async_accept(peer, boost::bind(&accept_operation_type::execute,
                            accept_operation_type(handler, peer), boost::asio::placeholders::error));

                }

                error_code accept_impl(
                        itu_socket& peer,
                        endpoint_type& peer_endpoint, error_code& ec) {
                    peer.session_option(session_selector_);
                    super_type::accept(peer, peer_endpoint, ec);
                    if (ec)
                        return ec;
                    peer.check_accept(ec);
                    return ec;
                }

                error_code accept_impl(
                        itu_socket& peer,
                        error_code& ec) {
                    peer.session_option(session_selector_);
                    super_type::accept(peer, ec);
                    if (ec)
                        return ec;
                    peer.check_accept(ec);
                    return ec;
                }

            private:
                session_selector session_selector_;

            };
        }





        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  x225 declaration  //
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////            

        class x225 {
        public:

            typedef boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint;

            typedef session_selector selector;
            typedef session_selector s_selector;
            typedef transport_selector t_selector;

            static x225 v4() {

                return x225(PF_INET);
            }

            static x225 v6() {

                return x225(PF_INET6);
            }

            int type() const {

                return SOCK_STREAM;
            }

            int protocol() const {

                return IPPROTO_TCP;
            }

            int family() const {

                return family_;
            }

            typedef x225impl::itu_socket socket;

            typedef x225impl::socket_acceptor acceptor;

            typedef boost::asio::ip::basic_resolver<boost::asio::ip::tcp> resolver;

#if !defined(BOOST_NO_IOSTREAM)
            typedef boost::asio::basic_socket_iostream<boost::asio::ip::tcp> iostream;
#endif 


            typedef boost::asio::detail::socket_option::boolean<
            IPPROTO_TCP, TCP_NODELAY> no_delay;

            /// Compare two protocols for equality.

            friend bool operator==(const x225& p1, const x225& p2) {

                return p1.family_ == p2.family_;
            }

            friend bool operator!=(const x225& p1, const x225& p2) {

                return p1.family_ != p2.family_;
            }

        private:

            explicit x225(int family)
            : family_(family) {
            }

            int family_;
        };

    }


} // namespace boost



#endif  