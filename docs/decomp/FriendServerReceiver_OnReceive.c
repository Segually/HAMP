// Void OnReceive(Packet)
void FriendServerReceiver::OnReceive(FriendServerReceiver *this, Packet *incoming, MethodInfo *method)
{
  Packet *pkt; // x21
  FriendServerReceiver *receiver; // x20
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // x1
  __int64 v8; // x1
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 v11; // x1
  __int64 v12; // x1
  __int64 v13; // x1
  __int64 v14; // x1
  __int64 v15; // x1
  __int64 v16; // x1
  __int64 v17; // x1
  __int64 v18; // x1
  __int64 v19; // x1
  __int64 v20; // x1
  __int64 v21; // x1
  __int64 v22; // x1
  __int64 v23; // x1
  __int64 v24; // x1
  __int64 v25; // x1
  __int64 v26; // x1
  __int64 v27; // x1
  __int64 v28; // x1
  __int64 v29; // x1
  __int64 v30; // x1
  __int64 v31; // x1
  __int64 v32; // x1
  __int64 v33; // x1
  __int64 v34; // x1
  __int64 v35; // x1
  __int64 v36; // x1
  __int64 v37; // x1
  __int64 v38; // x1
  __int64 v39; // x1
  __int64 v40; // x1
  __int64 v41; // x1
  __int64 v42; // x1
  __int64 v43; // x1
  __int64 v44; // x1
  __int64 v45; // x1
  __int64 v46; // x1
  __int64 v47; // x1
  __int64 v48; // x1
  __int64 v49; // x1
  __int64 v50; // x1
  __int64 v51; // x1
  __int64 v52; // x1
  __int64 v53; // x1
  __int64 v54; // x1
  __int64 v55; // x1
  __int64 v56; // x1
  __int64 v57; // x1
  __int64 v58; // x1
  __int64 v59; // x1
  __int64 v60; // x1
  __int64 v61; // x1
  __int64 v62; // x1
  __int64 v63; // x1
  __int64 v64; // x1
  __int64 v65; // x1
  __int64 v66; // x1
  __int64 v67; // x1
  __int64 v68; // x1
  __int64 v69; // x1
  __int64 v70; // x1
  __int64 v71; // x1
  __int64 v72; // x1
  __int64 v73; // x1
  __int64 v74; // x1
  __int64 v75; // x1
  __int64 v76; // x1
  __int64 v77; // x1
  __int64 v78; // x1
  __int64 v79; // x1
  __int64 v80; // x1
  __int64 v81; // x1
  __int64 v82; // x1
  __int64 v83; // x1
  __int64 v84; // x1
  __int64 v85; // x1
  __int64 v86; // x1
  __int64 v87; // x1
  __int64 v88; // x1
  __int64 v89; // x1
  __int64 v90; // x1
  __int64 v91; // x1
  __int64 v92; // x1
  __int64 v93; // x1
  __int64 v94; // x1
  __int64 v95; // x1
  __int64 v96; // x1
  __int64 v97; // x1
  __int64 v98; // x1
  __int64 v99; // x1
  __int64 v100; // x1
  __int64 v101; // x1
  __int64 v102; // x1
  __int64 v103; // x1
  __int64 v104; // x1
  __int64 v105; // x1
  __int64 v106; // x1
  __int64 v107; // x1
  __int64 v108; // x1
  __int64 v109; // x1
  __int64 v110; // x1
  __int64 v111; // x1
  __int64 v112; // x1
  __int64 v113; // x1
  __int64 v114; // x1
  __int64 v115; // x1
  __int64 v116; // x1
  __int64 v117; // x1
  __int64 v118; // x1
  __int64 v119; // x1
  __int64 v120; // x1
  __int64 v121; // x1
  __int64 v122; // x1
  __int64 v123; // x1
  uint8_t opcode; // w0
  String *name; // x0
  MethodInfo *v126; // x3
  WindowControl *Instance; // x8
  FriendServerInterface *v128; // x9
  String **v129; // x8
  bool v130; // w2
  String *v131; // x21
  String *v132; // x22
  String *v133; // x23
  String *v134; // x24
  String *v135; // x25
  String *v136; // x26
  FriendServerReceiver *v137; // x20
  _DWORD *v138; // x8
  struct MethodInfo *v139; // x9
  __int64 v140; // x10
  char *v141; // x8
  String *v142; // x19
  String *v143; // x22
  MethodInfo *v144; // x2
  Friend *v145; // x0
  Friend *v146; // x20
  String *v147; // x19
  chat_log *v148; // x21
  FriendServerReceiver *v149; // x24
  String *v150; // x0
  MethodInfo *v151; // x3
  Friend *v152; // x1
  int v153; // w8
  String **v154; // x8
  String *v155; // x0
  MethodInfo *v156; // x2
  struct FriendServerConnector__Class *v157; // x0
  String *v158; // x0
  struct FriendServerInterface__Class *v159; // x8
  String *v160; // x0
  String *v161; // x24
  String *v162; // x19
  String *v163; // x21
  String *v164; // x26
  int16_t v165; // w23
  String *v166; // x24
  String *v167; // x0
  PopupControl *v168; // x20
  String *v169; // x1
  String *v170; // x0
  char v171; // w19
  String **v172; // x8
  int v173; // w20
  List_1_ToPing_ *v174; // x21
  String *v175; // x23
  String *v176; // x24
  int16_t v177; // w19
  FriendServerReceiver *v178; // x22
  ToPing__Array *v179; // x8
  struct MethodInfo *v180; // x9
  __int64 v181; // x10
  ToPing__Array__Class **v182; // x0
  FriendServerReceiver *v183; // x20
  String *v184; // x19
  uint8_t v185; // w22
  MethodInfo *v186; // x2
  MethodInfo *v187; // x3
  Friend *v188; // x19
  const char *const *v189; // x8
  String *v190; // x19
  String *v191; // x0
  bool v192; // w20
  Object *v193; // x21
  uint8_t v194; // w23
  Byte__Array *v195; // x22
  __int64 v196; // x24
  unsigned __int64 i; // x19
  Texture2D *v198; // x20
  int v199; // w19
  int v200; // w0
  MethodInfo *v201; // x3
  Object *v202; // x2
  Object *v203; // x1
  String *v204; // x0
  MethodInfo *v205; // x2
  String *v206; // x0
  struct WindowControl__Class *v207; // x8
  String *v208; // x0
  int v209; // w8
  String **v210; // x8
  String *GlobalString; // x0
  bool v212; // w19
  uint8_t v213; // w1
  String *v214; // x19
  int v215; // w8
  PopupControl__StaticFields *v216; // x8
  String **v217; // x9
  String *v218; // x21
  MethodInfo *v219; // x2
  Friend *v220; // x0
  MethodInfo *v221; // x3
  Friend *v222; // x19
  String *v223; // x0
  Packet *v224; // x28
  int v225; // w8
  FriendServerReceiver *v226; // x27
  __int64 v227; // x8
  String *v228; // x21
  String *v229; // x22
  uint8_t v230; // w19
  MethodInfo *v231; // x2
  int v232; // w20
  List_1_RecentlySeenPlayer_ **p_recently_seen_players; // x19
  Friend *v234; // x21
  FriendServerReceiver *v235; // x0
  MethodInfo *v236; // x3
  String *v237; // x0
  String *v238; // x1
  GameplayGUIControl *v239; // x19
  FriendServerInterface *v240; // x8
  Sprite *icon_got_friend_req; // x21
  String *v242; // x0
  String *v243; // x1
  FriendServerReceiver *v244; // x19
  int32_t v245; // w19
  struct FriendServerConnector__Class *v246; // x0
  struct FriendServerConnector__Class *v247; // x0
  FriendServerConnector *v248; // x19
  String *v249; // x0
  MethodInfo *v250; // x2
  MethodInfo *v251; // x3
  FriendServerReceiver *v252; // x19
  String *v253; // x0
  String *recently_seen_players; // x1
  FriendServerInterface *v255; // x8
  String *v256; // x20
  struct OnNotifClick__Class *v257; // x0
  String *v258; // x0
  MethodInfo *v259; // x2
  Friend *v260; // x20
  ChatCollection *chat; // x9
  List_1_chat_log_ *entries; // x8
  int32_t v263; // w2
  int v264; // w9
  String *v265; // x0
  String *v266; // x0
  int Byte; // w8
  struct FriendServerSender__Class *v268; // x8
  String *v269; // x0
  WindowControl *v270; // x8
  FriendServerInterface *v271; // x8
  const char *const *v272; // x19
  String *String; // x21
  String *v274; // x23
  String *v275; // x19
  PopupControl *v276; // x20
  String *v277; // x0
  WindowControl *v278; // x8
  FriendServerInterface *v279; // x9
  String *v280; // x21
  String *v281; // x19
  Friend *v282; // x20
  _DWORD *v283; // x8
  struct MethodInfo *v284; // x9
  __int64 v285; // x10
  char *v286; // x8
  int v287; // w19
  String *v288; // x21
  String **v289; // x8
  String **v290; // x9
  String *v291; // x21
  MethodInfo *v292; // x2
  Packet *FriendByUsername; // x0
  struct FriendServerConnector__Class *v294; // x0
  String *v295; // x0
  FriendServerReceiver *v296; // x0
  MethodInfo *v297; // x2
  String *v298; // x0
  MethodInfo *v299; // x2
  struct FriendServerConnector__Class *v300; // x0
  struct SceneManager__Class *v301; // x0
  FriendServerReceiver *v302; // x25
  Packet *v303; // x28
  List_1_System_Object_ *v304; // x21
  int v305; // w20
  String *v306; // x22
  String *v307; // x23
  String *v308; // x25
  String *v309; // x26
  String *v310; // x27
  Packet *v311; // x19
  int16_t v312; // w28
  int16_t v313; // w29
  String *server_game_mode; // x19
  FriendServerReceiver *v315; // x24
  Object__Array *v316; // x8
  struct MethodInfo *v317; // x9
  __int64 v318; // x10
  Object__Array__Class **v319; // x0
  List_1_ServerInfo_ *public_server_list; // x8
  int32_t v321; // w2
  int v322; // w9
  Object *Item; // x0
  __int64 v324; // x1
  __int64 v325; // x2
  List_1_System_Object_ *v326; // x8
  Object *current; // x20
  int32_t v328; // w21
  Object__Array *v329; // x9
  struct MethodInfo *v330; // x10
  __int64 v331; // x11
  Object__Array__Class **v332; // x0
  String *v333; // x28
  MethodInfo *v334; // x2
  Object *v335; // x22
  String *v336; // x0
  int16_t v337; // w0
  MethodInfo *v338; // x2
  String *v339; // x28
  MethodInfo *v340; // x2
  Object *v341; // x22
  struct SceneManager__Class *v342; // x0
  String *v343; // x0
  String *v344; // x20
  IFormatProvider *v345; // x22
  struct FriendServerConnector__Class *v346; // x0
  String *v347; // x0
  WindowControl *v348; // x8
  FriendServerInterface_friend_window_screen__Enum v349; // w1
  String *v350; // x0
  FriendServerInterface *v351; // x8
  FriendServerReceiver *v352; // x22
  Friend *v353; // x0
  Friend *v354; // x26
  String *v355; // x27
  Dictionary_2_System_Object_System_Object_ *v356; // x29
  String *v357; // x0
  Object *v358; // x2
  FriendServerInterface *v359; // x8
  Sprite *icon_invite; // x19
  String **v361; // x8
  Friend *v362; // x0
  String *v363; // x0
  Object *v364; // x2
  FriendServerInterface *v365; // x8
  String *v366; // x0
  ChatCollection *v367; // x8
  String *v368; // x0
  __int64 v369; // x8
  __int64 v370; // x8
  String *v371; // x23
  PopupControl *v372; // x19
  List_1_Friend_ *v373; // x19
  FriendServerReceiver *v374; // x20
  Friend__Array *v375; // x8
  struct MethodInfo *v376; // x9
  __int64 v377; // x10
  __int64 v378; // x0
  String *v379; // x0
  FriendServerReceiver *v380; // x20
  __int64 v381; // x8
  List_1_Friend_ *friends; // x8
  int32_t size; // w2
  int v384; // w9
  int Short; // w21
  String *v386; // x24
  String *v387; // x25
  uint8_t v388; // w23
  Friend *v389; // x22
  _DWORD *m_CachedPtr; // x8
  struct MethodInfo *v391; // x9
  __int64 recently_seen_players_low; // x10
  char *v393; // x8
  FriendServerReceiver *v394; // x0
  MethodInfo *v395; // x3
  String *v396; // x23
  IFormatProvider *InvariantCulture; // x19
  int v398; // w20
  String *v399; // x23
  String *v400; // x19
  FriendServerReceiver *v401; // x22
  _DWORD *v402; // x8
  struct MethodInfo *v403; // x9
  __int64 v404; // x10
  char *v405; // x8
  int v406; // w20
  String *v407; // x23
  String *v408; // x19
  FriendServerReceiver *v409; // x22
  _DWORD *v410; // x8
  struct MethodInfo *v411; // x9
  __int64 v412; // x10
  char *v413; // x8
  int v414; // w20
  List_1_ToPing_ *v415; // x22
  String *v416; // x24
  String *v417; // x25
  int16_t v418; // w19
  FriendServerReceiver *v419; // x23
  ToPing__Array *items; // x8
  struct MethodInfo *v421; // x9
  __int64 v422; // x10
  ToPing__Array__Class **v423; // x0
  struct FriendServerReceiver_c__Class *v424; // x0
  FriendServerReceiver *_9__26_1; // x23
  Object *v426; // x19
  FriendServerReceiver_c__StaticFields *static_fields; // x0
  List_1_Trophy_ *trophies; // x8
  int32_t v429; // w2
  int v430; // w9
  int v431; // w19
  String *v432; // x23
  String *v433; // x24
  String *v434; // x25
  String *v435; // x26
  String *v436; // x27
  String *v437; // x28
  FriendServerReceiver *v438; // x22
  _DWORD *v439; // x8
  struct MethodInfo *v440; // x9
  __int64 v441; // x10
  char *v442; // x8
  String *v443; // x0
  Object *v444; // x19
  struct FriendServerConnector__Class *v445; // x0
  String *v446; // x0
  WindowControl *v447; // x8
  struct FriendServerConnector__Class *v448; // x0
  String *v449; // x0
  Packet **v450; // x8
  String *v451; // x0
  WindowControl *v452; // x8
  String **v453; // x20
  String *v454; // x0
  String *v455; // x8
  PopupControl *v456; // x19
  FriendServerReceiver *v457; // [xsp+10h] [xbp-D0h]
  Packet *incominga; // [xsp+18h] [xbp-C8h]
  List_1_T_Enumerator_System_Object_ v459; // [xsp+20h] [xbp-C0h] BYREF
  DateTime last_online; // [xsp+38h] [xbp-A8h] BYREF
  Int32 v461; // [xsp+44h] [xbp-9Ch] BYREF
  DateTime result; // [xsp+48h] [xbp-98h] BYREF
  List_1_T_Enumerator_System_Object_ v463; // [xsp+50h] [xbp-90h] BYREF
  Byte v464; // [xsp+70h] [xbp-70h] BYREF
  Byte v465; // [xsp+74h] [xbp-6Ch] BYREF
  Scene v466; // [xsp+78h] [xbp-68h] BYREF
  DateTime v467; // 0:x0.8
  DateTime v468; // 0:x0.8
  Vector2 v469; // 0:s4.4,4:s5.4

  pkt = incoming; /*0x83521c*/
  receiver = this; /*0x835220*/
  if ( (byte_27E6BC5 & 1) == 0 ) /*0x835224*/
  {
    sub_73C778(&TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>, incoming); /*0x835230*/
    sub_73C778(&TypeInfo::System::Byte, v5); /*0x83523c*/
    sub_73C778(&TypeInfo::System::Globalization::CultureInfo, v6); /*0x835248*/
    sub_73C778(&TypeInfo::System::DateTime, v7); /*0x835254*/
    sub_73C778(&TypeInfo::UnityEngine::Debug, v8); /*0x835260*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::Add, v9); /*0x83526c*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add, v10); /*0x835278*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Dictionary, v11); /*0x835284*/
    sub_73C778(&TypeInfo::System::Collections::Generic::Dictionary<System::String,System::String>, v12); /*0x835290*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ServerInfo>::Dispose, v13); /*0x83529c*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ServerInfo>::MoveNext, v14); /*0x8352a8*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ServerInfo>::get_Current, v15); /*0x8352b4*/
    sub_73C778(&TypeInfo::FriendServerInterface, v16); /*0x8352c0*/
    sub_73C778(&MethodInfo::FriendServerReceiver::_OnReceive_b__26_0, v17); /*0x8352cc*/
    sub_73C778(&TypeInfo::Friend, v18); /*0x8352d8*/
    sub_73C778(&TypeInfo::GameServerConnector, v19); /*0x8352e4*/
    sub_73C778(&TypeInfo::GameplayGUIControl, v20); /*0x8352f0*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ServerInfo>::Add, v21); /*0x8352fc*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<Friend>::Add, v22); /*0x835308*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ToPing>::Add, v23); /*0x835314*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<Trophy>::Add, v24); /*0x835320*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<Friend>::Clear, v25); /*0x83532c*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<chat_log>::Clear, v26); /*0x835338*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<Trophy>::Clear, v27); /*0x835344*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ServerInfo>::Clear, v28); /*0x835350*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ServerInfo>::GetEnumerator, v29); /*0x83535c*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<Friend>::IndexOf, v30); /*0x835368*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ServerInfo>::Insert, v31); /*0x835374*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<Friend>::RemoveAt, v32); /*0x835380*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::Remove, v33); /*0x83538c*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ToPing>::List, v34); /*0x835398*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ServerInfo>::List, v35); /*0x8353a4*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ServerInfo>::get_Count, v36); /*0x8353b0*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ServerInfo>::get_Item, v37); /*0x8353bc*/
    sub_73C778(&TypeInfo::System::Collections::Generic::List<ServerInfo>, v38); /*0x8353c8*/
    sub_73C778(&TypeInfo::System::Collections::Generic::List<ToPing>, v39); /*0x8353d4*/
    sub_73C778(&TypeInfo::MathProblem, v40); /*0x8353e0*/
    sub_73C778(&TypeInfo::OnNotifClick, v41); /*0x8353ec*/
    sub_73C778(&TypeInfo::PingController, v42); /*0x8353f8*/
    sub_73C778(&TypeInfo::PlayerData, v43); /*0x835404*/
    sub_73C778(&TypeInfo::PopupControl, v44); /*0x835410*/
    sub_73C778(&TypeInfo::UnityEngine::SceneManagement::SceneManager, v45); /*0x83541c*/
    sub_73C778(&TypeInfo::ServerInfo, v46); /*0x835428*/
    sub_73C778(&TypeInfo::UnityEngine::Texture2D, v47); /*0x835434*/
    sub_73C778(&TypeInfo::ToPing, v48); /*0x835440*/
    sub_73C778(&TypeInfo::Trophy, v49); /*0x83544c*/
    sub_73C778(&MethodInfo::FriendServerReceiver::__c::_OnReceive_b__26_1, v50); /*0x835458*/
    sub_73C778(&TypeInfo::FriendServerReceiver::__c, v51); /*0x835464*/
    sub_73C778(&TypeInfo::WindowControl, v52); /*0x835470*/
    sub_73C778(&StringLiteral_Game, v53); /*0x83547c*/
    sub_73C778(&StringLiteral_Friend_request_sent_to__color__4, v54); /*0x835488*/
    sub_73C778(&StringLiteral_ALLOW, v55); /*0x835494*/
    sub_73C778(&StringLiteral_JOIN, v56); /*0x8354a0*/
    sub_73C778(&StringLiteral_n_wasted_autologins, v57); /*0x8354ac*/
    sub_73C778(&StringLiteral___contains_an_inappropriate_word, v58); /*0x8354b8*/
    sub_73C778(&StringLiteral__color__bbbbbb_Too_many_friends_, v59); /*0x8354c4*/
    sub_73C778(&StringLiteral_o, v60); /*0x8354d0*/
    sub_73C778(&StringLiteral____color_, v61); /*0x8354dc*/
    sub_73C778(&StringLiteral__invited_you_to_play___color_, v62); /*0x8354e8*/
    sub_73C778(&StringLiteral___already_has_30_friends__which_, v63); /*0x8354f4*/
    sub_73C778(&StringLiteral__they_want_to_join_me_, v64); /*0x835500*/
    sub_73C778(&StringLiteral___color__is_now_online____, v65); /*0x83550c*/
    sub_73C778(&StringLiteral_rand_code, v66); /*0x835518*/
    sub_73C778(&StringLiteral__incorrect_logins_, v67); /*0x835524*/
    sub_73C778(&StringLiteral___is_already_taken__Please_try_a, v68); /*0x835530*/
    sub_73C778(&StringLiteral_Connecting_to_private_server, v69); /*0x83553c*/
    sub_73C778(&StringLiteral_accept_invite, v70); /*0x835548*/
    sub_73C778(&StringLiteral__color__fffd91_, v71); /*0x835554*/
    sub_73C778(&StringLiteral__color__bbbbbb_Cannot_Add__color_0, v72); /*0x835560*/
    sub_73C778(&StringLiteral_Authenticating, v73); /*0x83556c*/
    sub_73C778(&StringLiteral_ERROR_403u000A_color__26ccff_Somethi, v74); /*0x835578*/
    sub_73C778(&StringLiteral___30, v75); /*0x835584*/
    sub_73C778(&StringLiteral__color__21bcff_, v76); /*0x835590*/
    sub_73C778(&StringLiteral___color__accepted_your_friend_re, v77); /*0x83559c*/
    sub_73C778(&StringLiteral__color__80d9ff_, v78); /*0x8355a8*/
    sub_73C778(&StringLiteral_server_name, v79); /*0x8355b4*/
    sub_73C778(&StringLiteral__color__bbbbbb_Why__color_, v80); /*0x8355c0*/
    sub_73C778(&StringLiteral___contains_letters_that_are_not_, v81); /*0x8355cc*/
    sub_73C778(&StringLiteral___already_sent_you_a_request, v82); /*0x8355d8*/
    sub_73C778(&StringLiteral__color__ff0000_WARNING__color_u000A_, v83); /*0x8355e4*/
    sub_73C778(&StringLiteral__color__bbbbbb_Too_many_friends__0, v84); /*0x8355f0*/
    sub_73C778(&StringLiteral__color__30ff8d_, v85); /*0x8355fc*/
    sub_73C778(&StringLiteral___is_already_your_friend_, v86); /*0x835608*/
    sub_73C778(&StringLiteral__wishes_to_join_your_game__color, v87); /*0x835614*/
    sub_73C778(&StringLiteral__color__bbbbbb_Username_unavaila, v88); /*0x835620*/
    sub_73C778(&StringLiteral_Could_not_join_u000A, v89); /*0x83562c*/
    sub_73C778(&StringLiteral____color__, v90); /*0x835638*/
    sub_73C778(&StringLiteral__private_, v91); /*0x835644*/
    sub_73C778(&StringLiteral_Login_Succeed___, v92); /*0x835650*/
    sub_73C778(&StringLiteral___does_not_exist_, v93); /*0x83565c*/
    sub_73C778(&StringLiteral__color__bbbbbb_Success___color_u000A, v94); /*0x835668*/
    sub_73C778(&StringLiteral__color__abebff_, v95); /*0x835674*/
    sub_73C778(&StringLiteral_Setting_up_private_server, v96); /*0x835680*/
    sub_73C778(&StringLiteral_Couldn_t_set_up_matchu000AThe_server, v97); /*0x83568c*/
    sub_73C778(&StringLiteral_Joining_game, v98); /*0x835698*/
    sub_73C778(&StringLiteral_Could_not_join_serveru000AServer_no_, v99); /*0x8356a4*/
    sub_73C778(&StringLiteral__they_invited_me_, v100); /*0x8356b0*/
    sub_73C778(&StringLiteral_Could_not_join_serveru000AServer_ful, v101); /*0x8356bc*/
    sub_73C778(&StringLiteral__color__bbbbbb_Cannot_Add__color, v102); /*0x8356c8*/
    sub_73C778(&StringLiteral_Invite_sent_, v103); /*0x8356d4*/
    sub_73C778(&StringLiteral_accept_other_join, v104); /*0x8356e0*/
    sub_73C778(&StringLiteral_text, v105); /*0x8356ec*/
    sub_73C778(&StringLiteral___color__0, v106); /*0x8356f8*/
    sub_73C778(&StringLiteral_Connecting_to_, v107); /*0x835704*/
    sub_73C778(&StringLiteral_username_lower, v108); /*0x835710*/
    sub_73C778(&StringLiteral__s_World, v109); /*0x83571c*/
    sub_73C778(&StringLiteral__, v110); /*0x835728*/
    sub_73C778(&StringLiteral_username_punctuated, v111); /*0x835734*/
    sub_73C778(&StringLiteral___color__sent_you_a_friend_reque, v112); /*0x835740*/
    sub_73C778(&StringLiteral_username, v113); /*0x83574c*/
    sub_73C778(&StringLiteral__went_to_the_Main_Menu, v114); /*0x835758*/
    sub_73C778(&StringLiteral_Report_submitted_u000AWe_will_review, v115); /*0x835764*/
    sub_73C778(&StringLiteral_UPDATE_AVAILABLEu000A_color__26ccff_, v116); /*0x835770*/
    sub_73C778(&StringLiteral_type, v117); /*0x83577c*/
    sub_73C778(&StringLiteral_Player_is_joining, v118); /*0x835788*/
    sub_73C778(&StringLiteral_action, v119); /*0x835794*/
    sub_73C778(&StringLiteral__color__00ff00_, v120); /*0x8357a0*/
    sub_73C778(&StringLiteral__is_no_longer_online, v121); /*0x8357ac*/
    sub_73C778(&StringLiteral__color__bbbbbb_Username_invalid_, v122); /*0x8357b8*/
    this = (FriendServerReceiver *)sub_73C778(&TypeInfo::chat_log, v123); /*0x8357c4*/
    byte_27E6BC5 = 1; /*0x8357cc*/
  }
  v457 = receiver; /*0x8357d0*/
  v466.m_Handle = 0; /*0x8357d4*/
  v465.m_value = 0; /*0x8357d8*/
  v464.m_value = 0; /*0x8357dc*/
  result._dateData = 0; /*0x8357e4*/
  memset(&v463, 0, sizeof(v463)); /*0x8357e4*/
  v461.m_value = 0; /*0x8357e8*/
  last_online._dateData = 0; /*0x8357ec*/
  if ( !pkt ) /*0x8357f0*/
    goto LABEL_639; /*0x8357f0*/
  incominga = pkt; /*0x8357fc*/
  opcode = Packet::GetByte(pkt, nullptr); /*0x835800*/
  method = (MethodInfo *)&TypeInfo::ToPing; /*0x835898*/
  incoming = (Packet *)&TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>; /*0x8358a0*/
  switch ( opcode ) /*0x835908*/
  {
    case 6u: /*0x835908*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor )// // case 0x06: UPDATE_AVAILABLE - shows update notification on connecting screen /*0x835920*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x835928*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x835934*/
      name = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x835940*/
      this = (FriendServerReceiver *)System::String::op_Equality(name, (String *)"Game", nullptr); /*0x835954*/
      if ( ((unsigned __int8)this & 1) == 0 ) /*0x835968*/
        goto LABEL_250; /*0x835968*/
      Instance = TypeInfo::WindowControl->static_fields->Instance; /*0x835974*/
      if ( !Instance ) /*0x835978*/
        goto LABEL_639; /*0x835978*/
      if ( Instance->curr_miniwindow != 14 ) /*0x835984*/
        goto LABEL_250; /*0x835984*/
      if ( !byte_27E6BD4 ) /*0x83598c*/
      {
        this = (FriendServerReceiver *)sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x835998*/
        byte_27E6BD4 = 1; /*0x8359a4*/
      }
      v128 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x8359b0*/
      if ( !v128 ) /*0x8359b4*/
        goto LABEL_639; /*0x8359b4*/
      if ( v128->curr_screen != 1 ) /*0x8359c0*/
        goto LABEL_250; /*0x8359c0*/
      if ( !TypeInfo::FriendServerInterface->static_fields->Instance ) /*0x8359cc*/
        goto LABEL_639; /*0x8359cc*/
      v129 = (String **)&StringLiteral_UPDATE_AVAILABLEu000A_color__26ccff_; /*0x8359d4*/
      v130 = 1; /*0x8359d8*/
      goto LABEL_249; /*0x8359dc*/
    case 7u: /*0x835908*/
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::MathProblem);// // case 0x07: MATH_CHALLENGE - unpack and solve MathProblem, send solution /*0x83698c*/
      if ( !this ) /*0x836990*/
        goto LABEL_639; /*0x836990*/
      v244 = this; /*0x836998*/
      MathProblem::MathProblem((MathProblem *)this, nullptr); /*0x83699c*/
      MathProblem::Unpack((MathProblem *)v244, pkt, nullptr); /*0x8369ac*/
      v245 = MathProblem::Solve((MathProblem *)v244, nullptr); /*0x8369c0*/
      if ( !byte_27E6BD5 ) /*0x8369c4*/
      {
        sub_73C778(&TypeInfo::FriendServerSender, incoming); /*0x8369d0*/
        byte_27E6BD5 = 1; /*0x8369d8*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x8369e4*/
      if ( !this ) /*0x8369e8*/
        goto LABEL_639; /*0x8369e8*/
      FriendServerSender::SendMathSolution((FriendServerSender *)this, v245, nullptr); /*0x8369f4*/
      return; /*0x8369f8*/
    case 8u: /*0x835908*/
      this = (FriendServerReceiver *)TypeInfo::PlayerData->static_fields->Instance;// // case 0x08: SIGNAL_INTENT_REQ - server requesting login intent (has username?) /*0x836588*/
      if ( !this ) /*0x83658c*/
        goto LABEL_639; /*0x83658c*/
      GlobalString = PlayerData::GetGlobalString((PlayerData *)this, (String *)"username_lower", nullptr); /*0x8365a0*/
      v212 = Startup::StringNullOrEmpty(GlobalString, nullptr); /*0x8365b4*/
      if ( !byte_27E6BD5 ) /*0x8365b8*/
      {
        sub_73C778(&TypeInfo::FriendServerSender, incoming); /*0x8365c8*/
        byte_27E6BD5 = 1; /*0x8365d0*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x8365dc*/
      if ( !this ) /*0x8365e0*/
        goto LABEL_639; /*0x8365e0*/
      if ( v212 ) /*0x8365e4*/
        v213 = 2; /*0x8365e8*/
      else
        v213 = 1; /*0x837cd0*/
      FriendServerSender::SignalIntent((FriendServerSender *)this, v213, nullptr); /*0x837cd8*/
      return; /*0x837cdc*/
    case 9u: /*0x835908*/
      Byte = Packet::GetByte(pkt, nullptr); // // case 0x09: LOGIN_RESPONSE - result of login attempt (1=ok, 2=need register) /*0x836d74*/
      if ( Byte == 2 ) /*0x836d7c*/
      {
        if ( !byte_27E6BD3 ) /*0x838ea4*/
        {
          sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x838eb0*/
          byte_27E6BD3 = 1; /*0x838eb8*/
        }
        v246 = TypeInfo::FriendServerConnector; /*0x838ebc*/
        if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x838ec0*/
        {
LABEL_585:
          j_il2cpp_runtime_class_init_0(v246); /*0x838ec8*/
          v246 = TypeInfo::FriendServerConnector; /*0x838ecc*/
        }
LABEL_586:
        this = (FriendServerReceiver *)v246->static_fields->Instance; /*0x838ed0*/
        if ( !this ) /*0x838ed8*/
          goto LABEL_639; /*0x838ed8*/
        FriendServerConnector::TryGotoRegisterScreen((FriendServerConnector *)this, (MethodInfo *)incoming); /*0x838edc*/
      }
      else if ( Byte == 1 ) /*0x836d84*/
      {
        if ( !byte_27E6BD5 ) /*0x836d90*/
        {
          sub_73C778(&TypeInfo::FriendServerSender, incoming); /*0x836d9c*/
          byte_27E6BD5 = 1; /*0x836da8*/
        }
        v268 = TypeInfo::FriendServerSender; /*0x836dac*/
LABEL_216:
        this = (FriendServerReceiver *)v268->static_fields->Instance; /*0x836db0*/
        if ( this ) /*0x836db8*/
        {
          FriendServerSender::SendAttemptLogin((FriendServerSender *)this, nullptr); /*0x836dc0*/
          return; /*0x836dc4*/
        }
        goto LABEL_639; /*0x836db8*/
      }
      return; /*0x836d84*/
    case 0xAu: /*0x835908*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor )// // case 0x0A: REGISTER_RESULT - result of username registration (1=success, 2=taken, 3=bad, 4=invalid chars) /*0x836de0*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x836df8*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x836e04*/
      v269 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x836e10*/
      this = (FriendServerReceiver *)System::String::op_Equality(v269, (String *)"Game", nullptr); /*0x836e24*/
      if ( ((unsigned __int8)this & 1) != 0 ) /*0x836e28*/
      {
        v270 = TypeInfo::WindowControl->static_fields->Instance; /*0x836e34*/
        if ( !v270 ) /*0x836e38*/
          goto LABEL_639; /*0x836e38*/
        if ( v270->curr_miniwindow == 14 ) /*0x836e4c*/
        {
          if ( !byte_27E6BD4 ) /*0x836e58*/
          {
            this = (FriendServerReceiver *)sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x836e64*/
            byte_27E6BD4 = 1; /*0x836e78*/
          }
          v271 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x836e8c*/
          if ( !v271 ) /*0x836e90*/
            goto LABEL_639; /*0x836e90*/
          if ( v271->curr_screen == 3 ) /*0x836e9c*/
          {
            v272 = &StringLiteral__color__bbbbbb_Username_unavaila; /*0x836ed4*/
            switch ( Packet::GetByte(pkt, nullptr) ) /*0x836ed8*/
            {
              case 1u: /*0x836ed8*/
                String = Packet::GetString(pkt, nullptr); /*0x836efc*/
                v274 = Packet::GetString(incominga, nullptr); /*0x836f0c*/
                v275 = Packet::GetString(incominga, nullptr); /*0x836f34*/
                v276 = TypeInfo::PopupControl->static_fields->Instance; /*0x836f38*/
                this = (FriendServerReceiver *)System::String::Concat( /*0x836f40*/
                                                 (String *)"<color=#bbbbbb>Success!</color>\n"
                                                           "Your username is now <color=#00ff00>",
                                                 v274,
                                                 (String *)"</color>",
                                                 nullptr);
                if ( !v276 ) /*0x836f44*/
                  goto LABEL_639; /*0x836f44*/
                PopupControl::ShowMessage(v276, (String *)this, PopupControl_context__Enum_message, nullptr); /*0x836f58*/
                this = (FriendServerReceiver *)TypeInfo::PlayerData->static_fields->Instance; /*0x836f64*/
                if ( !this ) /*0x836f68*/
                  goto LABEL_639; /*0x836f68*/
                PlayerData::SetGlobalString((PlayerData *)this, (String *)"username_lower", String, nullptr); /*0x836f78*/
                this = (FriendServerReceiver *)TypeInfo::PlayerData->static_fields->Instance; /*0x836f84*/
                if ( !this ) /*0x836f88*/
                  goto LABEL_639; /*0x836f88*/
                PlayerData::SetGlobalString((PlayerData *)this, (String *)"username_punctuated", v274, nullptr); /*0x836f98*/
                this = (FriendServerReceiver *)TypeInfo::PlayerData->static_fields->Instance; /*0x836fac*/
                if ( !this ) /*0x836fb4*/
                  goto LABEL_639; /*0x836fb4*/
                PlayerData::SetGlobalString((PlayerData *)this, (String *)"rand_code", v275, nullptr); /*0x836fcc*/
                if ( !byte_27E6BD4 ) /*0x836fd4*/
                {
                  sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x836fe0*/
                  byte_27E6BD4 = 1; /*0x836fe8*/
                }
                this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x836ff4*/
                if ( !this ) /*0x836ff8*/
                  goto LABEL_639; /*0x836ff8*/
                FriendServerInterface::ChangeFriendScreen( /*0x837004*/
                  (FriendServerInterface *)this,
                  FriendServerInterface_friend_window_screen__Enum_connecting_screen,
                  method);
                if ( !byte_27E6BD5 ) /*0x83700c*/
                {
                  sub_73C778(&TypeInfo::FriendServerSender, incoming); /*0x837018*/
                  byte_27E6BD5 = 1; /*0x83701c*/
                }
                v268 = TypeInfo::FriendServerSender; /*0x837020*/
                goto LABEL_216; /*0x837024*/
              case 2u: /*0x836ed8*/
                v453 = (String **)&StringLiteral___is_already_taken__Please_try_a; /*0x8391b8*/
                goto LABEL_629; /*0x8391b8*/
              case 3u: /*0x836ed8*/
                v272 = &StringLiteral__color__ff0000_WARNING__color_u000A_; /*0x83919c*/
                v453 = (String **)&StringLiteral___contains_an_inappropriate_word; /*0x8391a0*/
                goto LABEL_629; /*0x8391a4*/
              case 4u: /*0x836ed8*/
                v453 = (String **)&StringLiteral___contains_letters_that_are_not_; /*0x8391ac*/
LABEL_629:
                v454 = Packet::GetString(pkt, nullptr); /*0x8391bc*/
                v455 = (String *)*v272; /*0x8391dc*/
                v456 = TypeInfo::PopupControl->static_fields->Instance; /*0x8391e0*/
                this = (FriendServerReceiver *)System::String::Concat(v455, v454, *v453, nullptr); /*0x8391e8*/
                if ( !v456 ) /*0x8391ec*/
                  goto LABEL_639; /*0x8391ec*/
                PopupControl::ShowMessage(v456, (String *)this, PopupControl_context__Enum_message, nullptr); /*0x839204*/
                if ( !byte_27E6BD4 ) /*0x839218*/
                {
                  sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x839224*/
                  byte_27E6BD4 = 1; /*0x839228*/
                }
                this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x839234*/
                if ( !this ) /*0x839238*/
                  goto LABEL_639; /*0x839238*/
                v349 = FriendServerInterface_friend_window_screen__Enum_register_screen; /*0x83923c*/
                break; /*0x83923c*/
              default:
                return;
            }
            goto LABEL_634; /*0x83923c*/
          }
        }
        if ( !byte_27E6BD3 ) /*0x8382d0*/
        {
LABEL_457:
          sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x8382d4*/
          byte_27E6BD3 = 1; /*0x8382ec*/
        }
LABEL_458:
        this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x8382f0*/
        if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x8382f4*/
          goto LABEL_459; /*0x8382f8*/
      }
      else
      {
        if ( !byte_27E6BD3 ) /*0x837ce8*/
        {
          sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x837cf4*/
          byte_27E6BD3 = 1; /*0x837d00*/
        }
        this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x837d04*/
        if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x837d08*/
        {
LABEL_459:
          j_il2cpp_runtime_class_init_0(this); /*0x838300*/
          this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x838304*/
        }
      }
      v369 = **((_QWORD **)this + 23); /*0x838308*/
      if ( !v369 ) /*0x838310*/
        goto LABEL_639; /*0x838310*/
      v370 = *(_QWORD *)(v369 + 32); /*0x838314*/
      if ( !v370 ) /*0x838318*/
        goto LABEL_639; /*0x838318*/
      *(_DWORD *)(v370 + 80) = 4; /*0x838320*/
      return; /*0x838324*/
    case 0xBu: /*0x835908*/
      v224 = pkt; // // case 0x0B: LOGIN_SUCCESS - full friend list sync, trophies, pings, gem count /*0x83675c*/
      v225 = Packet::GetByte(pkt, nullptr); /*0x836774*/
      if ( v225 == 1 ) /*0x83677c*/
      {
        if ( !byte_27E6BD3 ) /*0x8384fc*/
        {
          sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x838508*/
          byte_27E6BD3 = 1; /*0x83851c*/
        }
        this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x838520*/
        v226 = receiver; /*0x838524*/
        if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x838528*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x838530*/
          this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x83853c*/
        }
        v381 = **((_QWORD **)this + 23); /*0x838544*/
        if ( !v381 ) /*0x838548*/
          goto LABEL_639; /*0x838548*/
        *(_BYTE *)(v381 + 24) = 1; /*0x838550*/
        if ( !byte_27E6BD3 ) /*0x83855c*/
        {
          sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x838564*/
          this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x838570*/
          byte_27E6BD3 = 1; /*0x838578*/
        }
        if ( !*((_DWORD *)this + 56) ) /*0x83857c*/
        {
          j_il2cpp_runtime_class_init_0(this); /*0x838584*/
          this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x838590*/
        }
        this = **((FriendServerReceiver ***)this + 23); /*0x83859c*/
        if ( !this ) /*0x8385a0*/
          goto LABEL_639; /*0x8385a0*/
        FriendServerConnector::StartPinging((FriendServerConnector *)this, (MethodInfo *)incoming); /*0x8385a4*/
      }
      else
      {
        if ( v225 != 2 ) /*0x836790*/
          return; /*0x836790*/
        if ( !byte_27E6BD3 ) /*0x836798*/
        {
          sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x8367a4*/
          byte_27E6BD3 = 1; /*0x8367b8*/
        }
        this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x8367bc*/
        v226 = receiver; /*0x8367c0*/
        v224 = pkt; /*0x8367c0*/
        if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x8367c8*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x8367d0*/
          this = (FriendServerReceiver *)TypeInfo::FriendServerConnector; /*0x8367dc*/
        }
        v227 = **((_QWORD **)this + 23); /*0x8367e4*/
        if ( !v227 ) /*0x8367e8*/
          goto LABEL_639; /*0x8367e8*/
        *(_BYTE *)(v227 + 24) = 1; /*0x8367f0*/
      }
      friends = v226->friends; /*0x8385a8*/
      if ( !friends ) /*0x8385ac*/
        goto LABEL_639; /*0x8385ac*/
      size = friends->_size; /*0x8385b0*/
      v384 = friends->_version + 1; /*0x8385b4*/
      friends->_size = 0; /*0x8385bc*/
      friends->_version = v384; /*0x8385bc*/
      if ( size >= 1 ) /*0x8385c0*/
        System::Array::Clear((Array *)friends->_items, 0, size, nullptr); /*0x8385d0*/
      Short = Packet::GetShort(v224, nullptr); /*0x8385e0*/
      if ( Short >= 1 ) /*0x8385e8*/
      {
        do /*0x8385f8*/
        {
          v386 = Packet::GetString(v224, nullptr); /*0x8385f8*/
          v387 = Packet::GetString(v224, nullptr); /*0x838608*/
          v388 = Packet::GetByte(v224, nullptr); /*0x83861c*/
          this = (FriendServerReceiver *)sub_73C88C(TypeInfo::Friend); /*0x838624*/
          if ( !this ) /*0x838628*/
            goto LABEL_639; /*0x838668*/
          v389 = (Friend *)this; /*0x838644*/
          Friend::Friend((Friend *)this, v386, (Friend_status__Enum)(v388 == 1), v387, nullptr); /*0x838648*/
          this = (FriendServerReceiver *)v226->friends; /*0x83864c*/
          if ( !this ) /*0x838650*/
            goto LABEL_639; /*0x838668*/
          m_CachedPtr = this->m_CachedPtr; /*0x838658*/
          v391 = MethodInfo::System::Collections::Generic::List<Friend>::Add; /*0x83865c*/
          ++HIDWORD(this->recently_seen_players); /*0x838664*/
          if ( !m_CachedPtr ) /*0x838668*/
            goto LABEL_639; /*0x838668*/
          recently_seen_players_low = SLODWORD(this->recently_seen_players); /*0x83866c*/
          if ( (unsigned int)recently_seen_players_low >= m_CachedPtr[6] ) /*0x838678*/
          {
            v394 = (FriendServerReceiver *)(*((__int64 (**)(void))v391->klass->rgctx_data[11].rgctxDataDummy + 1))(); /*0x8386b0*/
          }
          else
          {
            v393 = (char *)&m_CachedPtr[2 * recently_seen_players_low]; /*0x838680*/
            LODWORD(this->recently_seen_players) = recently_seen_players_low + 1; /*0x838684*/
            *((_QWORD *)v393 + 4) = v389; /*0x838688*/
            v394 = (FriendServerReceiver *)sub_73C72C(v393 + 32); /*0x838694*/
          }
          if ( v388 == 1 ) /*0x8386bc*/
          {
            FriendServerReceiver::UnpackWorldString(v394, v389, v224, v395); /*0x8386c8*/
          }
          else if ( Packet::GetByte(v224, nullptr) == 1 ) /*0x8386e4*/
          {
            v396 = Packet::GetString(v224, nullptr); /*0x8386f8*/
            if ( !TypeInfo::System::Globalization::CultureInfo->_1.cctor_finished_or_no_cctor ) /*0x8386fc*/
              j_il2cpp_runtime_class_init_0(TypeInfo::System::Globalization::CultureInfo); /*0x838708*/
            InvariantCulture = (IFormatProvider *)System::Globalization::CultureInfo::get_InvariantCulture(nullptr); /*0x83871c*/
            if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x838724*/
              j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x838730*/
            if ( System::DateTime::TryParseExact( /*0x838754*/
                   v396,
                   (String *)"o",
                   InvariantCulture,
                   DateTimeStyles__Enum_RoundtripKind,
                   &last_online,
                   nullptr) )
            {
              Friend::set_last_online(v389, last_online, nullptr); /*0x83876c*/
            }
          }
        }
        while ( --Short ); /*0x8385f8*/
      }
      v398 = Packet::GetShort(v224, nullptr); /*0x838778*/
      if ( v398 >= 1 ) /*0x83878c*/
      {
        do /*0x83879c*/
        {
          v399 = Packet::GetString(v224, nullptr); /*0x83879c*/
          v400 = Packet::GetString(v224, nullptr); /*0x8387b0*/
          this = (FriendServerReceiver *)sub_73C88C(TypeInfo::Friend); /*0x8387b8*/
          if ( !this ) /*0x8387bc*/
            goto LABEL_639; /*0x8387f4*/
          v401 = this; /*0x8387d0*/
          Friend::Friend((Friend *)this, v399, Friend_status__Enum_req_sent, v400, nullptr); /*0x8387d4*/
          this = (FriendServerReceiver *)v226->friends; /*0x8387d8*/
          if ( !this ) /*0x8387dc*/
            goto LABEL_639; /*0x8387f4*/
          v402 = this->m_CachedPtr; /*0x8387e4*/
          v403 = MethodInfo::System::Collections::Generic::List<Friend>::Add; /*0x8387e8*/
          ++HIDWORD(this->recently_seen_players); /*0x8387f0*/
          if ( !v402 ) /*0x8387f4*/
            goto LABEL_639; /*0x8387f4*/
          v404 = SLODWORD(this->recently_seen_players); /*0x8387f8*/
          if ( (unsigned int)v404 >= v402[6] ) /*0x838804*/
          {
            (*((void (**)(void))v403->klass->rgctx_data[11].rgctxDataDummy + 1))(); /*0x83883c*/
          }
          else
          {
            v405 = (char *)&v402[2 * v404]; /*0x83880c*/
            LODWORD(this->recently_seen_players) = v404 + 1; /*0x838810*/
            *((_QWORD *)v405 + 4) = v401; /*0x838814*/
            sub_73C72C(v405 + 32); /*0x838820*/
          }
        }
        while ( --v398 ); /*0x83879c*/
      }
      v406 = Packet::GetShort(v224, nullptr); /*0x838848*/
      if ( v406 >= 1 ) /*0x83885c*/
      {
        do /*0x83886c*/
        {
          v407 = Packet::GetString(v224, nullptr); /*0x83886c*/
          v408 = Packet::GetString(v224, nullptr); /*0x838880*/
          this = (FriendServerReceiver *)sub_73C88C(TypeInfo::Friend); /*0x838888*/
          if ( !this ) /*0x83888c*/
            goto LABEL_639; /*0x8388c4*/
          v409 = this; /*0x8388a0*/
          Friend::Friend((Friend *)this, v407, Friend_status__Enum_req_received, v408, nullptr); /*0x8388a4*/
          this = (FriendServerReceiver *)v226->friends; /*0x8388a8*/
          if ( !this ) /*0x8388ac*/
            goto LABEL_639; /*0x8388c4*/
          v410 = this->m_CachedPtr; /*0x8388b4*/
          v411 = MethodInfo::System::Collections::Generic::List<Friend>::Add; /*0x8388b8*/
          ++HIDWORD(this->recently_seen_players); /*0x8388c0*/
          if ( !v410 ) /*0x8388c4*/
            goto LABEL_639; /*0x8388c4*/
          v412 = SLODWORD(this->recently_seen_players); /*0x8388c8*/
          if ( (unsigned int)v412 >= v410[6] ) /*0x8388d4*/
          {
            (*((void (**)(void))v411->klass->rgctx_data[11].rgctxDataDummy + 1))(); /*0x83890c*/
          }
          else
          {
            v413 = (char *)&v410[2 * v412]; /*0x8388dc*/
            LODWORD(this->recently_seen_players) = v412 + 1; /*0x8388e0*/
            *((_QWORD *)v413 + 4) = v409; /*0x8388e4*/
            sub_73C72C(v413 + 32); /*0x8388f0*/
          }
        }
        while ( --v406 ); /*0x83886c*/
      }
      v414 = Packet::GetShort(v224, nullptr); /*0x838918*/
      if ( v414 >= 1 ) /*0x83892c*/
      {
        this = (FriendServerReceiver *)sub_73C88C(TypeInfo::System::Collections::Generic::List<ToPing>); /*0x83893c*/
        if ( !this ) /*0x838940*/
          goto LABEL_639; /*0x838940*/
        v415 = (List_1_ToPing_ *)this; /*0x838954*/
        System::Collections::Generic::List<System::Object>::List( /*0x838964*/
          (List_1_System_Object_ *)this,
          MethodInfo::System::Collections::Generic::List<ToPing>::List);
        do /*0x838a34*/
        {
          v416 = Packet::GetString(v224, nullptr); /*0x838974*/
          v417 = Packet::GetString(v224, nullptr); /*0x838984*/
          v418 = Packet::GetShort(v224, nullptr); /*0x83899c*/
          this = (FriendServerReceiver *)sub_73C88C(TypeInfo::ToPing); /*0x8389a8*/
          if ( !this ) /*0x8389ac*/
            goto LABEL_639; /*0x8389ac*/
          v419 = this; /*0x8389c0*/
          ToPing::ToPing((ToPing *)this, v416, v417, v418, nullptr); /*0x8389c4*/
          items = v415->_items; /*0x8389d0*/
          v421 = MethodInfo::System::Collections::Generic::List<ToPing>::Add; /*0x8389dc*/
          ++v415->_version; /*0x8389e0*/
          if ( !items ) /*0x8389e4*/
            goto LABEL_639; /*0x8389e4*/
          v422 = v415->_size; /*0x8389e8*/
          if ( (unsigned int)v422 >= items->max_length.size ) /*0x8389f4*/
          {
            (*((void (__fastcall **)(List_1_ToPing_ *, FriendServerReceiver *))v421->klass->rgctx_data[11].rgctxDataDummy /*0x838a2c*/
             + 1))(
              v415,
              v419);
          }
          else
          {
            v423 = &items->klass + v422; /*0x8389fc*/
            v415->_size = v422 + 1; /*0x838a00*/
            v423[4] = (ToPing__Array__Class *)v419; /*0x838a04*/
            sub_73C72C(v423 + 4); /*0x838a0c*/
          }
          --v414; /*0x838a30*/
        }
        while ( v414 ); /*0x838a34*/
        v424 = TypeInfo::FriendServerReceiver::__c; /*0x838a38*/
        if ( !TypeInfo::FriendServerReceiver::__c->_1.cctor_finished_or_no_cctor ) /*0x838a44*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerReceiver::__c); /*0x838a54*/
          v424 = TypeInfo::FriendServerReceiver::__c; /*0x838a68*/
        }
        _9__26_1 = (FriendServerReceiver *)v424->static_fields->__9__26_1; /*0x838a70*/
        if ( !_9__26_1 ) /*0x838a74*/
        {
          if ( !v424->_1.cctor_finished_or_no_cctor ) /*0x838a78*/
          {
            j_il2cpp_runtime_class_init_0(v424); /*0x838a80*/
            v424 = TypeInfo::FriendServerReceiver::__c; /*0x838a8c*/
          }
          v426 = (Object *)v424->static_fields->__9; /*0x838a98*/
          this = (FriendServerReceiver *)sub_73C88C(TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>); /*0x838a9c*/
          if ( !this ) /*0x838aa0*/
            goto LABEL_639; /*0x838aa0*/
          _9__26_1 = this; /*0x838ab0*/
          System::Action<System::Object>::Action( /*0x838ab4*/
            (Action_1_Object_ *)this,
            v426,
            MethodInfo::FriendServerReceiver::__c::_OnReceive_b__26_1,
            nullptr);
          static_fields = TypeInfo::FriendServerReceiver::__c->static_fields; /*0x838ac0*/
          static_fields->__9__26_1 = (Action_1_System_Collections_Generic_Dictionary_2_ *)_9__26_1; /*0x838ac4*/
          sub_73C72C(&static_fields->__9__26_1); /*0x838ac8*/
        }
        this = (FriendServerReceiver *)TypeInfo::PingController->static_fields->Instance; /*0x838adc*/
        if ( !this ) /*0x838ae0*/
          goto LABEL_639; /*0x838ae0*/
        PingController::PingMany( /*0x838af4*/
          (PingController *)this,
          v415,
          (Action_1_System_Collections_Generic_Dictionary_2_ *)_9__26_1,
          (MonoBehaviour *)v226,
          nullptr);
      }
      v226->give_gems_on_open = Packet::GetShort(v224, nullptr); /*0x838b10*/
      v226->show_warning_on_open = Packet::GetByte(v224, nullptr); /*0x838b18*/
      this = (FriendServerReceiver *)Packet::GetShort(v224, nullptr); /*0x838b24*/
      v461.m_value = (__int16)this; /*0x838b2c*/
      trophies = v226->trophies; /*0x838b30*/
      if ( !trophies ) /*0x838b34*/
        goto LABEL_639; /*0x838b34*/
      v429 = trophies->_size; /*0x838b38*/
      v430 = trophies->_version + 1; /*0x838b3c*/
      trophies->_size = 0; /*0x838b44*/
      trophies->_version = v430; /*0x838b44*/
      if ( v429 >= 1 ) /*0x838b48*/
        System::Array::Clear((Array *)trophies->_items, 0, v429, nullptr); /*0x838b58*/
      v431 = Packet::GetShort(v224, nullptr); /*0x838b68*/
      if ( v431 >= 1 ) /*0x838b70*/
      {
        do /*0x838b80*/
        {
          v432 = Packet::GetString(v224, nullptr); /*0x838b80*/
          v433 = Packet::GetString(v224, nullptr); /*0x838b90*/
          v434 = Packet::GetString(v224, nullptr); /*0x838ba0*/
          v435 = Packet::GetString(v224, nullptr); /*0x838bb0*/
          v436 = Packet::GetString(v224, nullptr); /*0x838bc0*/
          v437 = Packet::GetString(v224, nullptr); /*0x838bd8*/
          this = (FriendServerReceiver *)sub_73C88C(TypeInfo::Trophy); /*0x838be4*/
          if ( !this ) /*0x838be8*/
            goto LABEL_639; /*0x838c3c*/
          v438 = this; /*0x838c08*/
          Trophy::Trophy((Trophy *)this, v432, v433, v434, v435, v436, v437, nullptr); /*0x838c0c*/
          this = (FriendServerReceiver *)v457->trophies; /*0x838c14*/
          if ( !this ) /*0x838c18*/
            goto LABEL_639; /*0x838c3c*/
          v439 = this->m_CachedPtr; /*0x838c24*/
          v224 = incominga; /*0x838c2c*/
          v440 = MethodInfo::System::Collections::Generic::List<Trophy>::Add; /*0x838c34*/
          ++HIDWORD(this->recently_seen_players); /*0x838c38*/
          if ( !v439 ) /*0x838c3c*/
            goto LABEL_639; /*0x838c3c*/
          v441 = SLODWORD(this->recently_seen_players); /*0x838c40*/
          if ( (unsigned int)v441 >= v439[6] ) /*0x838c4c*/
          {
            (*((void (**)(void))v440->klass->rgctx_data[11].rgctxDataDummy + 1))(); /*0x838c84*/
          }
          else
          {
            v442 = (char *)&v439[2 * v441]; /*0x838c54*/
            LODWORD(this->recently_seen_players) = v441 + 1; /*0x838c58*/
            *((_QWORD *)v442 + 4) = v438; /*0x838c5c*/
            sub_73C72C(v442 + 32); /*0x838c68*/
          }
        }
        while ( --v431 ); /*0x838b80*/
      }
      v443 = System::Int32::ToString(&v461, nullptr); /*0x838c90*/
      v444 = (Object *)System::String::Concat( /*0x838cd0*/
                         (String *)"Login Succeed! (",
                         v443,
                         (String *)" incorrect logins)",
                         nullptr);
      if ( !TypeInfo::UnityEngine::Debug->_1.cctor_finished_or_no_cctor ) /*0x838cd4*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Debug); /*0x838ce0*/
      UnityEngine::Debug::Log(v444, nullptr); /*0x838cec*/
      if ( !byte_27E6BD3 ) /*0x838d00*/
      {
        sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x838d10*/
        byte_27E6BD3 = 1; /*0x838d18*/
      }
      v445 = TypeInfo::FriendServerConnector; /*0x838d24*/
      if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x838d28*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x838d34*/
        v445 = TypeInfo::FriendServerConnector; /*0x838d38*/
      }
      this = (FriendServerReceiver *)v445->static_fields->Instance; /*0x838d40*/
      if ( !this ) /*0x838d44*/
        goto LABEL_639; /*0x838d44*/
      FriendServerConnector::CheckIfAutoLoginShouldBeDisabled((FriendServerConnector *)this, (MethodInfo *)incoming); /*0x838d48*/
      this = (FriendServerReceiver *)TypeInfo::PlayerData->static_fields->Instance; /*0x838d5c*/
      if ( !this ) /*0x838d60*/
        goto LABEL_639; /*0x838d60*/
      this = (FriendServerReceiver *)PlayerData::GetGlobalShort( /*0x838d74*/
                                       (PlayerData *)this,
                                       (String *)"n_wasted_autologins",
                                       nullptr);
      if ( !TypeInfo::PlayerData->static_fields->Instance ) /*0x838d80*/
        goto LABEL_639; /*0x838d84*/
      PlayerData::SetGlobalShort( /*0x838d9c*/
        TypeInfo::PlayerData->static_fields->Instance,
        (String *)"n_wasted_autologins",
        (__int16)this + 1,
        nullptr);
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x838dac*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x838db4*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x838dc0*/
      v446 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x838dcc*/
      this = (FriendServerReceiver *)System::String::op_Equality(v446, (String *)"Game", nullptr); /*0x838de0*/
      if ( ((unsigned __int8)this & 1) != 0 ) /*0x838df0*/
      {
        v447 = TypeInfo::WindowControl->static_fields->Instance; /*0x838dfc*/
        if ( !v447 ) /*0x838e00*/
          goto LABEL_639; /*0x838e00*/
        if ( v447->curr_miniwindow == 14 ) /*0x838e18*/
        {
          if ( !byte_27E6BD4 ) /*0x838e20*/
          {
            sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x838e2c*/
            byte_27E6BD4 = 1; /*0x838e34*/
          }
          this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x838e40*/
          if ( !this ) /*0x838e44*/
            goto LABEL_639; /*0x838e44*/
          FriendServerInterface::ChangeFriendScreen( /*0x838e4c*/
            (FriendServerInterface *)this,
            FriendServerInterface_friend_window_screen__Enum_friend_list,
            method);
        }
        if ( !byte_27E6BD5 ) /*0x838e60*/
        {
          sub_73C778(&TypeInfo::FriendServerSender, incoming); /*0x838e70*/
          byte_27E6BD5 = 1; /*0x838e80*/
        }
        this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x838e8c*/
        if ( !this ) /*0x838e90*/
          goto LABEL_639; /*0x838e90*/
        FriendServerSender::UpdateWorldString((FriendServerSender *)this, nullptr); /*0x838e98*/
      }
      return; /*0x838e9c*/
    case 0xCu: /*0x835908*/
      if ( !byte_27E6BD3 ) // // case 0x0C: REDIRECT_TO_REGISTER - server tells client to go to register screen /*0x836a00*/
      {
        sub_73C778( /*0x836a14*/
          &TypeInfo::FriendServerConnector,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD3 = 1; /*0x836a20*/
      }
      v246 = TypeInfo::FriendServerConnector; /*0x836a24*/
      if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x836a28*/
        goto LABEL_585; /*0x836a2c*/
      goto LABEL_586; /*0x836a2c*/
    case 0xFu: /*0x835908*/
      if ( !byte_27E6BD3 ) // // case 0x0F: PING - server ping response, updates last_server_ping timestamp /*0x836a3c*/
      {
        sub_73C778( /*0x836a54*/
          &TypeInfo::FriendServerConnector,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD3 = 1; /*0x836a64*/
      }
      v247 = TypeInfo::FriendServerConnector; /*0x836a68*/
      if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x836a6c*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x836a7c*/
        v247 = TypeInfo::FriendServerConnector; /*0x836a80*/
      }
      v248 = v247->static_fields->Instance; /*0x836a94*/
      if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x836a90*/
        j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x836aa0*/
      this = (FriendServerReceiver *)System::DateTime::get_UtcNow(nullptr)._dateData; /*0x836aa8*/
      if ( !v248 ) /*0x836aac*/
        goto LABEL_639; /*0x836aac*/
      v248->last_server_ping._dateData = (uint64_t)this; /*0x836ab0*/
      return; /*0x836ab4*/
    case 0x10u: /*0x835908*/
      if ( !byte_27E6BD5 ) /*0x8371f4*/
      {
        sub_73C778( /*0x837214*/
          &TypeInfo::FriendServerSender,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD5 = 1; /*0x83722c*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x83723c*/
      if ( !this ) /*0x837240*/
        goto LABEL_639; /*0x837240*/
      FriendServerSender::EndTimeout((FriendServerSender *)this, nullptr); /*0x837254*/
      v287 = Packet::GetByte(pkt, nullptr); /*0x837264*/
      v288 = Packet::GetString(pkt, nullptr); /*0x837274*/
      if ( v287 ) /*0x837278*/
      {
        v289 = (String **)&StringLiteral__color__bbbbbb_Cannot_Add__color; /*0x8372a0*/
        switch ( v287 ) /*0x8372a4*/
        {
          case 1: /*0x8372a4*/
            v289 = (String **)&StringLiteral__color__bbbbbb_Username_invalid_; /*0x8372b0*/
            v290 = (String **)&StringLiteral___does_not_exist_; /*0x8372b4*/
            goto LABEL_613; /*0x8372b8*/
          case 2: /*0x8372a4*/
            v290 = (String **)&StringLiteral___is_already_your_friend_; /*0x839094*/
            goto LABEL_613; /*0x839098*/
          case 3: /*0x8372a4*/
            v289 = (String **)&StringLiteral__color__bbbbbb_Cannot_Add__color_0; /*0x839070*/
            v290 = (String **)&StringLiteral___30; /*0x839074*/
            goto LABEL_613; /*0x839078*/
          case 4: /*0x8372a4*/
            v290 = (String **)&StringLiteral___already_sent_you_a_request; /*0x839080*/
            goto LABEL_613; /*0x839084*/
          case 5: /*0x8372a4*/
            v450 = (Packet **)&StringLiteral__color__bbbbbb_Too_many_friends__0; /*0x839060*/
            goto LABEL_615; /*0x839064*/
          case 6: /*0x8372a4*/
            v289 = (String **)&StringLiteral__color__bbbbbb_Too_many_friends_; /*0x8390a4*/
            v290 = (String **)&StringLiteral___already_has_30_friends__which_; /*0x8390a8*/
LABEL_613:
            incoming = (Packet *)System::String::Concat(*v289, v288, *v290, nullptr); /*0x8390ac*/
            break; /*0x8390c4*/
          case 7: /*0x8372a4*/
            v450 = (Packet **)&StringLiteral__color__bbbbbb_Why__color_; /*0x8390cc*/
LABEL_615:
            incoming = *v450; /*0x8390d0*/
            break; /*0x8390d0*/
          default:
            incoming = (Packet *)""; /*0x839088*/
            break; /*0x83908c*/
        }
        this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x8390dc*/
        if ( !this ) /*0x8390e0*/
          goto LABEL_639; /*0x8390e0*/
        PopupControl::ShowMessage((PopupControl *)this, (String *)incoming, PopupControl_context__Enum_message, nullptr); /*0x8390ec*/
        if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x8390fc*/
          j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x839104*/
        v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x839110*/
        v451 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x83911c*/
        this = (FriendServerReceiver *)System::String::op_Equality(v451, (String *)"Game", nullptr); /*0x839130*/
        if ( ((unsigned __int8)this & 1) != 0 ) /*0x839134*/
        {
          v452 = TypeInfo::WindowControl->static_fields->Instance; /*0x839140*/
          if ( !v452 ) /*0x839144*/
            goto LABEL_639; /*0x839144*/
          if ( v452->curr_miniwindow == 14 ) /*0x839150*/
          {
            if ( !byte_27E6BD4 ) /*0x83915c*/
            {
              sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x839168*/
              byte_27E6BD4 = 1; /*0x839170*/
            }
            this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x839184*/
            if ( !this ) /*0x839188*/
              goto LABEL_639; /*0x839188*/
            v349 = FriendServerInterface_friend_window_screen__Enum_add_friend; /*0x83918c*/
LABEL_634:
            FriendServerInterface::ChangeFriendScreen((FriendServerInterface *)this, v349, method); /*0x839240*/
          }
        }
      }
      else
      {
        v371 = Packet::GetString(incominga, nullptr); /*0x83834c*/
        v372 = TypeInfo::PopupControl->static_fields->Instance; /*0x838360*/
        this = (FriendServerReceiver *)System::String::Concat( /*0x838368*/
                                         (String *)"Friend request sent to <color=#4dccff>",
                                         v288,
                                         (String *)"!</color>",
                                         nullptr);
        if ( !v372 ) /*0x83836c*/
          goto LABEL_639; /*0x83836c*/
        PopupControl::ShowMessage(v372, (String *)this, PopupControl_context__Enum_message, nullptr); /*0x838380*/
        v373 = receiver->friends; /*0x838388*/
        this = (FriendServerReceiver *)sub_73C88C(TypeInfo::Friend); /*0x83838c*/
        if ( !this ) /*0x838390*/
          goto LABEL_639; /*0x838390*/
        v374 = this; /*0x8383a4*/
        Friend::Friend((Friend *)this, v371, Friend_status__Enum_req_sent, v288, nullptr); /*0x8383a8*/
        if ( !v373 ) /*0x8383ac*/
          goto LABEL_639; /*0x8383ac*/
        v375 = v373->_items; /*0x8383b4*/
        v376 = MethodInfo::System::Collections::Generic::List<Friend>::Add; /*0x8383b8*/
        ++v373->_version; /*0x8383c0*/
        if ( !v375 ) /*0x8383c4*/
          goto LABEL_639; /*0x8383c4*/
        v377 = v373->_size; /*0x8383c8*/
        if ( (unsigned int)v377 >= v375->max_length.size ) /*0x8383d4*/
        {
          (*((void (__fastcall **)(List_1_Friend_ *, FriendServerReceiver *))v376->klass->rgctx_data[11].rgctxDataDummy /*0x838f8c*/
           + 1))(
            v373,
            v374);
        }
        else
        {
          v378 = (__int64)v375 + 8 * v377; /*0x8383dc*/
          v373->_size = v377 + 1; /*0x8383e0*/
          *(_QWORD *)(v378 + 32) = v374; /*0x8383e4*/
          sub_73C72C(v378 + 32); /*0x8383ec*/
        }
        if ( !byte_27E6BD3 ) /*0x838fa0*/
        {
          sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x838fac*/
          byte_27E6BD3 = 1; /*0x838fb8*/
        }
        v448 = TypeInfo::FriendServerConnector; /*0x838fbc*/
        if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x838fc0*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x838fcc*/
          v448 = TypeInfo::FriendServerConnector; /*0x838fd0*/
        }
        this = (FriendServerReceiver *)v448->static_fields->Instance; /*0x838fd8*/
        if ( !this ) /*0x838fdc*/
          goto LABEL_639; /*0x838fdc*/
        FriendServerConnector::CheckIfAutoLoginShouldBeDisabled((FriendServerConnector *)this, (MethodInfo *)incoming); /*0x838fe0*/
        if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x838ff0*/
          j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x838ff8*/
        v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x839004*/
        v449 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x839010*/
        this = (FriendServerReceiver *)System::String::op_Equality(v449, (String *)"Game", nullptr); /*0x839024*/
        if ( ((unsigned __int8)this & 1) != 0 ) /*0x839028*/
        {
          v207 = TypeInfo::WindowControl; /*0x83902c*/
LABEL_377:
          v348 = v207->static_fields->Instance; /*0x837c5c*/
          if ( !v348 ) /*0x837c64*/
            goto LABEL_639; /*0x837c64*/
          if ( v348->curr_miniwindow == 14 ) /*0x837c70*/
          {
LABEL_379:
            if ( !byte_27E6BD4 ) /*0x837c7c*/
            {
              sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x837c88*/
              byte_27E6BD4 = 1; /*0x837c90*/
            }
            this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x837ca4*/
            if ( !this ) /*0x837ca8*/
              goto LABEL_639; /*0x837ca8*/
LABEL_382:
            v349 = FriendServerInterface_friend_window_screen__Enum_friend_list; /*0x837cac*/
            goto LABEL_634; /*0x837cb0*/
          }
        }
      }
      return; // // case 0x10: ADD_FRIEND_RESULT - result of add-friend attempt (0=sent, 1-7=various errors)
    case 0x11u: /*0x835908*/
      v280 = Packet::GetString(pkt, nullptr); // // case 0x11: FRIEND_REQUEST_RECEIVED - someone sent you a friend request /*0x83714c*/
      v281 = Packet::GetString(incominga, nullptr); /*0x837160*/
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::Friend); /*0x837168*/
      if ( !this ) /*0x83716c*/
        goto LABEL_639; /*0x83716c*/
      v282 = (Friend *)this; /*0x837180*/
      Friend::Friend((Friend *)this, v280, Friend_status__Enum_req_received, v281, nullptr); /*0x837184*/
      this = (FriendServerReceiver *)v457->friends; /*0x83718c*/
      if ( !this ) /*0x837190*/
        goto LABEL_639; /*0x837190*/
      v283 = this->m_CachedPtr; /*0x837198*/
      v284 = MethodInfo::System::Collections::Generic::List<Friend>::Add; /*0x83719c*/
      ++HIDWORD(this->recently_seen_players); /*0x8371a4*/
      if ( !v283 ) /*0x8371a8*/
        goto LABEL_639; /*0x8371a8*/
      v285 = SLODWORD(this->recently_seen_players); /*0x8371ac*/
      if ( (unsigned int)v285 >= v283[6] ) /*0x8371b8*/
      {
        (*((void (**)(void))v284->klass->rgctx_data[11].rgctxDataDummy + 1))(); /*0x837d2c*/
      }
      else
      {
        v286 = (char *)&v283[2 * v285]; /*0x8371c0*/
        LODWORD(this->recently_seen_players) = v285 + 1; /*0x8371c4*/
        *((_QWORD *)v286 + 4) = v282; /*0x8371c8*/
        sub_73C72C(v286 + 32); /*0x8371d4*/
      }
      if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x837d34*/
        j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x837d3c*/
      v468._dateData = System::DateTime::get_UtcNow(nullptr)._dateData; /*0x837d44*/
      Friend::set_last_online(v282, v468, nullptr); /*0x837d54*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x837d5c*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x837d64*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x837d70*/
      v350 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x837d7c*/
      if ( !System::String::op_Equality(v350, (String *)"Game", nullptr) ) /*0x837d94*/
        return; /*0x837d94*/
      v239 = TypeInfo::GameplayGUIControl->static_fields->Instance; /*0x837db8*/
      this = (FriendServerReceiver *)System::String::Concat( /*0x837dc4*/
                                       (String *)"<color=#80d9ff>",
                                       v282->username_punctuated,
                                       (String *)"</color> sent you a friend request   ",
                                       nullptr);
      v351 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x837dd8*/
      if ( !v351 ) /*0x837ddc*/
        goto LABEL_639; /*0x837ddc*/
      icon_got_friend_req = v351->icon_got_friend_req; /*0x837de0*/
      goto LABEL_399; /*0x837de0*/
    case 0x12u: /*0x835908*/
      if ( !byte_27E6BD5 ) // // case 0x12: FRIEND_STATUS_UPDATE - friend online/offline status changed /*0x836108*/
      {
        sub_73C778( /*0x836128*/
          &TypeInfo::FriendServerSender,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD5 = 1; /*0x836140*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x836150*/
      if ( !this ) /*0x836154*/
        goto LABEL_639; /*0x836154*/
      FriendServerSender::EndTimeout((FriendServerSender *)this, nullptr); /*0x836168*/
      v184 = Packet::GetString(pkt, nullptr); /*0x836178*/
      v185 = Packet::GetByte(pkt, nullptr); /*0x836188*/
      this = (FriendServerReceiver *)FriendServerReceiver::GetFriendByUsername(receiver, v184, v186); /*0x836194*/
      if ( !this ) /*0x836198*/
        goto LABEL_639; /*0x836198*/
      v188 = (Friend *)this; /*0x8361a0*/
      if ( v185 == 1 ) /*0x8361ac*/
      {
        LODWORD(this->trophies) = 1; /*0x8361b8*/
        FriendServerReceiver::UnpackWorldString(this, (Friend *)this, pkt, v187); /*0x8361bc*/
      }
      else
      {
        LODWORD(this->trophies) = 0; /*0x837b4c*/
        if ( Packet::GetByte(pkt, nullptr) == 1 ) /*0x837b5c*/
        {
          v344 = Packet::GetString(pkt, nullptr); /*0x837b70*/
          if ( !TypeInfo::System::Globalization::CultureInfo->_1.cctor_finished_or_no_cctor ) /*0x837b74*/
            j_il2cpp_runtime_class_init_0(TypeInfo::System::Globalization::CultureInfo); /*0x837b80*/
          v345 = (IFormatProvider *)System::Globalization::CultureInfo::get_InvariantCulture(nullptr); /*0x837b90*/
          if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x837b94*/
            j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x837ba0*/
          if ( System::DateTime::TryParseExact( /*0x837bbc*/
                 v344,
                 (String *)"o",
                 v345,
                 DateTimeStyles__Enum_RoundtripKind,
                 &result,
                 nullptr) )
          {
            Friend::set_last_online(v188, result, nullptr); /*0x837bd4*/
          }
        }
      }
      if ( !byte_27E6BD3 ) /*0x837bdc*/
      {
        sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x837be8*/
        byte_27E6BD3 = 1; /*0x837bf0*/
      }
      v346 = TypeInfo::FriendServerConnector; /*0x837bf4*/
      if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x837bf8*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x837c00*/
        v346 = TypeInfo::FriendServerConnector; /*0x837c04*/
      }
      this = (FriendServerReceiver *)v346->static_fields->Instance; /*0x837c0c*/
      if ( !this ) /*0x837c10*/
        goto LABEL_639; /*0x837c10*/
      FriendServerConnector::CheckIfAutoLoginShouldBeDisabled((FriendServerConnector *)this, (MethodInfo *)incoming); /*0x837c14*/
      v301 = TypeInfo::UnityEngine::SceneManagement::SceneManager; /*0x837c18*/
      goto LABEL_373; /*0x837c18*/
    case 0x13u: /*0x835908*/
      v228 = Packet::GetString(pkt, nullptr); // // case 0x13: FRIEND_REQUEST_ACCEPTED - your friend request was accepted /*0x836814*/
      v229 = Packet::GetString(incominga, nullptr); /*0x836824*/
      v230 = Packet::GetByte(incominga, nullptr); /*0x836834*/
      this = (FriendServerReceiver *)FriendServerReceiver::GetFriendByUsername(receiver, v228, v231); /*0x836840*/
      if ( !this ) /*0x836844*/
        goto LABEL_639; /*0x836844*/
      v232 = v230; /*0x836848*/
      this->recently_seen_players = (List_1_RecentlySeenPlayer_ *)v229; /*0x836850*/
      p_recently_seen_players = &this->recently_seen_players; /*0x836850*/
      v234 = (Friend *)this; /*0x836854*/
      v235 = (FriendServerReceiver *)sub_73C72C(&this->recently_seen_players); /*0x836860*/
      if ( v232 == 1 ) /*0x836868*/
      {
        v234->status_t = 1; /*0x836878*/
        FriendServerReceiver::UnpackWorldString(v235, v234, incominga, v236); /*0x83687c*/
        if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x836884*/
          j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x83688c*/
        v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x836898*/
        v237 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x8368a4*/
        if ( System::String::op_Equality(v237, (String *)"Game", nullptr) ) /*0x8368b8*/
        {
          v238 = (String *)*p_recently_seen_players; /*0x8368d8*/
          v239 = TypeInfo::GameplayGUIControl->static_fields->Instance; /*0x8368e0*/
          this = (FriendServerReceiver *)System::String::Concat( /*0x8368ec*/
                                           (String *)"<color=#fffd91>",
                                           v238,
                                           (String *)"</color> accepted your friend request   ",
                                           nullptr);
          v240 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x836900*/
          if ( !v240 ) /*0x836904*/
            goto LABEL_639; /*0x836904*/
          icon_got_friend_req = v240->icon_accepted_friend_req; /*0x836908*/
LABEL_399:
          v256 = (String *)this; /*0x837de4*/
          v257 = TypeInfo::OnNotifClick; /*0x837de8*/
LABEL_400:
          this = (FriendServerReceiver *)sub_73C88C(v257); /*0x837dec*/
          if ( !this ) /*0x837df4*/
            goto LABEL_639; /*0x837df4*/
          v352 = this; /*0x837e00*/
          OnNotifClick::OnNotifClick((OnNotifClick *)this, OnNotifClick_type__Enum_friends_list_general, nullptr); /*0x837e04*/
          if ( !v239 ) /*0x837e08*/
            goto LABEL_639; /*0x837e08*/
          GameplayGUIControl::ShowNotif(v239, v256, icon_got_friend_req, (OnNotifClick *)v352, nullptr); /*0x837e20*/
          if ( !byte_27E6BD4 ) /*0x837e28*/
          {
            sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x837e34*/
            byte_27E6BD4 = 1; /*0x837e3c*/
          }
          v159 = TypeInfo::FriendServerInterface; /*0x837e40*/
LABEL_405:
          this = (FriendServerReceiver *)v159->static_fields->Instance; /*0x837e48*/
          if ( !this ) /*0x837e4c*/
            goto LABEL_639; /*0x837e4c*/
          if ( *((_DWORD *)this + 26) == 4 ) /*0x837e58*/
LABEL_407:
            FriendServerInterface::RedrawFriendsList((FriendServerInterface *)this, (MethodInfo *)incoming); /*0x837e5c*/
        }
      }
      else
      {
        v234->status_t = 0; /*0x837cc8*/
      }
      return; /*0x837e60*/
    case 0x14u: /*0x835908*/
      if ( !byte_27E6BD5 ) // // case 0x14: FRIEND_REMOVED - a friend was removed from your list /*0x836434*/
      {
        sub_73C778( /*0x836448*/
          &TypeInfo::FriendServerSender,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD5 = 1; /*0x836454*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x836464*/
      if ( !this ) /*0x836468*/
        goto LABEL_639; /*0x836468*/
      FriendServerSender::EndTimeout((FriendServerSender *)this, nullptr); /*0x836470*/
      v204 = Packet::GetString(pkt, nullptr); /*0x83647c*/
      this = (FriendServerReceiver *)FriendServerReceiver::GetFriendByUsername(receiver, v204, v205); /*0x836488*/
      if ( !receiver->friends ) /*0x83648c*/
        goto LABEL_639; /*0x83648c*/
      this = (FriendServerReceiver *)System::Collections::Generic::List<System::Object>::IndexOf( /*0x8364a0*/
                                       (List_1_System_Object_ *)receiver->friends,
                                       (Object *)this,
                                       MethodInfo::System::Collections::Generic::List<Friend>::IndexOf);
      if ( !receiver->friends ) /*0x8364a4*/
        goto LABEL_639; /*0x8364a8*/
      System::Collections::Generic::List<System::Object>::RemoveAt( /*0x8364b8*/
        (List_1_System_Object_ *)receiver->friends,
        (int32_t)this,
        MethodInfo::System::Collections::Generic::List<Friend>::RemoveAt);
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x8364c0*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x8364c8*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x8364d4*/
      v206 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x8364e0*/
      this = (FriendServerReceiver *)System::String::op_Equality(v206, (String *)"Game", nullptr); /*0x8364f4*/
      if ( ((unsigned __int8)this & 1) == 0 ) /*0x8364f8*/
        return; /*0x8364f8*/
      v207 = TypeInfo::WindowControl; /*0x8364fc*/
      goto LABEL_377; /*0x836500*/
    case 0x15u: /*0x835908*/
      v155 = Packet::GetString(pkt, nullptr); // // case 0x15: UNFRIEND_CONFIRM - confirmation that you unfriended someone /*0x835cc0*/
      this = (FriendServerReceiver *)FriendServerReceiver::GetFriendByUsername(receiver, v155, v156); /*0x835cd0*/
      if ( !receiver->friends ) /*0x835cd4*/
        goto LABEL_639; /*0x835cd4*/
      this = (FriendServerReceiver *)System::Collections::Generic::List<System::Object>::IndexOf( /*0x835ce8*/
                                       (List_1_System_Object_ *)receiver->friends,
                                       (Object *)this,
                                       MethodInfo::System::Collections::Generic::List<Friend>::IndexOf);
      if ( !receiver->friends ) /*0x835cec*/
        goto LABEL_639; /*0x835cec*/
      System::Collections::Generic::List<System::Object>::RemoveAt( /*0x835d00*/
        (List_1_System_Object_ *)receiver->friends,
        (int32_t)this,
        MethodInfo::System::Collections::Generic::List<Friend>::RemoveAt);
      if ( !byte_27E6BD3 ) /*0x835d08*/
      {
        sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x835d14*/
        byte_27E6BD3 = 1; /*0x835d1c*/
      }
      v157 = TypeInfo::FriendServerConnector; /*0x835d20*/
      if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x835d24*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x835d2c*/
        v157 = TypeInfo::FriendServerConnector; /*0x835d30*/
      }
      this = (FriendServerReceiver *)v157->static_fields->Instance; /*0x835d38*/
      if ( !this ) /*0x835d3c*/
        goto LABEL_639; /*0x835d3c*/
      FriendServerConnector::CheckIfAutoLoginShouldBeDisabled((FriendServerConnector *)this, (MethodInfo *)incoming); /*0x835d40*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x835d48*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x835d50*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x835d5c*/
      v158 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x835d68*/
      if ( !System::String::op_Equality(v158, (String *)"Game", nullptr) ) /*0x835d80*/
        return; /*0x835d80*/
      if ( !byte_27E6BD4 ) /*0x835d8c*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x835d98*/
        byte_27E6BD4 = 1; /*0x835da0*/
      }
      v159 = TypeInfo::FriendServerInterface; /*0x835dac*/
      goto LABEL_405; /*0x835db0*/
    case 0x16u: /*0x835908*/
      v249 = Packet::GetString(pkt, nullptr); // // case 0x16: FRIEND_ONLINE - friend came online, shows notification /*0x836ac8*/
      this = (FriendServerReceiver *)FriendServerReceiver::GetFriendByUsername(receiver, v249, v250); /*0x836ad4*/
      if ( !this ) /*0x836ad8*/
        goto LABEL_639; /*0x836ad8*/
      v252 = this; /*0x836ae8*/
      LODWORD(this->trophies) = 1; /*0x836aec*/
      FriendServerReceiver::UnpackWorldString(this, (Friend *)this, pkt, v251); /*0x836af0*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x836af8*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x836b00*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x836b0c*/
      v253 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x836b18*/
      if ( !System::String::op_Equality(v253, (String *)"Game", nullptr) ) /*0x836b30*/
        return; /*0x836b30*/
      recently_seen_players = (String *)v252->recently_seen_players; /*0x836b4c*/
      v239 = TypeInfo::GameplayGUIControl->static_fields->Instance; /*0x836b54*/
      this = (FriendServerReceiver *)System::String::Concat( /*0x836b60*/
                                       (String *)"<color=#00ff00>",
                                       recently_seen_players,
                                       (String *)"</color> is now online    ",
                                       nullptr);
      v255 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x836b74*/
      if ( !v255 ) /*0x836b78*/
        goto LABEL_639; /*0x836b78*/
      v256 = (String *)this; /*0x836b7c*/
      icon_got_friend_req = v255->icon_friend_login; /*0x836b80*/
      v257 = TypeInfo::OnNotifClick; /*0x836b84*/
      goto LABEL_400; /*0x836b88*/
    case 0x17u: /*0x835908*/
      v258 = Packet::GetString(pkt, nullptr); // // case 0x17: FRIEND_OFFLINE - friend went offline, clears chat unread /*0x836b9c*/
      this = (FriendServerReceiver *)FriendServerReceiver::GetFriendByUsername(receiver, v258, v259); /*0x836bac*/
      if ( !this ) /*0x836bb0*/
        goto LABEL_639; /*0x836bb0*/
      LODWORD(this->trophies) = 0; /*0x836bb4*/
      v260 = (Friend *)this; /*0x836bb8*/
      if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x836bc0*/
        j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x836bc8*/
      v467._dateData = System::DateTime::get_UtcNow(nullptr)._dateData; /*0x836bd0*/
      Friend::set_last_online(v260, v467, nullptr); /*0x836be0*/
      chat = v260->chat; /*0x836be4*/
      if ( !chat ) /*0x836be8*/
        goto LABEL_639; /*0x836be8*/
      v457->total_unread -= chat->n_unread; /*0x836bf8*/
      entries = chat->entries; /*0x836bfc*/
      chat->n_unread = 0; /*0x836c00*/
      if ( !entries ) /*0x836c04*/
        goto LABEL_639; /*0x836c04*/
      v263 = entries->_size; /*0x836c08*/
      v264 = entries->_version + 1; /*0x836c10*/
      entries->_size = 0; /*0x836c18*/
      entries->_version = v264; /*0x836c18*/
      if ( v263 >= 1 ) /*0x836c1c*/
        System::Array::Clear((Array *)entries->_items, 0, v263, nullptr); /*0x836c2c*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x836c38*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x836c40*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x836c4c*/
      v265 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x836c58*/
      if ( !System::String::op_Equality(v265, (String *)"Game", nullptr) ) /*0x836c70*/
        return; /*0x836c70*/
      if ( !byte_27E6BD4 ) /*0x836c7c*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x836c88*/
        byte_27E6BD4 = 1; /*0x836c90*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x836ca4*/
      if ( !this ) /*0x836ca8*/
        goto LABEL_639; /*0x836ca8*/
      FriendServerInterface::RedrawGlobalNotificationCounter((FriendServerInterface *)this, (MethodInfo *)incoming); /*0x836cac*/
      if ( !byte_27E6BD4 ) /*0x836cb4*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x836cc0*/
        byte_27E6BD4 = 1; /*0x836cc8*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x836cd4*/
      if ( !this ) /*0x836cd8*/
        goto LABEL_639; /*0x836cd8*/
      if ( *((_DWORD *)this + 26) == 4 ) /*0x836ce4*/
        goto LABEL_407; /*0x836ce4*/
      if ( *((_DWORD *)this + 26) != 6 ) /*0x836cf0*/
        return; /*0x836cf0*/
      goto LABEL_382; /*0x836cf0*/
    case 0x18u: /*0x835908*/
      if ( !byte_27E6BD5 ) // // case 0x18: FRIEND_REQUEST_REJECTED - your friend request was declined /*0x837448*/
      {
        sub_73C778( /*0x837460*/
          &TypeInfo::FriendServerSender,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD5 = 1; /*0x837470*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x837480*/
      if ( !this ) /*0x837484*/
        goto LABEL_639; /*0x837484*/
      FriendServerSender::EndTimeout((FriendServerSender *)this, nullptr); /*0x837490*/
      v298 = Packet::GetString(pkt, nullptr); /*0x83749c*/
      this = (FriendServerReceiver *)FriendServerReceiver::GetFriendByUsername(receiver, v298, v299); /*0x8374a8*/
      if ( !receiver->friends ) /*0x8374ac*/
        goto LABEL_639; /*0x8374ac*/
      this = (FriendServerReceiver *)System::Collections::Generic::List<System::Object>::IndexOf( /*0x8374c0*/
                                       (List_1_System_Object_ *)receiver->friends,
                                       (Object *)this,
                                       MethodInfo::System::Collections::Generic::List<Friend>::IndexOf);
      if ( !receiver->friends ) /*0x8374c4*/
        goto LABEL_639; /*0x8374c4*/
      System::Collections::Generic::List<System::Object>::RemoveAt( /*0x8374d8*/
        (List_1_System_Object_ *)receiver->friends,
        (int32_t)this,
        MethodInfo::System::Collections::Generic::List<Friend>::RemoveAt);
      if ( !byte_27E6BD3 ) /*0x8374e4*/
      {
        sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x8374f0*/
        byte_27E6BD3 = 1; /*0x8374f8*/
      }
      v300 = TypeInfo::FriendServerConnector; /*0x8374fc*/
      if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x837500*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x837508*/
        v300 = TypeInfo::FriendServerConnector; /*0x83750c*/
      }
      this = (FriendServerReceiver *)v300->static_fields->Instance; /*0x837514*/
      if ( !this ) /*0x837518*/
        goto LABEL_639; /*0x837518*/
      FriendServerConnector::CheckIfAutoLoginShouldBeDisabled((FriendServerConnector *)this, (MethodInfo *)incoming); /*0x83751c*/
      v301 = TypeInfo::UnityEngine::SceneManagement::SceneManager; /*0x837520*/
LABEL_373:
      if ( !v301->_1.cctor_finished_or_no_cctor ) /*0x837c1c*/
        j_il2cpp_runtime_class_init_0(v301); /*0x837c24*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x837c30*/
      v347 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x837c3c*/
      this = (FriendServerReceiver *)System::String::op_Equality(v347, (String *)"Game", nullptr); /*0x837c50*/
      if ( ((unsigned __int8)this & 1) == 0 ) /*0x837c54*/
        return; /*0x837c54*/
      v207 = TypeInfo::WindowControl; /*0x837c58*/
      goto LABEL_377; /*0x837c58*/
    case 0x19u: /*0x835908*/
      v291 = Packet::GetString(pkt, nullptr); // // case 0x19: REQ_DENIED - friend declined your join request, removes from list /*0x8372d4*/
      FriendByUsername = (Packet *)FriendServerReceiver::GetFriendByUsername(receiver, v291, v292); /*0x8372e0*/
      if ( !FriendByUsername ) /*0x8372e4*/
        return; /*0x8372e4*/
      incoming = FriendByUsername; /*0x8372f4*/
      this = (FriendServerReceiver *)receiver->friends; /*0x8372f8*/
      if ( !this ) /*0x8372fc*/
        goto LABEL_639; /*0x8372fc*/
      this = (FriendServerReceiver *)System::Collections::Generic::List<System::Object>::IndexOf( /*0x837304*/
                                       (List_1_System_Object_ *)this,
                                       (Object *)incoming,
                                       MethodInfo::System::Collections::Generic::List<Friend>::IndexOf);
      if ( !receiver->friends ) /*0x837308*/
        goto LABEL_639; /*0x837308*/
      System::Collections::Generic::List<System::Object>::RemoveAt( /*0x83731c*/
        (List_1_System_Object_ *)receiver->friends,
        (int32_t)this,
        MethodInfo::System::Collections::Generic::List<Friend>::RemoveAt);
      if ( !byte_27E6BD3 ) /*0x837324*/
      {
        sub_73C778(&TypeInfo::FriendServerConnector, incoming); /*0x837330*/
        byte_27E6BD3 = 1; /*0x837338*/
      }
      v294 = TypeInfo::FriendServerConnector; /*0x83733c*/
      if ( !TypeInfo::FriendServerConnector->_1.cctor_finished_or_no_cctor ) /*0x837340*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerConnector); /*0x837348*/
        v294 = TypeInfo::FriendServerConnector; /*0x83734c*/
      }
      this = (FriendServerReceiver *)v294->static_fields->Instance; /*0x837354*/
      if ( !this ) /*0x837358*/
        goto LABEL_639; /*0x837358*/
      FriendServerConnector::CheckIfAutoLoginShouldBeDisabled((FriendServerConnector *)this, (MethodInfo *)incoming); /*0x83735c*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x837364*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x83736c*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x837378*/
      v295 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x837384*/
      if ( !System::String::op_Equality(v295, (String *)"Game", nullptr) ) /*0x83739c*/
        return; /*0x83739c*/
      if ( !byte_27E6BD4 ) /*0x8373a8*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x8373b4*/
        byte_27E6BD4 = 1; /*0x8373bc*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x8373d0*/
      if ( !this ) /*0x8373d4*/
        goto LABEL_639; /*0x8373d4*/
      if ( *((_DWORD *)this + 26) == 4 ) /*0x8373e0*/
        goto LABEL_407; /*0x8373e0*/
      if ( *((_DWORD *)this + 26) != 6 || !System::String::op_Equality(*((String **)this + 22), v291, nullptr) ) /*0x837400*/
        return; /*0x837400*/
      goto LABEL_379; /*0x837400*/
    case 0x1Au: /*0x835908*/
      v142 = Packet::GetString(pkt, nullptr); // // case 0x1A: FRIEND_CHAT_MSG - received chat message from a friend /*0x835af4*/
      v143 = Packet::GetString(pkt, nullptr); /*0x835b04*/
      v145 = FriendServerReceiver::GetFriendByUsername(receiver, v142, v144); /*0x835b10*/
      if ( !v145 ) /*0x835b14*/
        return; /*0x835b14*/
      v146 = v145; /*0x835b28*/
      v147 = System::String::Concat( /*0x835b4c*/
               (String *)"<color=#abebff>",
               v145->username_punctuated,
               (String *)":</color> ",
               v143,
               nullptr);
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::chat_log); /*0x835b58*/
      if ( !this ) /*0x835b5c*/
        goto LABEL_639; /*0x835b5c*/
      v148 = (chat_log *)this; /*0x835b78*/
      chat_log::chat_log((chat_log *)this, v147, v143, nullptr, 0, nullptr, nullptr); /*0x835b7c*/
      this = (FriendServerReceiver *)v146->chat; /*0x835b84*/
      v149 = v457; /*0x835b8c*/
      if ( !this ) /*0x835b94*/
        goto LABEL_639; /*0x835b94*/
      ChatCollection::AddLog((ChatCollection *)this, v148, nullptr); /*0x835ba0*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x835ba8*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x835bb0*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x835bbc*/
      v150 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x835bc8*/
      this = (FriendServerReceiver *)System::String::op_Equality(v150, (String *)"Game", nullptr); /*0x835bdc*/
      if ( ((unsigned __int8)this & 1) == 0 ) /*0x835be0*/
      {
        v367 = v146->chat; /*0x838ee4*/
        if ( !v367 ) /*0x838ee8*/
          goto LABEL_639; /*0x838ee8*/
        goto LABEL_589; /*0x838ee8*/
      }
      if ( !byte_27E6BD4 ) /*0x835be8*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x835bf4*/
        byte_27E6BD4 = 1; /*0x835bfc*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x835c08*/
      if ( !this ) /*0x835c0c*/
        goto LABEL_639; /*0x835c0c*/
      v152 = v146; /*0x835c10*/
      goto LABEL_444; /*0x835c14*/
    case 0x1Bu: /*0x835908*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor )// // case 0x1B: AUTH_STATUS - auth/setup progress (1=authenticating, 0=setting up private server) /*0x83650c*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x836514*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x836520*/
      v208 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x83652c*/
      if ( !System::String::op_Equality(v208, (String *)"Game", nullptr) ) /*0x836544*/
        return; /*0x836544*/
      v209 = Packet::GetByte(pkt, nullptr); /*0x836554*/
      if ( v209 == 1 ) /*0x83655c*/
      {
        this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x83903c*/
        if ( !this ) /*0x839040*/
          goto LABEL_639; /*0x839040*/
        v210 = (String **)&StringLiteral_Authenticating; /*0x839048*/
      }
      else
      {
        if ( v209 ) /*0x836560*/
          return; /*0x836560*/
        this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x83656c*/
        if ( !this ) /*0x836570*/
          goto LABEL_639; /*0x836570*/
        v210 = (String **)&StringLiteral_Setting_up_private_server; /*0x836578*/
      }
      PopupControl::ShowConnecting((PopupControl *)this, *v210, nullptr); /*0x839054*/
      return; /*0x839058*/
    case 0x1Du: /*0x835908*/
      if ( !byte_27E6BD5 ) // // case 0x1D: SERVER_LIST - list of public game servers /*0x83752c*/
      {
        sub_73C778( /*0x837540*/
          &TypeInfo::FriendServerSender,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD5 = 1; /*0x83754c*/
      }
      v302 = receiver; /*0x837554*/
      v303 = pkt; /*0x837554*/
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x83755c*/
      if ( !this ) /*0x837560*/
        goto LABEL_639; /*0x837560*/
      FriendServerSender::EndTimeout((FriendServerSender *)this, nullptr); /*0x837570*/
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::System::Collections::Generic::List<ServerInfo>); /*0x837578*/
      if ( !this ) /*0x83757c*/
        goto LABEL_639; /*0x83757c*/
      v304 = (List_1_System_Object_ *)this; /*0x83758c*/
      System::Collections::Generic::List<System::Object>::List( /*0x837598*/
        (List_1_System_Object_ *)this,
        MethodInfo::System::Collections::Generic::List<ServerInfo>::List);
      this = (FriendServerReceiver *)Packet::GetByte(incominga, nullptr); /*0x8375a4*/
      v305 = (unsigned __int8)this; /*0x8375a8*/
      if ( !(_BYTE)this ) /*0x8375ac*/
        goto LABEL_305; /*0x8375ac*/
      do /*0x8376e4*/
      {
        v306 = Packet::GetString(v303, nullptr); /*0x8375bc*/
        v307 = Packet::GetString(v303, nullptr); /*0x8375cc*/
        v308 = Packet::GetString(v303, nullptr); /*0x8375dc*/
        v309 = Packet::GetString(v303, nullptr); /*0x8375ec*/
        v310 = Packet::GetString(v303, nullptr); /*0x8375fc*/
        v311 = v303; /*0x83760c*/
        v312 = Packet::GetShort(v303, nullptr); /*0x837610*/
        v313 = Packet::GetShort(v311, nullptr); /*0x837620*/
        server_game_mode = Packet::GetString(v311, nullptr); /*0x837638*/
        this = (FriendServerReceiver *)sub_73C88C(TypeInfo::ServerInfo); /*0x837644*/
        if ( !this ) /*0x837648*/
          goto LABEL_639; /*0x837648*/
        v315 = this; /*0x837668*/
        ServerInfo::ServerInfo((ServerInfo *)this, v306, v307, v308, v309, v310, v312, v313, server_game_mode, nullptr); /*0x837670*/
        v316 = v304->_items; /*0x83767c*/
        v317 = MethodInfo::System::Collections::Generic::List<ServerInfo>::Add; /*0x837688*/
        ++v304->_version; /*0x83768c*/
        if ( !v316 ) /*0x837690*/
          goto LABEL_639; /*0x837690*/
        v318 = v304->_size; /*0x837694*/
        v302 = v457; /*0x83769c*/
        v303 = incominga; /*0x83769c*/
        if ( (unsigned int)v318 >= v316->max_length.size ) /*0x8376a4*/
        {
          this = (FriendServerReceiver *)(*((__int64 (__fastcall **)(List_1_System_Object_ *, FriendServerReceiver *))v317->klass->rgctx_data[11].rgctxDataDummy /*0x8376dc*/
                                          + 1))(
                                           v304,
                                           v315);
        }
        else
        {
          v319 = &v316->klass + v318; /*0x8376ac*/
          v304->_size = v318 + 1; /*0x8376b0*/
          v319[4] = (Object__Array__Class *)v315; /*0x8376b4*/
          this = (FriendServerReceiver *)sub_73C72C(v319 + 4); /*0x8376bc*/
        }
        --v305; /*0x8376e0*/
      }
      while ( v305 ); /*0x8376e4*/
LABEL_305:
      public_server_list = v302->public_server_list; /*0x8376e8*/
      if ( !public_server_list ) /*0x8376ec*/
        goto LABEL_639; /*0x8376ec*/
      v321 = public_server_list->_size; /*0x8376f0*/
      v322 = public_server_list->_version + 1; /*0x8376fc*/
      public_server_list->_size = 0; /*0x837704*/
      public_server_list->_version = v322; /*0x837704*/
      if ( v321 >= 1 ) /*0x837708*/
        System::Array::Clear((Array *)public_server_list->_items, 0, v321, nullptr); /*0x837718*/
      System::Collections::Generic::List<System::Object>::GetEnumerator( /*0x837748*/
        &v459,
        v304,
        MethodInfo::System::Collections::Generic::List<ServerInfo>::GetEnumerator);
      v463 = v459; /*0x837754*/
LABEL_309:
      while ( 1 ) /*0x837764*/
      {
        Item = (Object *)System::Collections::Generic::List_1_T_::Enumerator<System::Object>::MoveNext( /*0x837764*/
                           &v463,
                           MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ServerInfo>::MoveNext);
        if ( ((unsigned __int8)Item & 1) == 0 ) /*0x837768*/
          break; /*0x837768*/
        v326 = (List_1_System_Object_ *)v302->public_server_list; /*0x83776c*/
        if ( !v326 ) /*0x837770*/
LABEL_636:
          sub_73C89C(Item, v324, v325); /*0x839264*/
        current = v463._current; /*0x837774*/
        v328 = 0; /*0x837778*/
        while ( v328 < v326->_size ) /*0x837784*/
        {
          Item = System::Collections::Generic::List<System::Object>::get_Item( /*0x837794*/
                   v326,
                   v328,
                   MethodInfo::System::Collections::Generic::List<ServerInfo>::get_Item);
          if ( !Item ) /*0x837798*/
            sub_73C89C(0, v324, v325); /*0x839268*/
          if ( !current ) /*0x83779c*/
            sub_73C89C(Item, v324, v325); /*0x83926c*/
          if ( SLODWORD(Item[1].monitor) <= SLODWORD(current[1].monitor) ) /*0x8377ac*/
          {
            v326 = (List_1_System_Object_ *)v302->public_server_list; /*0x8377c0*/
            if ( v328 != -1 ) /*0x8377c8*/
            {
              if ( !v326 ) /*0x8377cc*/
                sub_73C89C(Item, v324, v325); /*0x83927c*/
              System::Collections::Generic::List<System::Object>::Insert( /*0x8377e0*/
                (List_1_System_Object_ *)v302->public_server_list,
                v328,
                current,
                MethodInfo::System::Collections::Generic::List<ServerInfo>::Insert);
              goto LABEL_309; /*0x8377e4*/
            }
            if ( !v326 ) /*0x8377e8*/
              sub_73C89C(Item, v324, v325); /*0x839280*/
            break; /*0x8377e8*/
          }
          v326 = (List_1_System_Object_ *)v302->public_server_list; /*0x8377b0*/
          ++v328; /*0x8377b4*/
          if ( !v326 ) /*0x8377b8*/
            goto LABEL_636; /*0x8377b8*/
        }
        v329 = v326->_items; /*0x8377ec*/
        v330 = MethodInfo::System::Collections::Generic::List<ServerInfo>::Add; /*0x8377f4*/
        ++v326->_version; /*0x8377fc*/
        if ( !v329 ) /*0x837800*/
          sub_73C89C(Item, v324, v325); /*0x839274*/
        v331 = v326->_size; /*0x837804*/
        if ( (unsigned int)v331 >= v329->max_length.size ) /*0x837810*/
        {
          (*((void (__fastcall **)(List_1_System_Object_ *, Object *))v330->klass->rgctx_data[11].rgctxDataDummy + 1))( /*0x837848*/
            v326,
            current);
        }
        else
        {
          v332 = &v329->klass + v331; /*0x837818*/
          v326->_size = v331 + 1; /*0x83781c*/
          v332[4] = (Object__Array__Class *)current; /*0x837820*/
          sub_73C72C(v332 + 4); /*0x837828*/
        }
      }
      System::Collections::Generic::List_1_T_::Enumerator<System::Object>::Dispose( /*0x837a24*/
        &v463,
        MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ServerInfo>::Dispose);
      v342 = TypeInfo::UnityEngine::SceneManagement::SceneManager; /*0x837a30*/
      goto LABEL_472; /*0x837a34*/
    case 0x1Eu: /*0x835908*/
      if ( !byte_27E6BD5 ) // // case 0x1E: JOIN_SERVER_FAILED - could not join server (full or offline) /*0x835c20*/
      {
        sub_73C778( /*0x835c38*/
          &TypeInfo::FriendServerSender,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD5 = 1; /*0x835c48*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x835c58*/
      if ( !this ) /*0x835c5c*/
        goto LABEL_639; /*0x835c5c*/
      FriendServerSender::EndTimeout((FriendServerSender *)this, nullptr); /*0x835c68*/
      v153 = Packet::GetByte(pkt, nullptr); /*0x835c78*/
      if ( v153 == 1 ) /*0x835c80*/
      {
        this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x8383fc*/
        if ( !this ) /*0x838400*/
          goto LABEL_639; /*0x838400*/
        v154 = (String **)&StringLiteral_Could_not_join_serveru000AServer_ful; /*0x838408*/
      }
      else
      {
        if ( v153 ) /*0x835c84*/
          return; /*0x835c84*/
        this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x835c90*/
        if ( !this ) /*0x835c94*/
          goto LABEL_639; /*0x835c94*/
        v154 = (String **)&StringLiteral_Could_not_join_serveru000AServer_no_; /*0x835c9c*/
      }
      PopupControl::ShowMessage((PopupControl *)this, *v154, PopupControl_context__Enum_message, nullptr); /*0x838418*/
      v342 = TypeInfo::UnityEngine::SceneManagement::SceneManager; /*0x83841c*/
LABEL_472:
      if ( !v342->_1.cctor_finished_or_no_cctor ) /*0x838420*/
        j_il2cpp_runtime_class_init_0(v342); /*0x838428*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x838434*/
      v379 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x838440*/
      if ( !System::String::op_Equality(v379, (String *)"Game", nullptr) ) /*0x838458*/
        return; /*0x838458*/
      if ( !byte_27E6BD4 ) /*0x838464*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x838470*/
        byte_27E6BD4 = 1; /*0x838478*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x83848c*/
      if ( !this ) /*0x838490*/
        goto LABEL_639; /*0x838490*/
      if ( *((_DWORD *)this + 26) != 1 ) /*0x83849c*/
        return; /*0x83849c*/
      v349 = FriendServerInterface_friend_window_screen__Enum_public_server_list; /*0x8384a0*/
      goto LABEL_634; /*0x8384a4*/
    case 0x1Fu: /*0x835908*/
      v193 = (Object *)Packet::GetString(pkt, nullptr);// // case 0x1F: SERVER_ICON - server icon image data received /*0x8362a8*/
      v194 = Packet::GetByte(incominga, nullptr); /*0x8362c0*/
      v195 = nullptr; /*0x8362c8*/
      if ( v194 != 1 ) /*0x8362cc*/
        goto LABEL_99; /*0x8362cc*/
      v196 = (unsigned int)Packet::GetShort(incominga, nullptr); /*0x8362e8*/
      v195 = (Byte__Array *)sub_73C7E4(TypeInfo::System::Byte, (unsigned int)v196); /*0x8362fc*/
      if ( (int)v196 < 1 ) /*0x836300*/
        goto LABEL_99; /*0x836300*/
      for ( i = 0; i != v196; ++i ) /*0x836304*/
      {
        this = (FriendServerReceiver *)Packet::GetByte(incominga, nullptr); /*0x836314*/
        if ( !v195 ) /*0x836318*/
          goto LABEL_639; /*0x836318*/
        if ( i >= (unsigned int)v195->max_length.size ) /*0x836324*/
          sub_73C8A4(this); /*0x839278*/
        v195->vector[i] = (unsigned __int8)this; /*0x836328*/
      }
LABEL_99:
      this = (FriendServerReceiver *)receiver->requesting_server_icons; /*0x836338*/
      if ( !this ) /*0x83633c*/
        goto LABEL_639; /*0x83633c*/
      System::Collections::Generic::List<System::Object>::Remove( /*0x83635c*/
        (List_1_System_Object_ *)this,
        v193,
        MethodInfo::System::Collections::Generic::List<System::String>::Remove);
      if ( v194 == 1 ) /*0x836364*/
      {
        this = (FriendServerReceiver *)sub_73C88C(TypeInfo::UnityEngine::Texture2D); /*0x836374*/
        if ( !this ) /*0x836378*/
          goto LABEL_639; /*0x836378*/
        v198 = (Texture2D *)this; /*0x836388*/
        UnityEngine::Texture2D::Texture2D((Texture2D *)this, 32, 32, nullptr); /*0x83638c*/
        UnityEngine::ImageConversion::LoadImage(v198, v195, nullptr); /*0x83639c*/
        v199 = ((__int64 (__fastcall *)(Texture2D *, const MethodInfo *))v198->klass->vtable.get_width.methodPtr)( /*0x8363b4*/
                 v198,
                 v198->klass->vtable.get_width.method);
        v200 = ((__int64 (__fastcall *)(Texture2D *, const MethodInfo *))v198->klass->vtable.get_height.methodPtr)( /*0x8363c0*/
                 v198,
                 v198->klass->vtable.get_height.method);
        v459._list = nullptr; /*0x8363dc*/
        *(_QWORD *)&v459._index = 0; /*0x8363dc*/
        UnityEngine::Rect::Rect((Rect *)&v459, 0.0, 0.0, (float)v199, (float)v200, nullptr); /*0x8363e0*/
        v469.x = 0.5; /*0x8363ec*/
        v469.y = 0.5; /*0x8363f4*/
        this = (FriendServerReceiver *)UnityEngine::Sprite::Create(v198, *(Rect *)&v459._list, v469, nullptr); /*0x8363fc*/
        if ( !v457->cached_server_icons ) /*0x836400*/
          goto LABEL_639; /*0x836404*/
        v201 = MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::Add; /*0x836408*/
        v202 = (Object *)this; /*0x83640c*/
        this = (FriendServerReceiver *)v457->cached_server_icons; /*0x836410*/
        v203 = v193; /*0x836414*/
      }
      else
      {
        this = (FriendServerReceiver *)receiver->cached_server_icons; /*0x838230*/
        if ( !this ) /*0x838234*/
          goto LABEL_639; /*0x838234*/
        v201 = MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::Add; /*0x838238*/
        v203 = v193; /*0x83823c*/
        v202 = nullptr; /*0x838240*/
      }
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x838244*/
        (Dictionary_2_System_Object_System_Object_ *)this,
        v203,
        v202,
        v201);
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x83824c*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x838254*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x838260*/
      v368 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x83826c*/
      if ( !System::String::op_Equality(v368, (String *)"Game", nullptr) ) /*0x838284*/
        return; /*0x838284*/
      if ( !byte_27E6BD4 ) /*0x838290*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x83829c*/
        byte_27E6BD4 = 1; /*0x8382a4*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x8382b8*/
      if ( !this ) /*0x8382bc*/
        goto LABEL_639; /*0x8382bc*/
      FriendServerInterface::GotServerIcon((FriendServerInterface *)this, (String *)v193, method); /*0x8382c4*/
      return; /*0x8382c8*/
    case 0x20u: /*0x835908*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor )// // case 0x20: CONNECT_TO_GAME - connecting to game server, pings provided /*0x835ef8*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x835f08*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x835f14*/
      v170 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x835f20*/
      if ( !System::String::op_Equality(v170, (String *)"Game", nullptr) ) /*0x835f38*/
        return; /*0x835f38*/
      this = (FriendServerReceiver *)Packet::GetByte(pkt, nullptr); /*0x835f48*/
      if ( !TypeInfo::WindowControl->static_fields->Instance ) /*0x835f54*/
        goto LABEL_639; /*0x835f54*/
      v171 = (char)this; /*0x835f5c*/
      WindowControl::CloseAllWindows(TypeInfo::WindowControl->static_fields->Instance, nullptr); /*0x835f68*/
      this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x835f74*/
      if ( !this ) /*0x835f78*/
        goto LABEL_639; /*0x835f78*/
      v172 = (String **)&StringLiteral_Player_is_joining; /*0x835f84*/
      if ( v171 != 1 ) /*0x835f98*/
        v172 = (String **)&StringLiteral_Joining_game; /*0x835f98*/
      PopupControl::ShowConnecting((PopupControl *)this, *v172, nullptr); /*0x835fa0*/
      v173 = Packet::GetShort(pkt, nullptr); /*0x835fb0*/
      if ( v173 < 1 ) /*0x835fb8*/
        return; /*0x835fb8*/
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::System::Collections::Generic::List<ToPing>); /*0x835fc0*/
      if ( !this ) /*0x835fc4*/
        goto LABEL_639; /*0x835fc4*/
      v174 = (List_1_ToPing_ *)this; /*0x835fcc*/
      System::Collections::Generic::List<System::Object>::List( /*0x835fd0*/
        (List_1_System_Object_ *)this,
        MethodInfo::System::Collections::Generic::List<ToPing>::List);
      do /*0x836098*/
      {
        v175 = Packet::GetString(incominga, nullptr); /*0x835fe4*/
        v176 = Packet::GetString(incominga, nullptr); /*0x835ff4*/
        v177 = Packet::GetShort(incominga, nullptr); /*0x836008*/
        this = (FriendServerReceiver *)sub_73C88C(TypeInfo::ToPing); /*0x836010*/
        if ( !this ) /*0x836014*/
          goto LABEL_639; /*0x836014*/
        v178 = this; /*0x836028*/
        ToPing::ToPing((ToPing *)this, v175, v176, v177, nullptr); /*0x83602c*/
        v179 = v174->_items; /*0x836038*/
        v180 = MethodInfo::System::Collections::Generic::List<ToPing>::Add; /*0x83603c*/
        ++v174->_version; /*0x836044*/
        if ( !v179 ) /*0x836048*/
          goto LABEL_639; /*0x836048*/
        v181 = v174->_size; /*0x83604c*/
        if ( (unsigned int)v181 >= v179->max_length.size ) /*0x836058*/
        {
          (*((void (__fastcall **)(List_1_ToPing_ *, FriendServerReceiver *))v180->klass->rgctx_data[11].rgctxDataDummy /*0x836090*/
           + 1))(
            v174,
            v178);
        }
        else
        {
          v182 = &v179->klass + v181; /*0x836060*/
          v174->_size = v181 + 1; /*0x836064*/
          v182[4] = (ToPing__Array__Class *)v178; /*0x836068*/
          sub_73C72C(v182 + 4); /*0x836070*/
        }
        --v173; /*0x836094*/
      }
      while ( v173 ); /*0x836098*/
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>); /*0x8360a0*/
      if ( !this ) /*0x8360a4*/
        goto LABEL_639; /*0x8360a4*/
      v183 = this; /*0x8360b8*/
      System::Action<System::Object>::Action( /*0x8360c0*/
        (Action_1_Object_ *)this,
        (Object *)v457,
        MethodInfo::FriendServerReceiver::_OnReceive_b__26_0,
        nullptr);
      this = (FriendServerReceiver *)TypeInfo::PingController->static_fields->Instance; /*0x8360d4*/
      if ( !this ) /*0x8360d8*/
        goto LABEL_639; /*0x8360d8*/
      PingController::PingMany( /*0x8360ec*/
        (PingController *)this,
        v174,
        (Action_1_System_Collections_Generic_Dictionary_2_ *)v183,
        (MonoBehaviour *)v457,
        nullptr);
      return; /*0x8360f0*/
    case 0x23u: /*0x835908*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor )// // case 0x23: MATCH_SETUP_FAILED - couldn't set up match on server /*0x836918*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x836920*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x83692c*/
      v242 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x836938*/
      if ( !System::String::op_Equality(v242, (String *)"Game", nullptr) ) /*0x836950*/
        return; /*0x836950*/
      this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x83695c*/
      if ( !this ) /*0x836960*/
        goto LABEL_639; /*0x836960*/
      v189 = &StringLiteral_Couldn_t_set_up_matchu000AThe_server; /*0x836968*/
LABEL_163:
      v243 = (String *)*v189; /*0x83696c*/
      goto LABEL_483; /*0x836974*/
    case 0x25u: /*0x835908*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor )// // case 0x25: GAME_SERVER_CONNECT - connect to game server with address/port/token /*0x835dc4*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x835dd4*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x835de0*/
      v160 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x835dec*/
      if ( System::String::op_Equality(v160, (String *)"Game", nullptr) ) /*0x835e00*/
      {
        v161 = Packet::GetString(pkt, nullptr); /*0x835e18*/
        v162 = Packet::GetString(pkt, nullptr); /*0x835e28*/
        v163 = Packet::GetString(pkt, nullptr); /*0x835e38*/
        v164 = Packet::GetString(incominga, nullptr); /*0x835e48*/
        v165 = Packet::GetShort(incominga, nullptr); /*0x835e58*/
        this = (FriendServerReceiver *)Packet::GetByte(incominga, nullptr); /*0x835e64*/
        if ( !v161 ) /*0x835e68*/
          goto LABEL_639; /*0x835e68*/
        this = (FriendServerReceiver *)System::String::Replace(v161, (String *)"(private)", (String *)"", nullptr); /*0x835e84*/
        if ( !TypeInfo::PlayerData->static_fields->Instance ) /*0x835e90*/
          goto LABEL_639; /*0x835e90*/
        v166 = (String *)this; /*0x835e9c*/
        v167 = PlayerData::GetGlobalString( /*0x835ea8*/
                 TypeInfo::PlayerData->static_fields->Instance,
                 (String *)"username_punctuated",
                 nullptr);
        this = (FriendServerReceiver *)System::String::op_Equality(v167, v166, nullptr); /*0x835eb4*/
        v168 = TypeInfo::PopupControl->static_fields->Instance; /*0x835ec0*/
        if ( ((unsigned __int8)this & 1) != 0 ) /*0x835ec4*/
        {
          if ( !v168 ) /*0x835ec8*/
            goto LABEL_639; /*0x835ec8*/
          v169 = (String *)"Connecting to private server"; /*0x835ed4*/
        }
        else
        {
          this = (FriendServerReceiver *)System::String::Concat( /*0x838f28*/
                                           (String *)"Connecting to ",
                                           v166,
                                           (String *)"'s World",
                                           nullptr);
          if ( !v168 ) /*0x838f2c*/
            goto LABEL_639; /*0x838f2c*/
          v169 = (String *)this; /*0x838f30*/
        }
        PopupControl::ShowConnecting(v168, v169, nullptr); /*0x838f44*/
        this = (FriendServerReceiver *)TypeInfo::GameServerConnector->static_fields->Instance; /*0x838f50*/
        if ( !this ) /*0x838f54*/
LABEL_639:
          sub_73C89C(this, incoming, method); /*0x839270*/
        GameServerConnector::ConnectToGameServer((GameServerConnector *)this, v163, v164, v165, v162, nullptr); /*0x838f6c*/
      }
      else
      {
        if ( !byte_27E6BD5 ) /*0x837b10*/
        {
          sub_73C778(&TypeInfo::FriendServerSender, incoming); /*0x837b1c*/
          byte_27E6BD5 = 1; /*0x837b24*/
        }
        this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x837b30*/
        if ( !this ) /*0x837b34*/
          goto LABEL_639; /*0x837b34*/
        FriendServerSender::EndTimeout((FriendServerSender *)this, nullptr); /*0x837b3c*/
      }
      return; /*0x838f70*/
    case 0x27u: /*0x835908*/
      if ( !byte_27E6BD5 ) // // case 0x27: INVITE_SENT - confirmation that invite was sent to friend /*0x8378b0*/
      {
        sub_73C778( /*0x8378c8*/
          &TypeInfo::FriendServerSender,
          &TypeInfo::System::Action<System::Collections::Generic::Dictionary<System::String,short>>);
        byte_27E6BD5 = 1; /*0x8378d8*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x8378e4*/
      if ( !this ) /*0x8378e8*/
        goto LABEL_639; /*0x8378e8*/
      FriendServerSender::EndTimeout((FriendServerSender *)this, nullptr); /*0x8378f4*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x8378fc*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x837904*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x837910*/
      v336 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x83791c*/
      if ( !System::String::op_Equality(v336, (String *)"Game", nullptr) ) /*0x837934*/
        return; /*0x837934*/
      this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x837940*/
      if ( !this ) /*0x837944*/
        goto LABEL_639; /*0x837944*/
      PopupControl::ShowMessage( /*0x837960*/
        (PopupControl *)this,
        (String *)"Invite sent!",
        PopupControl_context__Enum_message,
        nullptr);
      if ( !byte_27E6BD4 ) /*0x837974*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x837980*/
        byte_27E6BD4 = 1; /*0x837984*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x837990*/
      if ( !this ) /*0x837994*/
        goto LABEL_639; /*0x837994*/
      if ( *((_DWORD *)this + 26) != 1 ) /*0x8379a0*/
        return; /*0x8379a0*/
      goto LABEL_382; /*0x8379a0*/
    case 0x28u: /*0x835908*/
      v333 = Packet::GetString(pkt, nullptr); // // case 0x28: FRIEND_INVITE_RECEIVED - friend invited you to join their game /*0x837870*/
      v464.m_value = Packet::GetByte(pkt, nullptr); /*0x83788c*/
      if ( (unsigned __int8)(v464.m_value - 1) > 1u ) /*0x837890*/
        v335 = (Object *)""; /*0x837e6c*/
      else
        v335 = (Object *)Packet::GetString(pkt, nullptr); /*0x8378a0*/
      v353 = FriendServerReceiver::GetFriendByUsername(receiver, v333, v334); /*0x837e78*/
      if ( !v353 ) /*0x837e7c*/
        return; /*0x837e7c*/
      v354 = v353; /*0x837e80*/
      this = (FriendServerReceiver *)v353->chat; /*0x837e84*/
      if ( !this ) /*0x837e88*/
        goto LABEL_639; /*0x837e88*/
      ChatCollection::DisableOldInvites((ChatCollection *)this, nullptr); /*0x837ea0*/
      v355 = System::String::Concat( /*0x837ebc*/
               (String *)"<color=#21bcff>",
               v354->username_punctuated,
               (String *)" invited you to play!</color>",
               nullptr);
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::System::Collections::Generic::Dictionary<System::String,System::String>); /*0x837ec4*/
      if ( !this ) /*0x837ec8*/
        goto LABEL_639; /*0x837ec8*/
      v356 = (Dictionary_2_System_Object_System_Object_ *)this; /*0x837ee0*/
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Dictionary( /*0x837ee4*/
        (Dictionary_2_System_Object_System_Object_ *)this,
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Dictionary);
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x837f00*/
        v356,
        (Object *)"text",
        (Object *)"JOIN",
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x837f1c*/
        v356,
        (Object *)"action",
        (Object *)"accept_invite",
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      v357 = System::Byte::ToString(&v464, nullptr); /*0x837f28*/
      if ( v357 ) /*0x837f44*/
        v358 = (Object *)v357; /*0x837f44*/
      else
        v358 = (Object *)""; /*0x837f44*/
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x837f4c*/
        v356,
        (Object *)"type",
        v358,
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      if ( (unsigned int)v464.m_value - 1 <= 1 ) /*0x837f5c*/
        System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x837f70*/
          v356,
          (Object *)"server_name",
          v335,
          MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x837f84*/
        v356,
        (Object *)"username",
        (Object *)v333,
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      if ( !byte_27E6BD4 ) /*0x837f98*/
      {
        this = (FriendServerReceiver *)sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x837fa4*/
        byte_27E6BD4 = 1; /*0x837fac*/
      }
      v149 = receiver; /*0x837fb8*/
      v359 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x837fc4*/
      if ( !v359 ) /*0x837fc8*/
        goto LABEL_639; /*0x837fc8*/
      icon_invite = v359->icon_invite; /*0x837fd0*/
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::chat_log); /*0x837fd4*/
      if ( !this ) /*0x837fd8*/
        goto LABEL_639; /*0x837fd8*/
      v361 = (String **)&StringLiteral__they_invited_me_; /*0x837fe0*/
      goto LABEL_436; /*0x837fe4*/
    case 0x29u: /*0x835908*/
      v190 = Packet::GetString(pkt, nullptr); // // case 0x29: ACCEPT_INVITE - server telling client to accept/process invite /*0x836200*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x836204*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x836210*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x83621c*/
      v191 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x836228*/
      v192 = System::String::op_Equality(v191, (String *)"Game", nullptr); /*0x836248*/
      if ( !byte_27E6BD5 ) /*0x83624c*/
      {
        sub_73C778(&TypeInfo::FriendServerSender, incoming); /*0x83625c*/
        byte_27E6BD5 = 1; /*0x836264*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerSender->static_fields->Instance; /*0x836270*/
      if ( !this ) /*0x836274*/
        goto LABEL_639; /*0x836274*/
      if ( v192 ) /*0x836278*/
        FriendServerSender::SendYouMayJoinMyWorldNow((FriendServerSender *)this, v190, 0, (String *)"", nullptr); /*0x83628c*/
      else
        FriendServerSender::SendAcceptInviteFailed((FriendServerSender *)this, v190, 0, nullptr); /*0x837cc0*/
      return; /*0x836290*/
    case 0x2Au: /*0x835908*/
      v214 = Packet::GetString(pkt, nullptr); // // case 0x2A: JOIN_FAILED - could not join (friend offline or went to main menu) /*0x83660c*/
      v215 = Packet::GetByte(pkt, nullptr); /*0x83661c*/
      if ( v215 == 1 ) /*0x836624*/
      {
        v216 = TypeInfo::PopupControl->static_fields; /*0x8384b0*/
        v217 = (String **)&StringLiteral__is_no_longer_online; /*0x8384b4*/
      }
      else
      {
        if ( v215 ) /*0x836628*/
          return; /*0x836628*/
        v216 = TypeInfo::PopupControl->static_fields; /*0x836634*/
        v217 = (String **)&StringLiteral__went_to_the_Main_Menu; /*0x836638*/
      }
      v380 = (FriendServerReceiver *)v216->Instance; /*0x8384c0*/
      this = (FriendServerReceiver *)System::String::Concat((String *)"Could not join!\n", v214, *v217, nullptr); /*0x8384cc*/
      if ( !v380 ) /*0x8384d0*/
        goto LABEL_639; /*0x8384d0*/
      v243 = (String *)this; /*0x8384d4*/
      this = v380; /*0x8384dc*/
LABEL_483:
      PopupControl::ShowMessage((PopupControl *)this, v243, PopupControl_context__Enum_message, nullptr); /*0x8384e0*/
      return; /*0x8384e8*/
    case 0x2Bu: /*0x835908*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor )// // case 0x2B: HIDE_POPUPS - hide all popups /*0x836d00*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x836d08*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x836d14*/
      v266 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x836d20*/
      if ( !System::String::op_Equality(v266, (String *)"Game", nullptr) ) /*0x836d38*/
        return; /*0x836d38*/
      this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance; /*0x836d44*/
      if ( !this ) /*0x836d48*/
        goto LABEL_639; /*0x836d48*/
      PopupControl::HideAll((PopupControl *)this, nullptr); /*0x836d50*/
      return; /*0x836d54*/
    case 0x2Cu: /*0x835908*/
      v218 = Packet::GetString(pkt, nullptr); // // case 0x2C: FRIEND_WORLD_UPDATE - friend's world/location string updated /*0x836650*/
      v220 = FriendServerReceiver::GetFriendByUsername(receiver, v218, v219); /*0x83665c*/
      if ( !v220 ) /*0x836660*/
        return; /*0x836660*/
      v222 = v220; /*0x83666c*/
      FriendServerReceiver::UnpackWorldString((FriendServerReceiver *)v220, v220, incominga, v221); /*0x836670*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x836678*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x836680*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x83668c*/
      v223 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x836698*/
      if ( !System::String::op_Equality(v223, (String *)"Game", nullptr) ) /*0x8366b0*/
        return; /*0x8366b0*/
      if ( !byte_27E6BD4 ) /*0x8366bc*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x8366c8*/
        byte_27E6BD4 = 1; /*0x8366d0*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x8366e4*/
      if ( !this ) /*0x8366e8*/
        goto LABEL_639; /*0x8366e8*/
      if ( *((_DWORD *)this + 26) == 4 ) /*0x8366f4*/
        goto LABEL_407; /*0x8366f4*/
      if ( *((_DWORD *)this + 26) != 6 || !System::String::op_Equality(*((String **)this + 22), v218, nullptr) ) /*0x836714*/
        return; /*0x836714*/
      if ( !byte_27E6BD4 ) /*0x836720*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x83672c*/
        byte_27E6BD4 = 1; /*0x836734*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x836748*/
      if ( !this ) /*0x83674c*/
        goto LABEL_639; /*0x83674c*/
      FriendServerInterface::RedrawChat((FriendServerInterface *)this, v222->chat, method); /*0x836754*/
      return; /*0x836758*/
    case 0x2Du: /*0x835908*/
      v339 = Packet::GetString(pkt, nullptr); // // case 0x2D: FRIEND_JOIN_REQUEST - friend wants to join your game (ALLOW button) /*0x8379e4*/
      v465.m_value = Packet::GetByte(pkt, nullptr); /*0x837a00*/
      if ( (unsigned __int8)(v465.m_value - 1) > 1u ) /*0x837a04*/
        v341 = (Object *)""; /*0x837ff0*/
      else
        v341 = (Object *)Packet::GetString(pkt, nullptr); /*0x837a14*/
      v362 = FriendServerReceiver::GetFriendByUsername(receiver, v339, v340); /*0x837ffc*/
      if ( !v362 ) /*0x838000*/
        return; /*0x838000*/
      v354 = v362; /*0x838004*/
      this = (FriendServerReceiver *)v362->chat; /*0x838008*/
      if ( !this ) /*0x83800c*/
        goto LABEL_639; /*0x83800c*/
      ChatCollection::DisableOldJoins((ChatCollection *)this, nullptr); /*0x838024*/
      v355 = System::String::Concat( /*0x838040*/
               (String *)"<color=#30ff8d>",
               v354->username_punctuated,
               (String *)" wishes to join your game</color>",
               nullptr);
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::System::Collections::Generic::Dictionary<System::String,System::String>); /*0x838048*/
      if ( !this ) /*0x83804c*/
        goto LABEL_639; /*0x83804c*/
      v356 = (Dictionary_2_System_Object_System_Object_ *)this; /*0x838064*/
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Dictionary( /*0x838068*/
        (Dictionary_2_System_Object_System_Object_ *)this,
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Dictionary);
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x838084*/
        v356,
        (Object *)"text",
        (Object *)"ALLOW",
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x8380a0*/
        v356,
        (Object *)"action",
        (Object *)"accept_other_join",
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      v363 = System::Byte::ToString(&v465, nullptr); /*0x8380ac*/
      if ( v363 ) /*0x8380c8*/
        v364 = (Object *)v363; /*0x8380c8*/
      else
        v364 = (Object *)""; /*0x8380c8*/
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x8380d0*/
        v356,
        (Object *)"type",
        v364,
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      if ( (unsigned int)v465.m_value - 1 <= 1 ) /*0x8380e0*/
        System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x8380f4*/
          v356,
          (Object *)"server_name",
          v341,
          MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x838108*/
        v356,
        (Object *)"username",
        (Object *)v339,
        MethodInfo::System::Collections::Generic::Dictionary<System::String,System::String>::Add);
      if ( !byte_27E6BD4 ) /*0x83811c*/
      {
        this = (FriendServerReceiver *)sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x838128*/
        byte_27E6BD4 = 1; /*0x838130*/
      }
      v149 = receiver; /*0x83813c*/
      v365 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x838148*/
      if ( !v365 ) /*0x83814c*/
        goto LABEL_639; /*0x83814c*/
      icon_invite = v365->icon_want_to_join; /*0x838154*/
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::chat_log); /*0x838158*/
      if ( !this ) /*0x83815c*/
        goto LABEL_639; /*0x83815c*/
      v361 = (String **)&StringLiteral__they_want_to_join_me_; /*0x838164*/
LABEL_436:
      v148 = (chat_log *)this; /*0x838168*/
      chat_log::chat_log( /*0x838188*/
        (chat_log *)this,
        v355,
        *v361,
        icon_invite,
        0,
        (Dictionary_2_System_String_System_String_ *)v356,
        nullptr);
      this = (FriendServerReceiver *)v354->chat; /*0x83818c*/
      if ( !this ) /*0x838190*/
        goto LABEL_639; /*0x838190*/
      ChatCollection::AddLog((ChatCollection *)this, v148, nullptr); /*0x83819c*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x8381ac*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x8381b4*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x8381c0*/
      v366 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x8381cc*/
      this = (FriendServerReceiver *)System::String::op_Equality(v366, (String *)"Game", nullptr); /*0x8381e0*/
      if ( ((unsigned __int8)this & 1) != 0 ) /*0x8381e4*/
      {
        if ( !byte_27E6BD4 ) /*0x8381ec*/
        {
          sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x8381f8*/
          byte_27E6BD4 = 1; /*0x838200*/
        }
        this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x83820c*/
        if ( !this ) /*0x838210*/
          goto LABEL_639; /*0x838210*/
        v152 = v354; /*0x838214*/
LABEL_444:
        FriendServerInterface::FriendChatReceived((FriendServerInterface *)this, v152, v148, v151); /*0x838218*/
      }
      else
      {
        v367 = v354->chat; /*0x838224*/
        if ( !v367 ) /*0x838228*/
          goto LABEL_639; /*0x838228*/
LABEL_589:
        ++v367->n_unread; /*0x838eec*/
        ++v149->total_unread; /*0x838f00*/
      }
      return; /*0x838220*/
    case 0x2Eu: /*0x835908*/
      this = (FriendServerReceiver *)TypeInfo::PopupControl->static_fields->Instance;// // case 0x2E: REPORT_SUBMITTED - report was submitted successfully /*0x8361cc*/
      if ( !this ) /*0x8361d0*/
        goto LABEL_639; /*0x8361d0*/
      v189 = &StringLiteral_Report_submitted_u000AWe_will_review; /*0x8361d8*/
      goto LABEL_163; /*0x8361dc*/
    case 0x2Fu: /*0x835908*/
      v296 = (FriendServerReceiver *)Packet::GetByte(pkt, nullptr);// // case 0x2F: WARNING - show warning message /*0x837410*/
      if ( (_BYTE)v296 ) /*0x837418*/
        FriendServerReceiver::ShowWarning(v296, (uint8_t)v296, v297); /*0x837420*/
      return; /*0x837424*/
    case 0x34u: /*0x835908*/
      v337 = Packet::GetShort(pkt, nullptr); // // case 0x34: RECEIVE_GEMS - received gems notification /*0x8379b0*/
      FriendServerReceiver::ShowReceiveGems(receiver, v337, v338); /*0x8379bc*/
      return; /*0x8379c0*/
    case 0x37u: /*0x835908*/
      v131 = Packet::GetString(pkt, nullptr); // // case 0x37: TROPHY_RECEIVED - new trophy awarded to player /*0x8359fc*/
      v132 = Packet::GetString(incominga, nullptr); /*0x835a0c*/
      v133 = Packet::GetString(incominga, nullptr); /*0x835a1c*/
      v134 = Packet::GetString(incominga, nullptr); /*0x835a2c*/
      v135 = Packet::GetString(incominga, nullptr); /*0x835a3c*/
      v136 = Packet::GetString(incominga, nullptr); /*0x835a54*/
      this = (FriendServerReceiver *)sub_73C88C(TypeInfo::Trophy); /*0x835a60*/
      if ( !this ) /*0x835a64*/
        goto LABEL_639; /*0x835a64*/
      v137 = this; /*0x835a84*/
      Trophy::Trophy((Trophy *)this, v131, v132, v133, v134, v135, v136, nullptr); /*0x835a88*/
      this = (FriendServerReceiver *)v457->trophies; /*0x835a90*/
      if ( !this ) /*0x835a94*/
        goto LABEL_639; /*0x835a94*/
      v138 = this->m_CachedPtr; /*0x835a9c*/
      v139 = MethodInfo::System::Collections::Generic::List<Trophy>::Add; /*0x835aa0*/
      ++HIDWORD(this->recently_seen_players); /*0x835aa8*/
      if ( !v138 ) /*0x835aac*/
        goto LABEL_639; /*0x835aac*/
      v140 = SLODWORD(this->recently_seen_players); /*0x835ab0*/
      if ( (unsigned int)v140 >= v138[6] ) /*0x835abc*/
      {
        (*((void (**)(void))v139->klass->rgctx_data[11].rgctxDataDummy + 1))(); /*0x837a4c*/
      }
      else
      {
        v141 = (char *)&v138[2 * v140]; /*0x835ac4*/
        LODWORD(this->recently_seen_players) = v140 + 1; /*0x835ac8*/
        *((_QWORD *)v141 + 4) = v137; /*0x835acc*/
        sub_73C72C(v141 + 32); /*0x835ad8*/
      }
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x837a54*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x837a5c*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x837a68*/
      v343 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x837a74*/
      if ( !System::String::op_Equality(v343, (String *)"Game", nullptr) ) /*0x837a8c*/
        return; /*0x837a8c*/
      if ( !byte_27E6BD4 ) /*0x837a98*/
      {
        sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x837aa4*/
        byte_27E6BD4 = 1; /*0x837aac*/
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x837ac0*/
      if ( !this ) /*0x837ac4*/
        goto LABEL_639; /*0x837ac4*/
      if ( *((_DWORD *)this + 26) == 4 ) /*0x837ad0*/
      {
        FriendServerInterface::RedrawFriendsList((FriendServerInterface *)this, (MethodInfo *)incoming); /*0x837ad4*/
        if ( !byte_27E6BD4 ) /*0x837adc*/
        {
          sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x837ae8*/
          byte_27E6BD4 = 1; /*0x837af0*/
        }
      }
      this = (FriendServerReceiver *)TypeInfo::FriendServerInterface->static_fields->Instance; /*0x837afc*/
      if ( !this ) /*0x837b00*/
        goto LABEL_639; /*0x837b00*/
      FriendServerInterface::ShowNewGiftsNotif((FriendServerInterface *)this, (MethodInfo *)incoming); /*0x837b04*/
      return; /*0x837b08*/
    case 0x3Eu: /*0x835908*/
      if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor )// // case 0x3E: CONNECT_FAILED - ERROR_403 / failed to connect to server /*0x83703c*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x837044*/
      v466.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x837050*/
      v277 = UnityEngine::SceneManagement::Scene::get_name(&v466, nullptr); /*0x83705c*/
      this = (FriendServerReceiver *)System::String::op_Equality(v277, (String *)"Game", nullptr); /*0x837070*/
      if ( ((unsigned __int8)this & 1) == 0 ) /*0x837084*/
        goto LABEL_250; /*0x837084*/
      v278 = TypeInfo::WindowControl->static_fields->Instance; /*0x837090*/
      if ( !v278 ) /*0x837094*/
        goto LABEL_639; /*0x837094*/
      if ( v278->curr_miniwindow != 14 ) /*0x8370a0*/
        goto LABEL_250; /*0x8370a0*/
      if ( !byte_27E6BD4 ) /*0x8370a8*/
      {
        this = (FriendServerReceiver *)sub_73C778(&TypeInfo::FriendServerInterface, incoming); /*0x8370b4*/
        byte_27E6BD4 = 1; /*0x8370c0*/
      }
      v279 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x8370cc*/
      if ( !v279 ) /*0x8370d0*/
        goto LABEL_639; /*0x8370d0*/
      if ( v279->curr_screen != 1 ) /*0x8370dc*/
        goto LABEL_250; /*0x8370dc*/
      if ( !TypeInfo::FriendServerInterface->static_fields->Instance ) /*0x8370e8*/
        goto LABEL_639; /*0x8370e8*/
      v129 = (String **)&StringLiteral_ERROR_403u000A_color__26ccff_Somethi; /*0x8370f0*/
      v130 = 0; /*0x8370f4*/
LABEL_249:
      FriendServerInterface::ShowFailedToConnect((FriendServerInterface *)this, *v129, v130, v126); /*0x8370f8*/
LABEL_250:
      if ( !byte_27E6BD3 ) /*0x837108*/
        goto LABEL_457; /*0x837108*/
      goto LABEL_458; /*0x837108*/
    default:
      return;
  }
}