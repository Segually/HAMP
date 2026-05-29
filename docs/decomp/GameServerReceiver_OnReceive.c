// Void OnReceive(Packet)
void GameServerReceiver::OnReceive(GameServerReceiver *this, Packet *incoming, MethodInfo *method)
{
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
  __int64 v124; // x1
  __int64 v125; // x1
  __int64 v126; // x1
  __int64 v127; // x1
  __int64 v128; // x1
  __int64 v129; // x1
  __int64 v130; // x1
  __int64 v131; // x1
  __int64 v132; // x1
  __int64 v133; // x1
  __int64 v134; // x1
  __int64 v135; // x1
  __int64 v136; // x1
  __int64 v137; // x1
  __int64 v138; // x1
  __int64 v139; // x1
  __int64 v140; // x1
  __int64 v141; // x1
  __int64 v142; // x1
  __int64 v143; // x1
  __int64 v144; // x1
  __int64 v145; // x1
  __int64 v146; // x1
  __int64 v147; // x1
  __int64 v148; // x1
  __int64 v149; // x1
  __int64 v150; // x1
  __int64 v151; // x1
  __int64 v152; // x1
  __int64 v153; // x1
  __int64 v154; // x1
  __int64 v155; // x1
  __int64 v156; // x1
  __int64 v157; // x1
  __int64 v158; // x1
  __int64 v159; // x1
  __int64 v160; // x1
  __int64 v161; // x1
  __int64 v162; // x1
  __int64 v163; // x1
  __int64 v164; // x1
  __int64 v165; // x1
  String *name; // x0
  DateTime v167; // x0
  uint64_t v168; // x1
  struct Startup__Class **v169; // x2
  GameServerConnector *Instance; // x8
  Connection *game_server_connection; // x0
  int opcode_minus_1; // kr00_4
  GameServerConnector *game_connector; // x19
  Object *v174; // x20
  MobControl *v175; // x8
  String *v176; // x19
  MobControl *v177; // x8
  Object *v178; // x20
  uint64_t v179; // x20
  __int64 v180; // x8
  __int64 v181; // x8
  MobControl *v182; // x21
  __int64 v183; // x8
  __int64 v184; // x8
  String *v185; // x22
  Object *v186; // x0
  Object_1 *v187; // x19
  __int64 v188; // x8
  Object_1 *v189; // x19
  String *v190; // x24
  PerkData *v191; // x21
  int16_t v192; // w23
  String *v193; // x22
  int32_t v194; // w19
  BanditCampsControl *v195; // x8
  Object *v196; // x19
  BanditCampsControl *v197; // x8
  GameServerConnector *v198; // x8
  String *v199; // x21
  uint8_t v200; // w0
  uint8_t v201; // w19
  Object_1 *v202; // x22
  MethodInfo *v203; // x4
  MinigameMenu *v204; // x8
  int32_t curr_menu; // w20
  uint8_t v206; // w1
  struct PoolGameControl__Class *v207; // x0
  Object_1 *v208; // x20
  int32_t v209; // w20
  int32_t v210; // w0
  struct PoolGameControl__Class *v211; // x8
  int v212; // w19
  String *v213; // x22
  Packet *v214; // x21
  uint8_t v215; // w22
  GameServerReceiver *v216; // x0
  MethodInfo *v217; // x1
  int v218; // w20
  String *v219; // x22
  MobControl *v220; // x8
  MobControl *v221; // x8
  MobControl *v222; // x8
  uint64_t v223; // x23
  MobControl *v224; // x8
  GameObject *v225; // x23
  GameServerSender *v226; // x22
  Connection_priority__Enum v227; // w2
  Packet *v228; // x1
  int v229; // w20
  Object *v230; // x21
  GameServerSender *v231; // x8
  MobControl *v232; // x8
  GameServerSender *v233; // x8
  GameServerSender *v234; // x8
  struct PoolGameControl__Class *v235; // x0
  Object_1 *v236; // x19
  struct PoolGameControl__Class *v237; // x0
  int16_t v238; // w29
  int16_t v239; // w22
  int16_t v240; // w27
  int16_t v241; // w25
  int32_t v242; // w26
  Byte__Array *v243; // x20
  unsigned __int64 k; // x28
  String *persistentDataPath; // x19
  String *v246; // x21
  String *CurrentSlotFolder; // x0
  String *v248; // x19
  String *v249; // x0
  String *v250; // x0
  String *v251; // x0
  __int64 v252; // x8
  int32_t v253; // w24
  uint8_t v254; // w21
  uint8_t v255; // w25
  int32_t v256; // w22
  OnlineTeleporter *v257; // x23
  CustomTeleporterControl *v258; // x8
  OnlineTeleporter **p_teleporter_R; // x0
  __int64 v260; // x8
  uint64_t v261; // x0
  CustomTeleporterControl *v262; // x8
  CustomTeleporterControl *v263; // x8
  __int64 v264; // x8
  String *v265; // x23
  uint8_t v266; // w24
  int32_t v267; // w21
  int32_t v268; // w22
  struct MusicBoxControl__Class *v269; // x0
  uint64_t v270; // x21
  uint8_t v271; // w22
  String **v272; // x20
  uint8_t v273; // w0
  PopupControl__StaticFields *v274; // x8
  const char *const *v275; // x9
  Object *v276; // x21
  OnlinePlayerData *v277; // x22
  GameServerInterface *v278; // x8
  MobControl *v279; // x8
  GameServerInterface *v280; // x8
  MobControl *v281; // x19
  String *v282; // x20
  uint8_t v283; // w21
  MethodInfo *v284; // x4
  InventoryItem *v285; // x19
  String *v286; // x20
  int32_t v287; // w21
  BasketContents *v288; // x19
  Packet *v289; // x22
  GameServerReceiver *v290; // x0
  MethodInfo *v291; // x1
  int v292; // w20
  __int64 v293; // x1
  int v294; // w20
  int16_t v295; // w21
  int16_t v296; // w26
  int16_t v297; // w20
  int16_t v298; // w25
  uint8_t v299; // w27
  InventoryItem *v300; // x29
  ChunkElement *v301; // x28
  String *v302; // x0
  struct ChunkControl__Class *v303; // x8
  String *mp_cache_key; // x27
  GameServerConnector *v305; // x8
  String *v306; // x20
  MethodInfo *v307; // x2
  struct GameController__Class *v308; // x0
  int32_t v309; // w20
  BasketContents *v310; // x21
  String *v311; // x25
  String *v312; // x20
  int16_t v313; // w24
  int16_t v314; // w0
  struct ChunkControl__Class *v315; // x8
  int16_t v316; // w19
  int32_t v317; // w29
  int32_t v318; // w24
  String *v319; // x19
  bool IsChunkFullyLoadedOrMidload; // w0
  struct ChunkControl__Class *v321; // x8
  bool v322; // w25
  ChunkData *ChunkData; // x25
  char v324; // w29
  String *v325; // x20
  Packet *v326; // x19
  int v327; // w28
  unsigned int v328; // w22
  Dictionary_2_System_Object_System_Object_ *v329; // x23
  Object *v330; // x24
  __int64 v331; // x8
  struct MethodInfo *v332; // x9
  __int64 v333; // x10
  char *v334; // x0
  uint8_t v335; // w20
  int v336; // w8
  Object *v337; // x20
  int16_t v338; // w24
  int16_t v339; // w25
  int16_t v340; // w22
  int16_t v341; // w21
  String *v342; // x19
  ZoneDataControl *v343; // x8
  ZoneData *v344; // x8
  Object *v345; // x19
  ZoneDataControl__StaticFields *v346; // x8
  ZoneData *v347; // x9
  char v348; // w8
  String *v349; // x21
  String *v350; // x20
  int16_t v351; // w26
  int16_t v352; // w25
  int16_t v353; // w23
  int v354; // w19
  int32_t v355; // w27
  int v356; // w25
  String *v357; // x28
  String *v358; // x26
  String *v359; // x0
  String *v360; // x26
  String *v361; // x0
  String *v362; // x0
  String *v363; // x0
  Packet *v364; // x28
  String *v365; // x0
  String *v366; // x19
  String *v367; // x0
  uint64_t v368; // x19
  MethodInfo *v369; // x1
  __int64 v370; // x8
  unsigned __int64 v371; // x20
  struct GameController__Class *v372; // x8
  int32_t v373; // w19
  LootControl *v374; // x20
  GameController *v375; // x8
  BasketContents *LootChest; // x0
  struct inventory_ctr__Class *v377; // x8
  BasketContents *v378; // x20
  int32_t v379; // w1
  BasketContents *v380; // x2
  String *v381; // x21
  MethodInfo *v382; // x2
  GameServerReceiver *v383; // x0
  MethodInfo *v384; // x2
  GameServerReceiver *v385; // x0
  MethodInfo *v386; // x2
  GameServerInterface *v387; // x8
  GameServerInterface *v388; // x8
  uint64_t v389; // x19
  Object_1 *v390; // x20
  Object_1 *v391; // x20
  int v392; // w8
  String *v393; // x20
  int16_t v394; // w23
  List_1_System_String_ *v395; // x21
  int v396; // w22
  MethodInfo *v397; // x3
  String__Array *v398; // x8
  struct MethodInfo *v399; // x9
  __int64 v400; // x10
  uint64_t v401; // x1
  String__Array__Class **v402; // x0
  String *String; // x20
  Packet *v404; // x19
  int v405; // w27
  unsigned int NewUniqueId; // w22
  Dictionary_2_System_Object_System_Object_ *unique_ids_given_away; // x23
  Object *v408; // x24
  __int64 v409; // x8
  struct MethodInfo *v410; // x9
  __int64 v411; // x10
  ZoneDataControl *v412; // x8
  __int64 v413; // x8
  ZoneDataControl *v414; // x8
  Object *v415; // x21
  uint64_t v416; // x19
  GameServerInterface *v417; // x8
  GameServerInterface *v418; // x8
  uint64_t v419; // x0
  Object *v420; // x22
  String *v421; // x24
  MethodInfo *v422; // x3
  uint8_t Byte; // w19
  GameServerConnector *v424; // x8
  BOOL is_host_cached; // w10
  ConstructionControl *v426; // x19
  String *v427; // x21
  int16_t v428; // w22
  int16_t v429; // w23
  struct ChunkControl__Class *v430; // x8
  Object *ChunkString; // x21
  uint8_t v432; // w22
  String *v433; // x23
  ChunkData *Item; // x22
  GameServerSender *v435; // x8
  char v436; // w23
  GameServerSender *v437; // x8
  PerkData *v438; // x24
  int16_t v439; // w21
  String *v440; // x23
  String *v441; // x22
  GameServerReceiver *v442; // x0
  int32_t v443; // w25
  MethodInfo *v444; // x2
  GameServerReceiver *v445; // x0
  MethodInfo *v446; // x2
  String *v447; // x0
  String *v448; // x3
  InventoryItem *v449; // x26
  uint8_t v450; // w27
  String *v451; // x21
  int16_t v452; // w28
  int16_t v453; // w29
  int16_t v454; // w20
  String *v455; // x0
  struct ChunkControl__Class *v456; // x8
  String *v457; // x25
  int32_t v458; // w19
  String *v459; // x29
  struct ChunkControl__Class *v460; // x0
  Object *v461; // x25
  int32_t v462; // w20
  Byte__Array *v463; // x22
  unsigned __int64 m; // x21
  Texture2D *v465; // x19
  int v466; // w22
  int v467; // w0
  Object *v468; // x19
  FriendServerSender *v469; // x8
  GameServerConnector *v470; // x24
  __int64 v471; // x1
  GameServerConnector *v472; // x20
  GameServerConnector *v473; // x8
  GameServerSender *v474; // x24
  __int64 v475; // x1
  GameServerSender *v476; // x20
  List_1_System_Object_ *dateData; // x24
  __int64 v478; // x1
  GameServerConnector *v479; // x20
  GameServerConnector *v480; // x8
  int32_t v481; // w20
  char v482; // w8
  GameServerConnector *v483; // x8
  Object__Array *items; // x8
  struct MethodInfo *v485; // x9
  __int64 size; // x10
  uint64_t v487; // x1
  Object__Array__Class **v488; // x0
  String *v489; // x21
  String *v490; // x19
  String *v491; // x23
  char *v492; // x20
  String__Array *v493; // x19
  const char *v494; // x8
  String *v495; // x21
  String *v496; // x0
  struct CompanionController__Class *v497; // x8
  String *v498; // x19
  String *v499; // x24
  int v500; // w20
  uint8_t v501; // w0
  uint8_t v502; // w22
  String *v503; // x1
  PopupControl *v504; // x19
  char *v505; // x0
  char *v506; // x2
  int v507; // w8
  String *v508; // x19
  struct PoolGameControl__Class *v509; // x0
  Object_1 *v510; // x20
  int32_t v511; // w20
  int16_t v512; // w21
  int32_t v513; // w23
  Byte__Array *v514; // x22
  unsigned __int64 jj; // x24
  PoolGameRecording *v516; // x19
  __int64 v517; // x8
  int16_t v518; // w22
  List_1_System_Object_ *v519; // x21
  int v520; // w28
  String *v521; // x22
  int v522; // w20
  Object__Array *v523; // x8
  struct MethodInfo *v524; // x9
  __int64 v525; // x10
  Object__Array__Class **v526; // x0
  String *v527; // x20
  __int64 v528; // x0
  __int64 v529; // x1
  MethodInfo *v530; // x2
  uint8_t v531; // w24
  float v532; // s8
  float v533; // s9
  float v534; // s10
  int dateData_low; // w20
  ConstructionControl *v536; // x8
  List_1_System_Int32_ *online_unique_ids; // x22
  Int32__Array *v538; // x8
  struct MethodInfo *v539; // x9
  __int64 v540; // x10
  List_1_System_String_ *disabled_perks; // x8
  int32_t v542; // w2
  int v543; // w9
  __int64 v544; // x1
  int Short; // w20
  List_1_System_String_ *v546; // x22
  String__Array *v547; // x8
  struct MethodInfo *v548; // x9
  __int64 v549; // x10
  uint64_t v550; // x1
  String__Array__Class **v551; // x0
  GameServerConnector *v552; // x20
  struct CompanionController__Class *v553; // x0
  CompanionController *v554; // x20
  CompanionController *v555; // x8
  __int64 v556; // x0
  __int64 v557; // x1
  __int64 v558; // x2
  Object *v559; // x21
  GameServerSender *v560; // x22
  String *combat_name; // x0
  MethodInfo *v562; // x2
  struct PoolGameControl__Class *v563; // x0
  Object_1 *v564; // x19
  __int64 v565; // x8
  const char *const *v566; // x8
  String *v567; // x1
  String *v568; // x20
  String *v569; // x21
  String *v570; // x23
  String *GlobalString; // x0
  __int64 v572; // x8
  _BOOL8 v573; // x0
  __int64 v574; // x1
  __int64 v575; // x2
  String *v576; // x24
  chat_log *v577; // x19
  GameServerInterface *v578; // x8
  struct FriendServerReceiver__Class *v579; // x0
  String *v580; // x21
  int v581; // w8
  MethodInfo *v582; // x3
  int16_t v583; // w19
  int32_t v584; // w2
  String *v585; // x1
  IEnumerator *v586; // x1
  uint8_t v587; // w23
  MethodInfo *v588; // x3
  char v589; // w20
  MobControl *v590; // x8
  Object *v591; // x19
  MobControl *v592; // x8
  struct ChunkControl__Class *v593; // x8
  GameObject *v594; // x20
  ChunkControl *v595; // x21
  String *v596; // x21
  struct Object_1__Class *v597; // x0
  Object *v598; // x21
  int v599; // w22
  uint64_t v600; // x20
  __int64 v601; // x8
  struct MethodInfo *v602; // x9
  __int64 v603; // x10
  uint64_t v604; // x1
  __int64 v605; // x0
  MobControl *v606; // x8
  MobControl *v607; // x8
  String *v608; // x20
  String *v609; // x21
  __int64 v610; // x0
  __int64 v611; // x1
  MethodInfo *v612; // x2
  uint8_t v613; // w24
  float x; // s8
  float y; // s9
  float z; // s10
  int v617; // w20
  ConstructionControl *v618; // x8
  List_1_System_Int32_ *v619; // x21
  Int32__Array *v620; // x8
  struct MethodInfo *v621; // x9
  __int64 v622; // x10
  GameServerSender *v623; // x8
  String *v624; // x20
  MethodInfo *v625; // x2
  List_1_System_Object_ *v626; // x21
  GameServerInterface *v627; // x8
  Object *v628; // x22
  GameServerInterface *v629; // x8
  int v630; // w8
  int v631; // w20
  String *v632; // x21
  String *v633; // x20
  String *v634; // x22
  int16_t v635; // w23
  int16_t v636; // w26
  int16_t v637; // w25
  PlayerData *v638; // x19
  String *v639; // x0
  PlayerData *v640; // x19
  String *v641; // x0
  int32_t Long; // w20
  uint64_t v643; // x21
  struct inventory_ctr__Class *v644; // x0
  MobControl *v645; // x8
  Object *v646; // x19
  MobControl *v647; // x8
  Object *v648; // x20
  MobControl *v649; // x8
  GameObject *v650; // x19
  CreatureStruct *v651; // x20
  Object_1 *gameObject; // x19
  Object *v653; // x24
  int32_t v654; // w21
  int32_t v655; // w25
  int32_t v656; // w22
  MobControl *v657; // x8
  int v658; // w23
  MobControl *v659; // x8
  GameObject *v660; // x19
  int v661; // w20
  GameServerInterface *v662; // x8
  GameServerInterface *v663; // x8
  Object_1 *v664; // x19
  GameServerInterface *v665; // x8
  String *v666; // x20
  int32_t v667; // w19
  String *v668; // x0
  MobControl *v669; // x8
  MobControl *v670; // x8
  Object *v671; // x20
  int v672; // w28
  String *v673; // x26
  int32_t v674; // w29
  PerkData *v675; // x22
  int16_t v676; // w24
  String *v677; // x23
  int16_t v678; // w25
  String *v679; // x0
  MobControl *v680; // x8
  MobControl *v681; // x8
  Object *v682; // x21
  int v683; // w20
  Object *v684; // x23
  CreatureStruct *v685; // x24
  String *v686; // x25
  MethodInfo *v687; // x2
  GameServerInterface *v688; // x8
  GameServerSender *v689; // x8
  int16_t v690; // w22
  int16_t v691; // w23
  int16_t v692; // w24
  uint8_t v693; // w26
  String *v694; // x25
  String__Array *v695; // x27
  unsigned __int64 v696; // x20
  _QWORD *vector; // x21
  uint64_t v698; // x29
  struct LandClaimControl__Class *v699; // x0
  InventoryItem *v700; // x24
  InventoryItem *v701; // x21
  uint8_t v702; // w28
  String *v703; // x22
  String *v704; // x20
  String *v705; // x0
  struct MusicBoxControl__Class *v706; // x0
  MusicBoxControl *v707; // x23
  String__Array *v708; // x26
  const char *v709; // x8
  Object *v710; // x22
  InventoryItem *v711; // x21
  InventoryItem *v712; // x20
  MobControl *v713; // x8
  uint64_t v714; // x19
  MobControl *v715; // x8
  Object *v716; // x22
  SharedCreature *v717; // x22
  String *v718; // x20
  String *v719; // x19
  Object_1 *PlayerByUsername; // x20
  char v721; // w21
  Object *v722; // x20
  int32_t v723; // w19
  Object *v724; // x19
  GameServerInterface *v725; // x8
  GameServerInterface *v726; // x8
  struct PoolGameControl__Class *v727; // x0
  Object_1 *v728; // x20
  int32_t v729; // w0
  struct PoolGameControl__Class *v730; // x8
  int v731; // w19
  MobControl *v732; // x8
  Object *v733; // x19
  MobControl *v734; // x8
  Object *v735; // x19
  GameObject *v736; // x19
  Object_1 *v737; // x0
  String *v738; // x26
  Object *v739; // x25
  String *v740; // x0
  MobControl *v741; // x8
  Object *v742; // x19
  MobControl *v743; // x8
  MobControl *v744; // x8
  String *v745; // x20
  int32_t v746; // w28
  String *v747; // x25
  PerkData *v748; // x22
  int16_t v749; // w24
  String *v750; // x23
  char v751; // w19
  String *v752; // x0
  MobControl *v753; // x8
  MobControl *v754; // x8
  Object *v755; // x25
  Int32__Array *v756; // x20
  unsigned __int64 kk; // x21
  struct PoolGameControl__Class *v758; // x0
  Object_1 *v759; // x19
  struct PoolGameControl__Class *v760; // x0
  Object *v761; // x29
  String *v762; // x25
  int16_t v763; // w26
  int16_t v764; // w22
  int16_t v765; // w27
  int16_t v766; // w21
  String *v767; // x23
  bool v768; // w19
  String *v769; // x0
  MobControl *v770; // x8
  Object *v771; // x28
  MobControl *v772; // x8
  MobControl *v773; // x8
  GameObject *v774; // x19
  Object *v775; // x20
  MobControl *v776; // x8
  char v777; // w19
  MobControl *v778; // x8
  MobControl *v779; // x8
  Object *v780; // x19
  MobControl *v781; // x8
  GameServerConnector *v782; // x8
  String *v783; // x0
  FriendServerInterface *v784; // x8
  Sprite *default_server_icon; // x29
  String *v786; // x27
  chat_log *v787; // x19
  GameServerInterface *v788; // x8
  GameServerConnector *v789; // x8
  __int64 v790; // x1
  __int64 v791; // x2
  MethodInfo *v792; // x3
  Object *current; // x19
  GameServerInterface *v794; // x0
  GameController *v795; // x21
  GameServerConnector *v796; // x8
  GameController *v797; // x21
  GameServerConnector *v798; // x8
  MethodInfo *v799; // x3
  String *SavedPlayerZoneOnServer; // x21
  GameServerConnector *v801; // x20
  GameServerConnector *v802; // x8
  Object_1 *v803; // x19
  TradingTableControl *v804; // x8
  BOOL other_player_has_joined; // w19
  List_1_System_Object_ *v806; // x24
  List_1_System_Object_ *v807; // x23
  __int64 v808; // x1
  __int64 v809; // x2
  List_1_System_Object_ *full_bandit_camps_sent_to_server; // x0
  Object *v811; // x24
  _BOOL8 v812; // x0
  __int64 v813; // x1
  __int64 v814; // x2
  Object__Array *v815; // x8
  struct MethodInfo *v816; // x9
  __int64 v817; // x10
  Object__Array__Class **v818; // x0
  __int64 v819; // x1
  __int64 v820; // x2
  List_1_System_String_ *v821; // x0
  String__Array *v822; // x8
  struct MethodInfo *v823; // x9
  __int64 v824; // x10
  String__Array__Class **v825; // x8
  Packet *v826; // x21
  __int64 v827; // x1
  __int64 v828; // x2
  BanditCampsControl *v829; // x0
  BanditCampInstance *BanditCampInstanceByName; // x0
  __int64 v831; // x1
  __int64 v832; // x2
  GameServerReceiver *v833; // x0
  MethodInfo *v834; // x1
  GameServerConnector *v835; // x8
  Vector3__StaticFields *static_fields; // x8
  Packet *v837; // x19
  ZoneData *v838; // x20
  List_1_System_Object_ *v839; // x20
  GameServerReceiver *v840; // x0
  MethodInfo *v841; // x1
  Vector3__StaticFields *v842; // x8
  int32_t j; // w25
  Object *v844; // x0
  ZoneDataControl *v845; // x26
  ZoneData *v846; // x26
  GameServerConnector *v847; // x8
  struct QuestControl__Class *v848; // x0
  WindowControl *v849; // x8
  CustomTeleporterControl *v850; // x8
  OnlineTeleporter *teleporter_L; // x8
  String *v852; // x19
  __int64 v853; // x8
  Dictionary_2_System_Object_System_Object_ *monitor; // x8
  const char *v855; // x8
  const char *v856; // x8
  struct CompanionController__Class *v857; // x8
  String *v858; // x20
  CompanionController *v859; // x8
  Sprite *companion_died_ico; // x21
  chat_log *v861; // x19
  GameServerInterface *v862; // x8
  CustomTeleporterControl *v863; // x8
  __int64 v864; // x8
  __int64 v865; // x8
  __int64 v866; // x8
  CustomTeleporterControl *v867; // x8
  struct MusicBoxControl__Class *v868; // x0
  MusicBoxControl *v869; // x19
  String__Array *v870; // x20
  const char *v871; // x8
  GameServerConnector *v872; // x8
  GameServerSender *v873; // x8
  GameServerSender *v874; // x8
  GameServerSender *v875; // x8
  String *v876; // x22
  int16_t v877; // w23
  int16_t v878; // w20
  int16_t v879; // w25
  int32_t CorrespondingTelePage; // w19
  int v881; // w20
  uint8_t v882; // w21
  ZoneDataControl *v883; // x8
  ZoneData *v884; // x8
  ZoneDataControl *v885; // x8
  ZoneData *v886; // x8
  ZoneDataControl *v887; // x8
  ZoneData *curr_zonedata_cache; // x8
  struct ChunkControl__Class *v889; // x0
  int v890; // w24
  BanditCampsControl *v891; // x8
  uint64_t v892; // x23
  BanditCampsControl *v893; // x8
  GameServerSender *v894; // x8
  struct ChunkControl__Class *v895; // x0
  struct ChunkControl__Class *v896; // x0
  MobControl *v897; // x8
  GameObject *v898; // x21
  PerkControl *v899; // x8
  GameObject **p_prefab_darksword_kill; // x8
  PerkControl *v901; // x8
  CustomTeleporterControl *v902; // x8
  OnlineTeleporter *teleporter_mid; // x8
  __int64 v904; // x8
  MethodInfo *v905; // x2
  int32_t v906; // w1
  Int32__Array *v907; // x20
  unsigned __int64 n; // x21
  struct GameController__Class *v909; // x0
  Object_1 *v910; // x23
  MethodInfo *v911; // x5
  MinigameMenu *v912; // x8
  Int32__Array *v913; // x22
  unsigned __int64 ii; // x20
  struct PoolGameControl__Class *v915; // x0
  Object_1 *v916; // x19
  MethodInfo *v917; // x5
  struct PoolGameControl__Class *v918; // x0
  String *v919; // x0
  String *v920; // x0
  String *v921; // x0
  struct LandClaimControl__Class *v922; // x0
  String *item_name; // x0
  String *v924; // x0
  String *v925; // x0
  struct LandClaimControl__Class *v926; // x0
  int v927; // w22
  String *v928; // x24
  MethodInfo *v929; // x2
  GameServerReceiver *v930; // x0
  MethodInfo *v931; // x2
  GameServerReceiver *v932; // x0
  MethodInfo *v933; // x2
  MobControl *v934; // x8
  MobControl *v935; // x8
  Object *v936; // x24
  GameServerSender *v937; // x8
  Object__Array *v938; // x8
  struct MethodInfo *v939; // x9
  __int64 v940; // x10
  Object__Array__Class **v941; // x0
  GameServerSender *v942; // x8
  __int64 v943; // x8
  struct MethodInfo *v944; // x9
  __int64 v945; // x10
  __int64 v946; // x8
  int32_t v947; // w20
  Object *v948; // x0
  uint64_t v949; // x27
  const char *v950; // x8
  uint64_t v951; // x27
  const char *v952; // x8
  uint64_t v953; // x27
  const char *v954; // x8
  uint64_t v955; // x27
  struct ChunkControl__Class *v956; // x0
  GameServerConnector *v957; // x8
  uint64_t v958; // x21
  const char *v959; // x8
  uint64_t v960; // x21
  struct ChunkControl__Class *v961; // x0
  Packet *v962; // x20
  GameServerReceiver *v963; // x0
  MethodInfo *v964; // x1
  CustomTeleporterControl *v965; // x8
  OnlineTeleporter *teleporter_R; // x8
  __int64 v967; // x8
  Image *v968; // x19
  PopupControl *v969; // x19
  uint64_t v970; // x22
  String **v971; // x21
  String *v972; // x1
  uint8_t v973; // w2
  PopupControl *v974; // x19
  String *v975; // x23
  GameServerSender *v976; // x8
  double v977; // d8
  Object *key; // x27
  Object *value; // x28
  DateTime v980; // x1
  DateTime v981; // x2
  double TotalSeconds; // d0
  uint8_t v983; // w3
  String *v984; // x2
  GameServerSender *v985; // x8
  GameServerSender *v986; // x8
  __int64 v987; // x0
  uint8_t v988; // [xsp+30h] [xbp-1B0h]
  uint8_t v989; // [xsp+34h] [xbp-1ACh]
  String *str; // [xsp+38h] [xbp-1A8h]
  int16_t stra; // [xsp+38h] [xbp-1A8h]
  int16_t v992; // [xsp+44h] [xbp-19Ch]
  int16_t v993; // [xsp+44h] [xbp-19Ch]
  int16_t v994; // [xsp+44h] [xbp-19Ch]
  String *zone; // [xsp+48h] [xbp-198h]
  String *zonea; // [xsp+48h] [xbp-198h]
  String *zoneb; // [xsp+48h] [xbp-198h]
  String *zonec; // [xsp+48h] [xbp-198h]
  String *zoned; // [xsp+48h] [xbp-198h]
  int16_t zonee; // [xsp+48h] [xbp-198h]
  String *incominga; // [xsp+50h] [xbp-190h]
  InventoryItem *incomingb; // [xsp+50h] [xbp-190h]
  Dictionary_2_TKey_TValue_Enumerator_System_Object_System_Object_ v1003; // [xsp+58h] [xbp-188h] BYREF
  List_1_T_Enumerator_System_Object_ v1004; // [xsp+80h] [xbp-160h] BYREF
  TimeSpan v1005; // [xsp+98h] [xbp-148h] BYREF
  Dictionary_2_TKey_TValue_Enumerator_System_Object_System_Object_ v1006; // [xsp+A0h] [xbp-140h] BYREF
  List_1_T_Enumerator_System_Object_ v1007; // [xsp+D0h] [xbp-110h] BYREF
  List_1_T_Enumerator_System_Object_ i; // [xsp+F0h] [xbp-F0h] BYREF
  __int64 v1009; // [xsp+108h] [xbp-D8h] BYREF
  Int32 v1010[2]; // [xsp+110h] [xbp-D0h] BYREF
  DateTime v1011; // [xsp+118h] [xbp-C8h] BYREF
  Int32 v1012; // [xsp+124h] [xbp-BCh] BYREF
  Int32 v1013[2]; // [xsp+128h] [xbp-B8h] BYREF
  __int64 v1014; // [xsp+130h] [xbp-B0h] BYREF
  Scene v1015; // [xsp+138h] [xbp-A8h] BYREF
  DateTime v1016; // 0:x0.8
  Vector3 v1017; // 0:kr140_12.12
  Vector3 v1018; // 0:kr160_12.12
  Vector3 v1019; // 0:kr174_12.12
  Vector3 v1020; // 0:kr180_12.12
  Vector3 v1021; // 0:kr1A0_12.12
  Vector3 v1022; // 0:kr1B4_12.12
  Vector3 v1023; // 0:kr1C0_12.12
  Vector3 v1024; // 0:kr1E0_12.12
  Vector3 v1025; // 0:kr1F4_12.12
  Vector3 v1026; // 0:kr200_12.12
  Vector3 v1027; // 0:kr220_12.12
  Vector3 SavedPlayerPositionOnServer; // 0:kr234_12.12
  Vector3 v1029; // 0:kr240_12.12
  Vector3 v1030; // 0:kr254_12.12
  Quaternion v1031; // 0:kr190_16.16
  Quaternion rotation; // 0:kr210_16.16
  Quaternion v1033; // 0:kr260_16.16
  Vector2 v1034; // 0:s0.4,4:s1.4
  Vector2 v1035; // 0:s4.4,4:s5.4
  Vector3 v1036; // 0:s0.4,4:s1.4,8:s2.4
  Vector3 v1037; // 0:s0.4,4:s1.4,8:s2.4
  Vector3 v1038; // 0:s0.4,4:s1.4,8:s2.4
  Vector3 v1039; // 0:s0.4,4:s1.4,8:s2.4
  Vector3 position; // 0:s0.4,4:s1.4,8:s2.4
  Color OverheadNameColor; // 0:s0.4,4:s1.4,8:s2.4,12:s3.4

  if ( (byte_27E6C26 & 1) == 0 ) /*0x84f1e8*/
  {
    sub_73C778(&TypeInfo::System::Action, incoming); /*0x84f1f4*/
    sub_73C778(&TypeInfo::BanditCampsControl, v5); /*0x84f200*/
    sub_73C778(&TypeInfo::BasketContents, v6); /*0x84f20c*/
    sub_73C778(&TypeInfo::System::Byte, v7); /*0x84f218*/
    sub_73C778(&TypeInfo::System::Char, v8); /*0x84f224*/
    sub_73C778(&TypeInfo::ChunkControl, v9); /*0x84f230*/
    sub_73C778(&TypeInfo::ChunkData, v10); /*0x84f23c*/
    sub_73C778(&TypeInfo::ChunkElement, v11); /*0x84f248*/
    sub_73C778(&TypeInfo::CompanionController, v12); /*0x84f254*/
    sub_73C778(&TypeInfo::ConstructionControl, v13); /*0x84f260*/
    sub_73C778(&TypeInfo::CreatureStruct, v14); /*0x84f26c*/
    sub_73C778(&TypeInfo::CustomTeleporterControl, v15); /*0x84f278*/
    sub_73C778(&TypeInfo::System::DateTime, v16); /*0x84f284*/
    sub_73C778(&TypeInfo::UnityEngine::Debug, v17); /*0x84f290*/
    sub_73C778( /*0x84f29c*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::Add,
      v18);
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::Add, v19); /*0x84f2a8*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::Add, v20); /*0x84f2b4*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,BanditCampInstance>::Add, v21); /*0x84f2c0*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::Add, v22); /*0x84f2cc*/
    sub_73C778( /*0x84f2d8*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::Clear,
      v23);
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::ContainsKey, v24); /*0x84f2e4*/
    sub_73C778( /*0x84f2f0*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::ContainsKey,
      v25);
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,CreatureStruct>::ContainsKey, v26); /*0x84f2fc*/
    sub_73C778( /*0x84f308*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::ContainsKey,
      v27);
    sub_73C778( /*0x84f314*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::ContainsKey,
      v28);
    sub_73C778( /*0x84f320*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,BanditCampInstance>::ContainsKey,
      v29);
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::ContainsKey, v30); /*0x84f32c*/
    sub_73C778( /*0x84f338*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey,
      v31);
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::GetEnumerator, v32); /*0x84f344*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::Remove, v33); /*0x84f350*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::Remove, v34); /*0x84f35c*/
    sub_73C778( /*0x84f368*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::Remove,
      v35);
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,CreatureStruct>::Remove, v36); /*0x84f374*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::get_Count, v37); /*0x84f380*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,BanditCampInstance>::get_Item, v38); /*0x84f38c*/
    sub_73C778( /*0x84f398*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item,
      v39);
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::get_Item, v40); /*0x84f3a4*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::get_Item, v41); /*0x84f3b0*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::get_Item, v42); /*0x84f3bc*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::get_Item, v43); /*0x84f3c8*/
    sub_73C778( /*0x84f3d4*/
      &MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::get_Item,
      v44);
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,CreatureStruct>::get_Item, v45); /*0x84f3e0*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::set_Item, v46); /*0x84f3ec*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::set_Item, v47); /*0x84f3f8*/
    sub_73C778(&MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::set_Item, v48); /*0x84f404*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::Dispose, v49); /*0x84f410*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<Friend>::Dispose, v50); /*0x84f41c*/
    sub_73C778( /*0x84f428*/
      &MethodInfo::System::Collections::Generic::Dictionary_2_TKey_TValue_::Enumerator<System::String,ChunkData>::Dispose,
      v51);
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ActiveCompanion>::Dispose, v52); /*0x84f434*/
    sub_73C778( /*0x84f440*/
      &MethodInfo::System::Collections::Generic::Dictionary_2_TKey_TValue_::Enumerator<System::String,ChunkData>::MoveNext,
      v53);
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ActiveCompanion>::MoveNext, v54); /*0x84f44c*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<Friend>::MoveNext, v55); /*0x84f458*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::MoveNext, v56); /*0x84f464*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::get_Current, v57); /*0x84f470*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<Friend>::get_Current, v58); /*0x84f47c*/
    sub_73C778( /*0x84f488*/
      &MethodInfo::System::Collections::Generic::Dictionary_2_TKey_TValue_::Enumerator<System::String,ChunkData>::get_Current,
      v59);
    sub_73C778(&MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ActiveCompanion>::get_Current, v60); /*0x84f494*/
    sub_73C778(&TypeInfo::FriendServerInterface, v61); /*0x84f4a0*/
    sub_73C778(&TypeInfo::FriendServerReceiver, v62); /*0x84f4ac*/
    sub_73C778(&TypeInfo::FriendServerSender, v63); /*0x84f4b8*/
    sub_73C778(&TypeInfo::GameController, v64); /*0x84f4c4*/
    sub_73C778(&MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>, v65); /*0x84f4d0*/
    sub_73C778(&MethodInfo::UnityEngine::GameObject::GetComponent<PerkReceiver>, v66); /*0x84f4dc*/
    sub_73C778(&MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>, v67); /*0x84f4e8*/
    sub_73C778(&TypeInfo::GameServerConnector, v68); /*0x84f4f4*/
    sub_73C778(&TypeInfo::GameServerInterface, v69); /*0x84f500*/
    sub_73C778(&TypeInfo::GameServerSender, v70); /*0x84f50c*/
    sub_73C778(&TypeInfo::GameplayGUIControl, v71); /*0x84f518*/
    sub_73C778(&TypeInfo::System::Int32, v72); /*0x84f524*/
    sub_73C778(&MethodInfo::System::Collections::Generic::KeyValuePair<System::String,ChunkData>::get_Key, v73); /*0x84f530*/
    sub_73C778(&MethodInfo::System::Collections::Generic::KeyValuePair<System::String,ChunkData>::get_Value, v74); /*0x84f53c*/
    sub_73C778(&TypeInfo::LandClaimControl, v75); /*0x84f548*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<int>::Add, v76); /*0x84f554*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::Add, v77); /*0x84f560*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::Clear, v78); /*0x84f56c*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::Contains, v79); /*0x84f578*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<Friend>::GetEnumerator, v80); /*0x84f584*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<ActiveCompanion>::GetEnumerator, v81); /*0x84f590*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::GetEnumerator, v82); /*0x84f59c*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<int>::Remove, v83); /*0x84f5a8*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<UnityEngine::GameObject>::Remove, v84); /*0x84f5b4*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::Remove, v85); /*0x84f5c0*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<int>::List, v86); /*0x84f5cc*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::List, v87); /*0x84f5d8*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::get_Count, v88); /*0x84f5e4*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<CraftingSlot>::get_Item, v89); /*0x84f5f0*/
    sub_73C778(&MethodInfo::System::Collections::Generic::List<System::String>::get_Item, v90); /*0x84f5fc*/
    sub_73C778(&TypeInfo::System::Collections::Generic::List<int>, v91); /*0x84f608*/
    sub_73C778(&TypeInfo::System::Collections::Generic::List<System::String>, v92); /*0x84f614*/
    sub_73C778(&TypeInfo::LootControl, v93); /*0x84f620*/
    sub_73C778(&TypeInfo::MinigameMenu, v94); /*0x84f62c*/
    sub_73C778(&TypeInfo::MobControl, v95); /*0x84f638*/
    sub_73C778(&TypeInfo::MusicBoxControl, v96); /*0x84f644*/
    sub_73C778(&TypeInfo::UnityEngine::Object, v97); /*0x84f650*/
    sub_73C778(&TypeInfo::OnlinePlayerData, v98); /*0x84f65c*/
    sub_73C778(&TypeInfo::OnlineTeleporter, v99); /*0x84f668*/
    sub_73C778(&TypeInfo::Packet, v100); /*0x84f674*/
    sub_73C778(&TypeInfo::System::IO::Path, v101); /*0x84f680*/
    sub_73C778(&TypeInfo::PerkControl, v102); /*0x84f68c*/
    sub_73C778(&TypeInfo::PerkData, v103); /*0x84f698*/
    sub_73C778(&TypeInfo::PlayerData, v104); /*0x84f6a4*/
    sub_73C778(&TypeInfo::PoolGameControl, v105); /*0x84f6b0*/
    sub_73C778(&TypeInfo::PoolGameRecording, v106); /*0x84f6bc*/
    sub_73C778(&TypeInfo::PopupControl, v107); /*0x84f6c8*/
    sub_73C778(&TypeInfo::QuestControl, v108); /*0x84f6d4*/
    sub_73C778(&TypeInfo::UnityEngine::SceneManagement::SceneManager, v109); /*0x84f6e0*/
    sub_73C778(&TypeInfo::Startup, v110); /*0x84f6ec*/
    sub_73C778(&TypeInfo::System::String, v111); /*0x84f6f8*/
    sub_73C778(&TypeInfo::UnityEngine::Texture2D, v112); /*0x84f704*/
    sub_73C778(&TypeInfo::System::TimeSpan, v113); /*0x84f710*/
    sub_73C778(&TypeInfo::TradingTableControl, v114); /*0x84f71c*/
    sub_73C778(&MethodInfo::GameServerReceiver::__c__DisplayClass18_0::_OnReceive_b__0, v115); /*0x84f728*/
    sub_73C778(&MethodInfo::GameServerReceiver::__c__DisplayClass18_0::_OnReceive_b__1, v116); /*0x84f734*/
    sub_73C778(&TypeInfo::GameServerReceiver::__c__DisplayClass18_0, v117); /*0x84f740*/
    sub_73C778(&TypeInfo::WindowControl, v118); /*0x84f74c*/
    sub_73C778(&TypeInfo::ZoneDataControl, v119); /*0x84f758*/
    sub_73C778(&StringLiteral_Game, v120); /*0x84f764*/
    sub_73C778(&StringLiteral___color__is_currently_trading_wi, v121); /*0x84f770*/
    sub_73C778(&StringLiteral__name_0, v122); /*0x84f77c*/
    sub_73C778(&StringLiteral__s__color__world, v123); /*0x84f788*/
    sub_73C778(&StringLiteral_You, v124); /*0x84f794*/
    sub_73C778(&StringLiteral___color__is_setting_up_a_game_u000AP, v125); /*0x84f7a0*/
    sub_73C778(&StringLiteral_Got__Create_Drop, v126); /*0x84f7ac*/
    sub_73C778(&StringLiteral___color__already_started_a_game_, v127); /*0x84f7b8*/
    sub_73C778(&StringLiteral_Music_Box, v128); /*0x84f7c4*/
    sub_73C778(&StringLiteral__0_results_found, v129); /*0x84f7d0*/
    sub_73C778(&StringLiteral_Other_player_left, v130); /*0x84f7dc*/
    sub_73C778(&StringLiteral__desc, v131); /*0x84f7e8*/
    sub_73C778(&StringLiteral_Could_not_start_gameu000A_color__43d, v132); /*0x84f7f4*/
    sub_73C778(&StringLiteral_default, v133); /*0x84f800*/
    sub_73C778(&StringLiteral___color__left_, v134); /*0x84f80c*/
    sub_73C778(&StringLiteral_Trade_with__color__43de4f_, v135); /*0x84f818*/
    sub_73C778(&StringLiteral_Could_not_joinu000A_color__43de4f_, v136); /*0x84f824*/
    sub_73C778(&StringLiteral____color__, v137); /*0x84f830*/
    sub_73C778(&StringLiteral__private_, v138); /*0x84f83c*/
    sub_73C778(&StringLiteral_sent_10_more_unique_ids, v139); /*0x84f848*/
    sub_73C778(&StringLiteral__color__abebff_, v140); /*0x84f854*/
    sub_73C778(&StringLiteral_teleporter_, v141); /*0x84f860*/
    sub_73C778(&StringLiteral___color__color__ff5252__killed_, v142); /*0x84f86c*/
    sub_73C778(&StringLiteral_Welcome_to__color__4acfff_, v143); /*0x84f878*/
    sub_73C778(&StringLiteral_Play_against__color__43de4f_, v144); /*0x84f884*/
    sub_73C778(&StringLiteral_you, v145); /*0x84f890*/
    sub_73C778(&StringLiteral__color__f2cb88_, v146); /*0x84f89c*/
    sub_73C778(&StringLiteral____color__5, v147); /*0x84f8a8*/
    sub_73C778(&StringLiteral__color__43de4f_, v148); /*0x84f8b4*/
    sub_73C778(&StringLiteral__unique_id_used_up__, v149); /*0x84f8c0*/
    sub_73C778(&StringLiteral___34, v150); /*0x84f8cc*/
    sub_73C778(&StringLiteral_Admin_Land_Claim, v151); /*0x84f8d8*/
    sub_73C778(&StringLiteral__3_day_Land_Claim, v152); /*0x84f8e4*/
    sub_73C778(&StringLiteral___color__0, v153); /*0x84f8f0*/
    sub_73C778(&StringLiteral_username_lower, v154); /*0x84f8fc*/
    sub_73C778(&StringLiteral___color__is_currently_playing_ag, v155); /*0x84f908*/
    sub_73C778(&StringLiteral_Yes, v156); /*0x84f914*/
    sub_73C778(&StringLiteral_LOCAL, v157); /*0x84f920*/
    sub_73C778(&StringLiteral__, v158); /*0x84f92c*/
    sub_73C778(&StringLiteral_No, v159); /*0x84f938*/
    sub_73C778(&StringLiteral_Received__launch_projectile, v160); /*0x84f944*/
    sub_73C778(&StringLiteral___color__is_currently_playing_ag_0, v161); /*0x84f950*/
    sub_73C778(&StringLiteral__8_day_Land_Claim, v162); /*0x84f95c*/
    sub_73C778(&StringLiteral_tele_graphic_, v163); /*0x84f968*/
    sub_73C778(&TypeInfo::chat_log, v164); /*0x84f974*/
    sub_73C778(&TypeInfo::inventory_ctr, v165); /*0x84f980*/
    byte_27E6C26 = 1; /*0x84f988*/
  }
  v1015.m_Handle = 0; /*0x84f994*/
  *(_QWORD *)&v1013[0].m_value = 0; /*0x84f998*/
  v1014 = 0; /*0x84f998*/
  v1012.m_value = 0; /*0x84f99c*/
  *(_QWORD *)&v1010[0].m_value = 0; /*0x84f9a0*/
  v1011._dateData = 0; /*0x84f9a0*/
  v1009 = 0; /*0x84f9a4*/
  memset(&i, 0, sizeof(i)); /*0x84f9a8*/
  memset(&v1007, 0, sizeof(v1007)); /*0x84f9b0*/
  v1005._ticks = 0; /*0x84f9b8*/
  memset(&v1006, 0, sizeof(v1006)); /*0x84f9bc*/
  memset(&v1004, 0, sizeof(v1004)); /*0x84f9c0*/
  if ( !TypeInfo::UnityEngine::SceneManagement::SceneManager->_1.cctor_finished_or_no_cctor ) /*0x84f9c8*/
    j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::SceneManagement::SceneManager); /*0x84f9d4*/
  v1015.m_Handle = UnityEngine::SceneManagement::SceneManager::GetActiveScene(nullptr).m_Handle; /*0x84f9e8*/
  name = UnityEngine::SceneManagement::Scene::get_name(&v1015, nullptr); /*0x84f9f4*/
  v167._dateData = System::String::op_Inequality(name, (String *)"Game", nullptr); /*0x84fa00*/
  if ( (v167._dateData & 1) != 0 ) /*0x84fa04*/
  {
    Instance = TypeInfo::GameServerConnector->static_fields->Instance; /*0x84fa10*/
    if ( !Instance ) /*0x84fa14*/
      goto LABEL_1546; /*0x84fa14*/
    game_server_connection = Instance->game_server_connection; /*0x84fa18*/
    if ( game_server_connection ) /*0x84fa1c*/
      Connection::Disconnect(game_server_connection, nullptr); /*0x84fa24*/
    return; /*0x84fa24*/
  }
  zone = (String *)this; /*0x84fa58*/
  if ( !incoming ) /*0x84fa5c*/
    goto LABEL_1546; /*0x84fa5c*/
  opcode_minus_1 = Packet::GetByte(incoming, nullptr) - 1; /*0x84fa74*/
  v167._dateData = (uint64_t)&MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>; /*0x84faa8*/
  v168 = (uint64_t)&MethodInfo::System::Collections::Generic::List<System::String>::Contains; /*0x84fb18*/
  v169 = &TypeInfo::Startup; /*0x84fb30*/
  switch ( opcode_minus_1 )
  {
    case 0:
      if ( !byte_27E6C86 ) // // case 0x01: PING /*0x84fb80*/
      {
        sub_73C778( /*0x84fb90*/
          &TypeInfo::GameServerConnector,
          &MethodInfo::System::Collections::Generic::List<System::String>::Contains);
        byte_27E6C86 = 1; /*0x84fb98*/
      }
      game_connector = TypeInfo::GameServerConnector->static_fields->Instance; /*0x84fbb4*/
      if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x84fbac*/
        j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x84fbbc*/
      v167._dateData = System::DateTime::get_UtcNow(nullptr)._dateData; /*0x84fbc4*/
      if ( !game_connector ) /*0x84fbc8*/
        goto LABEL_1546; /*0x84fbc8*/
      game_connector->last_server_ping = v167; /*0x84fbcc*/
      return; /*0x84fbd0*/
    case 1:
      v469 = TypeInfo::FriendServerSender->static_fields->Instance;// // case 0x02: JOIN /*0x8528d8*/
      if ( !v469 ) /*0x8528dc*/
        goto LABEL_1546; /*0x8528dc*/
      v469->sending_request_of_some_sort = 0; /*0x8528e0*/
      if ( !byte_27E6C86 ) /*0x852910*/
      {
        sub_73C778( /*0x85291c*/
          &TypeInfo::GameServerConnector,
          &MethodInfo::System::Collections::Generic::List<System::String>::Contains);
        byte_27E6C86 = 1; /*0x852924*/
      }
      v470 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x852938*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x85293c*/
      if ( !v470 ) /*0x852940*/
        goto LABEL_1546; /*0x852940*/
      v470->server_name = (String *)v167._dateData; /*0x852944*/
      sub_73C72C(&v470->server_name); /*0x852950*/
      if ( !byte_27E6C86 ) /*0x852958*/
      {
        sub_73C778(&TypeInfo::GameServerConnector, v471); /*0x852964*/
        byte_27E6C86 = 1; /*0x85296c*/
      }
      v472 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x852980*/
      v167._dateData = Packet::GetByte(incoming, nullptr); /*0x852984*/
      if ( !v472 ) /*0x852988*/
        goto LABEL_1546; /*0x852988*/
      v472->is_host_cached = LOBYTE(v167._dateData) == 1; /*0x8529a0*/
      v167._dateData = Packet::GetByte(incoming, nullptr); /*0x8529a4*/
      if ( !byte_27E6C86 ) /*0x8529b0*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x8529bc*/
        byte_27E6C86 = 1; /*0x8529c8*/
      }
      v473 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x8529d4*/
      if ( !v473 ) /*0x8529d8*/
        goto LABEL_1546; /*0x8529d8*/
      v473->pvp_enabled = 0; /*0x8529dc*/
      if ( !byte_27E6C85 ) /*0x8529e4*/
      {
        sub_73C778(&TypeInfo::GameServerSender, v168); /*0x8529f0*/
        byte_27E6C85 = 1; /*0x8529f8*/
      }
      v474 = TypeInfo::GameServerSender->static_fields->Instance; /*0x852a0c*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x852a10*/
      if ( !v474 ) /*0x852a14*/
        goto LABEL_1546; /*0x852a14*/
      v474->packet_validator_code = (String *)v167._dateData; /*0x852a18*/
      sub_73C72C(&v474->packet_validator_code); /*0x852a24*/
      if ( !byte_27E6C85 ) /*0x852a2c*/
      {
        sub_73C778(&TypeInfo::GameServerSender, v475); /*0x852a38*/
        byte_27E6C85 = 1; /*0x852a40*/
      }
      v476 = TypeInfo::GameServerSender->static_fields->Instance; /*0x852a54*/
      v167._dateData = Packet::GetShort(incoming, nullptr); /*0x852a58*/
      if ( !v476 ) /*0x852a5c*/
        goto LABEL_1546; /*0x852a5c*/
      v476->packet_validator_total_variation = SLOWORD(v167._dateData); /*0x852a64*/
      v167._dateData = sub_73C88C(TypeInfo::System::Collections::Generic::List<System::String>); /*0x852a6c*/
      if ( !v167._dateData ) /*0x852a70*/
        goto LABEL_1546; /*0x852a70*/
      dateData = (List_1_System_Object_ *)v167._dateData; /*0x852a7c*/
      System::Collections::Generic::List<System::Object>::List( /*0x852a84*/
        (List_1_System_Object_ *)v167._dateData,
        MethodInfo::System::Collections::Generic::List<System::String>::List);
      if ( !byte_27E6C86 ) /*0x852a8c*/
      {
        sub_73C778(&TypeInfo::GameServerConnector, v478); /*0x852a98*/
        byte_27E6C86 = 1; /*0x852aa0*/
      }
      v479 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x852ab4*/
      v167._dateData = Packet::GetShort(incoming, nullptr); /*0x852ab8*/
      if ( !v479 ) /*0x852abc*/
        goto LABEL_1546; /*0x852abc*/
      v479->n_others_in_game = SLOWORD(v167._dateData); /*0x852ac4*/
      if ( !byte_27E6C86 ) /*0x852ad0*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x852adc*/
        byte_27E6C86 = 1; /*0x852ae8*/
      }
      v480 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x852af4*/
      if ( !v480 ) /*0x852af8*/
        goto LABEL_1546; /*0x852af8*/
      if ( !v480->is_host_cached || !v480->n_others_in_game ) /*0x852b04*/
        goto LABEL_965; /*0x852b08*/
      v481 = 0; /*0x852b0c*/
      v482 = 1; /*0x852b14*/
      while ( 2 ) /*0x852b1c*/
      {
        if ( !v482 ) /*0x852b1c*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x852b24*/
          byte_27E6C86 = 1; /*0x852b2c*/
        }
        v483 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x852b38*/
        if ( !v483 ) /*0x852b3c*/
          goto LABEL_1546; /*0x852b3c*/
        if ( v481 < v483->n_others_in_game ) /*0x852b48*/
        {
          v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x852b54*/
          items = dateData->_items; /*0x852b5c*/
          v485 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x852b60*/
          ++dateData->_version; /*0x852b68*/
          if ( items ) /*0x852b6c*/
          {
            size = dateData->_size; /*0x852b70*/
            v487 = v167._dateData; /*0x852b78*/
            if ( (unsigned int)size >= items->max_length.size ) /*0x852b80*/
            {
              v167._dateData = (*((__int64 (__fastcall **)(List_1_System_Object_ *, uint64_t))v485->klass->rgctx_data[11].rgctxDataDummy /*0x852bb0*/
                                + 1))(
                                 dateData,
                                 v167._dateData);
            }
            else
            {
              v488 = &items->klass + size; /*0x852b88*/
              dateData->_size = size + 1; /*0x852b8c*/
              v488[4] = (Object__Array__Class *)v487; /*0x852b90*/
              v167._dateData = sub_73C72C(v488 + 4); /*0x852b94*/
            }
            v482 = byte_27E6C86; /*0x852bb8*/
            ++v481; /*0x852bbc*/
            continue; /*0x852bc0*/
          }
          goto LABEL_1546; /*0x852b6c*/
        }
        break;
      }
LABEL_965:
      v167._dateData = (uint64_t)TypeInfo::FriendServerSender->static_fields->Instance; /*0x855878*/
      if ( !v167._dateData ) /*0x855884*/
        goto LABEL_1546; /*0x855884*/
      FriendServerSender::UpdateWorldString((FriendServerSender *)v167._dateData, (MethodInfo *)v168); /*0x855888*/
      if ( !byte_27E6C86 ) /*0x855898*/
      {
        sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x8558a4*/
        byte_27E6C86 = 1; /*0x8558ac*/
      }
      v167._dateData = (uint64_t)TypeInfo::GameServerConnector->static_fields->Instance; /*0x8558b8*/
      if ( !v167._dateData ) /*0x8558bc*/
        goto LABEL_1546; /*0x8558bc*/
      *(_BYTE *)(v167._dateData + 56) = 1; /*0x8558c4*/
      GameServerConnector::StartPinging((GameServerConnector *)v167._dateData, (MethodInfo *)v168); /*0x8558c8*/
      v167._dateData = (uint64_t)TypeInfo::PopupControl->static_fields->Instance; /*0x8558dc*/
      if ( !v167._dateData ) /*0x8558e0*/
        goto LABEL_1546; /*0x8558e0*/
      PopupControl::HideAll((PopupControl *)v167._dateData, nullptr); /*0x8558e8*/
      if ( !byte_27E6C86 ) /*0x8558f4*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x855900*/
        byte_27E6C86 = 1; /*0x85590c*/
      }
      v782 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x855918*/
      if ( !v782 ) /*0x85591c*/
        goto LABEL_1546; /*0x85591c*/
      if ( !v782->is_host_cached ) /*0x855920*/
      {
        v167._dateData = (uint64_t)v782->server_name; /*0x855928*/
        if ( !v167._dateData ) /*0x85592c*/
          goto LABEL_1546; /*0x85592c*/
        v783 = System::String::Replace((String *)v167._dateData, (String *)"(private)", (String *)"", nullptr); /*0x855964*/
        v167._dateData = (uint64_t)System::String::Concat( /*0x85597c*/
                                     (String *)"Welcome to <color=#4acfff>",
                                     v783,
                                     (String *)"'s</color> world",
                                     nullptr);
        v784 = TypeInfo::FriendServerInterface->static_fields->Instance; /*0x855988*/
        if ( !v784 ) /*0x85598c*/
          goto LABEL_1546; /*0x85598c*/
        default_server_icon = v784->default_server_icon; /*0x855990*/
        v786 = (String *)v167._dateData; /*0x85599c*/
        v167._dateData = sub_73C88C(TypeInfo::chat_log); /*0x8559a4*/
        if ( !v167._dateData ) /*0x8559a8*/
          goto LABEL_1546; /*0x8559a8*/
        v787 = (chat_log *)v167._dateData; /*0x8559cc*/
        chat_log::chat_log((chat_log *)v167._dateData, v786, (String *)"", default_server_icon, 1, nullptr, nullptr); /*0x8559d4*/
        if ( !byte_27E6C84 ) /*0x8559e4*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x8559f0*/
          byte_27E6C84 = 1; /*0x8559f4*/
        }
        v788 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x855a04*/
        if ( !v788 ) /*0x855a0c*/
          goto LABEL_1546; /*0x855a0c*/
        v167._dateData = (uint64_t)v788->game_chat; /*0x855a10*/
        if ( !v167._dateData ) /*0x855a14*/
          goto LABEL_1546; /*0x855a14*/
        ChatCollection::AddLog((ChatCollection *)v167._dateData, v787, nullptr); /*0x855a20*/
        if ( !byte_27E6C84 ) /*0x855a28*/
        {
          sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x855a34*/
          byte_27E6C84 = 1; /*0x855a3c*/
        }
        v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x855a48*/
        if ( !v167._dateData ) /*0x855a4c*/
          goto LABEL_1546; /*0x855a4c*/
        GameServerInterface::GameChatReceived((GameServerInterface *)v167._dateData, v787, (MethodInfo *)v169); /*0x855a54*/
        if ( !byte_27E6C86 ) /*0x855a60*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x855a6c*/
          byte_27E6C86 = 1; /*0x855a78*/
        }
      }
      v789 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x855a84*/
      if ( !v789 ) /*0x855a88*/
        goto LABEL_1546; /*0x855a88*/
      if ( v789->is_host_cached ) /*0x855a8c*/
      {
        System::Collections::Generic::List<System::Object>::GetEnumerator( /*0x855aa8*/
          (List_1_T_Enumerator_System_Object_ *)&v1003,
          dateData,
          MethodInfo::System::Collections::Generic::List<System::String>::GetEnumerator);
        i = *(List_1_T_Enumerator_System_Object_ *)&v1003._dictionary; /*0x855abc*/
        while ( System::Collections::Generic::List_1_T_::Enumerator<System::Object>::MoveNext( /*0x855ad8*/
                  &i,
                  MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::MoveNext) )
        {
          current = i._current; /*0x855ae0*/
          if ( !byte_27E6C84 ) /*0x855ae4*/
          {
            sub_73C778(&TypeInfo::GameServerInterface, v790); /*0x855aec*/
            byte_27E6C84 = 1; /*0x855af0*/
          }
          v794 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x855afc*/
          if ( !v794 ) /*0x855b00*/
            sub_73C89C(0, v790, v791); /*0x858390*/
          GameServerInterface::ShowPlayerLogInOrOut(v794, (String *)current, 1u, v792); /*0x855b0c*/
        }
        System::Collections::Generic::List_1_T_::Enumerator<System::Object>::Dispose( /*0x855cfc*/
          &i,
          MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::Dispose);
      }
      if ( !byte_27E6C86 ) /*0x855d08*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x855d18*/
        byte_27E6C86 = 1; /*0x855d20*/
      }
      v802 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x855d2c*/
      if ( !v802 ) /*0x855d30*/
        goto LABEL_1546; /*0x855d30*/
      if ( v802->is_host_cached ) /*0x855d34*/
      {
        v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x855d3c*/
        if ( !v167._dateData ) /*0x855d40*/
          goto LABEL_1546; /*0x855d40*/
        System::Collections::Generic::Dictionary<System::Object,System::Object>::Clear( /*0x855d50*/
          (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
          MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::Clear);
      }
      else
      {
        GameServerReceiver::ClearPreviousMap(this, (MethodInfo *)v168); /*0x85685c*/
      }
      if ( !byte_27E6C85 ) /*0x856864*/
      {
        sub_73C778(&TypeInfo::GameServerSender, v168); /*0x856870*/
        byte_27E6C85 = 1; /*0x856878*/
      }
      v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x856884*/
      if ( !v167._dateData ) /*0x856888*/
        goto LABEL_1546; /*0x856888*/
      GameServerSender::SendInitialPlayerData((GameServerSender *)v167._dateData, (MethodInfo *)v168); /*0x85688c*/
      return; /*0x856890*/
    case 3:
      String = Packet::GetString(incoming, nullptr);// // case 0x04: UNKNOWN_0x04 /*0x851ea4*/
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x851eb0*/
      if ( !v167._dateData ) /*0x851eb4*/
        goto LABEL_1546; /*0x851eb4*/
      v404 = (Packet *)v167._dateData; /*0x851ebc*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x851ec0*/
      Packet::PutByte(v404, 4u, nullptr); /*0x851ed0*/
      Packet::PutString(v404, String, nullptr); /*0x851ee0*/
      v405 = 25; /*0x851ef0*/
      do /*0x851ffc*/
      {
        v167._dateData = (uint64_t)TypeInfo::ConstructionControl->static_fields->Instance; /*0x851f00*/
        if ( !v167._dateData ) /*0x851f04*/
          goto LABEL_1546; /*0x851f04*/
        NewUniqueId = ConstructionControl::GetNewUniqueId((ConstructionControl *)v167._dateData, 1, nullptr); /*0x851f14*/
        Packet::PutLong(v404, NewUniqueId, nullptr); /*0x851f24*/
        v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x851f28*/
        if ( !v167._dateData ) /*0x851f2c*/
          goto LABEL_1546; /*0x851f2c*/
        if ( !System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x851f3c*/
                (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                (Object *)String,
                MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::ContainsKey) )
        {
          unique_ids_given_away = (Dictionary_2_System_Object_System_Object_ *)this->unique_ids_given_away; /*0x851f44*/
          v167._dateData = sub_73C88C(TypeInfo::System::Collections::Generic::List<int>); /*0x851f48*/
          if ( !v167._dateData ) /*0x851f4c*/
            goto LABEL_1546; /*0x851f4c*/
          v408 = (Object *)v167._dateData; /*0x851f58*/
          System::Collections::Generic::List<int>::List( /*0x851f60*/
            (List_1_System_Int32_ *)v167._dateData,
            MethodInfo::System::Collections::Generic::List<int>::List);
          if ( !unique_ids_given_away ) /*0x851f64*/
            goto LABEL_1546; /*0x851f64*/
          System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x851f80*/
            unique_ids_given_away,
            (Object *)String,
            v408,
            MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::Add);
        }
        v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x851f8c*/
        if ( !v167._dateData ) /*0x851f90*/
          goto LABEL_1546; /*0x851f90*/
        v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x851f9c*/
                                     (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                     (Object *)String,
                                     MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::get_Item);
        if ( !v167._dateData ) /*0x851fa0*/
          goto LABEL_1546; /*0x851fa0*/
        v409 = *(_QWORD *)(v167._dateData + 16); /*0x851fa8*/
        v410 = MethodInfo::System::Collections::Generic::List<int>::Add; /*0x851fac*/
        ++*(_DWORD *)(v167._dateData + 28); /*0x851fb4*/
        if ( !v409 ) /*0x851fb8*/
          goto LABEL_1546; /*0x851fb8*/
        v411 = *(int *)(v167._dateData + 24); /*0x851fbc*/
        if ( (unsigned int)v411 >= *(_DWORD *)(v409 + 24) ) /*0x851fc8*/
        {
          v167._dateData = (*((__int64 (__fastcall **)(uint64_t, _QWORD))v410->klass->rgctx_data[11].rgctxDataDummy + 1))( /*0x851ff4*/
                             v167._dateData,
                             NewUniqueId);
        }
        else
        {
          *(_DWORD *)(v167._dateData + 24) = v411 + 1; /*0x851fd4*/
          *(_DWORD *)(v409 + 4 * v411 + 32) = NewUniqueId; /*0x851fd8*/
        }
        --v405; /*0x851ff8*/
      }
      while ( v405 ); /*0x851ffc*/
      v167._dateData = (uint64_t)GameServerReceiver::get_connection( /*0x852000*/
                                   (GameServerReceiver *)v167._dateData,
                                   (MethodInfo *)v168);
      if ( !v167._dateData ) /*0x852004*/
        goto LABEL_1546; /*0x852004*/
      v228 = v404; /*0x852008*/
      v227 = Connection_priority__Enum_SUPER_HIGH; /*0x85200c*/
      goto LABEL_1396; /*0x852010*/
    case 4:
      v167._dateData = Packet::GetShort(incoming, nullptr);// // case 0x05: UNKNOWN_0x05 /*0x8531c0*/
      dateData_low = SLOWORD(v167._dateData); /*0x8531e0*/
      if ( SLOWORD(v167._dateData) < 1 ) /*0x8531ec*/
        goto LABEL_568; /*0x8531ec*/
      do /*0x853270*/
      {
        v536 = TypeInfo::ConstructionControl->static_fields->Instance; /*0x8531f8*/
        if ( !v536 ) /*0x8531fc*/
          goto LABEL_1546; /*0x8531fc*/
        online_unique_ids = v536->online_unique_ids_; /*0x853200*/
        v167._dateData = Packet::GetLong(incoming, nullptr); /*0x85320c*/
        if ( !online_unique_ids ) /*0x853210*/
          goto LABEL_1546; /*0x853210*/
        v538 = online_unique_ids->_items; /*0x853218*/
        v539 = MethodInfo::System::Collections::Generic::List<int>::Add; /*0x85321c*/
        ++online_unique_ids->_version; /*0x853224*/
        if ( !v538 ) /*0x853228*/
          goto LABEL_1546; /*0x853228*/
        v540 = online_unique_ids->_size; /*0x85322c*/
        v168 = LODWORD(v167._dateData); /*0x853234*/
        if ( (unsigned int)v540 >= v538->max_length.size ) /*0x85323c*/
        {
          v167._dateData = (*((__int64 (__fastcall **)(List_1_System_Int32_ *, _QWORD))v539->klass->rgctx_data[11].rgctxDataDummy /*0x853268*/
                            + 1))(
                             online_unique_ids,
                             LODWORD(v167._dateData));
        }
        else
        {
          online_unique_ids->_size = v540 + 1; /*0x853248*/
          v538->vector[v540] = v167._dateData; /*0x85324c*/
        }
        --dateData_low; /*0x85326c*/
      }
      while ( dateData_low ); /*0x853270*/
LABEL_568:
      GameServerReceiver::ReceiveDaynight(this, incoming, (MethodInfo *)v169); /*0x853274*/
      disabled_perks = this->disabled_perks; /*0x853280*/
      if ( !disabled_perks ) /*0x853284*/
        goto LABEL_1546; /*0x853284*/
      v542 = disabled_perks->_size; /*0x853288*/
      v543 = disabled_perks->_version + 1; /*0x853290*/
      disabled_perks->_size = 0; /*0x853294*/
      disabled_perks->_version = v543; /*0x853294*/
      if ( v542 >= 1 ) /*0x8532a0*/
        System::Array::Clear((Array *)disabled_perks->_items, 0, v542, nullptr); /*0x8532b0*/
      Short = Packet::GetShort(incoming, nullptr); /*0x8532c0*/
      if ( Short >= 1 ) /*0x8532c8*/
      {
        do /*0x8532cc*/
        {
          v546 = this->disabled_perks; /*0x8532cc*/
          v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x8532d8*/
          if ( !v546 ) /*0x8532dc*/
            goto LABEL_1546; /*0x8532f4*/
          v547 = v546->_items; /*0x8532e4*/
          v548 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x8532e8*/
          ++v546->_version; /*0x8532f0*/
          if ( !v547 ) /*0x8532f4*/
            goto LABEL_1546; /*0x8532f4*/
          v549 = v546->_size; /*0x8532f8*/
          v550 = v167._dateData; /*0x853300*/
          if ( (unsigned int)v549 >= v547->max_length.size ) /*0x853308*/
          {
            (*((void (__fastcall **)(List_1_System_String_ *, uint64_t))v548->klass->rgctx_data[11].rgctxDataDummy + 1))( /*0x853338*/
              v546,
              v167._dateData);
          }
          else
          {
            v551 = &v547->klass + v549; /*0x853310*/
            v546->_size = v549 + 1; /*0x853314*/
            v551[4] = (String__Array__Class *)v550; /*0x853318*/
            sub_73C72C(v551 + 4); /*0x85331c*/
          }
        }
        while ( --Short ); /*0x8532cc*/
      }
      if ( !byte_27E6C86 ) /*0x85334c*/
      {
        sub_73C778(&TypeInfo::GameServerConnector, v544); /*0x853358*/
        byte_27E6C86 = 1; /*0x853364*/
      }
      v552 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x853378*/
      v167._dateData = Packet::GetByte(incoming, nullptr); /*0x85337c*/
      if ( !v552 ) /*0x853388*/
        goto LABEL_1546; /*0x853388*/
      v552->is_moderator = LOBYTE(v167._dateData) == 1; /*0x853398*/
      v553 = TypeInfo::CompanionController; /*0x85339c*/
      if ( !TypeInfo::CompanionController->_1.cctor_finished_or_no_cctor ) /*0x8533a0*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::CompanionController); /*0x8533a8*/
        v553 = TypeInfo::CompanionController; /*0x8533ac*/
      }
      v554 = v553->static_fields->Instance; /*0x8533bc*/
      v167._dateData = Packet::GetByte(incoming, nullptr); /*0x8533c0*/
      if ( !v554 ) /*0x8533c4*/
        goto LABEL_1546; /*0x8533c4*/
      v554->max_personal_companions_right_now = LOBYTE(v167._dateData); /*0x8533cc*/
      v167._dateData = (uint64_t)TypeInfo::CompanionController->static_fields->Instance; /*0x8533d8*/
      if ( !v167._dateData ) /*0x8533dc*/
        goto LABEL_1546; /*0x8533dc*/
      CompanionController::RecreateAllCompanions((CompanionController *)v167._dateData, nullptr); /*0x8533e4*/
      v555 = TypeInfo::CompanionController->static_fields->Instance; /*0x8533f0*/
      if ( !v555 ) /*0x8533f4*/
        goto LABEL_1546; /*0x8533f4*/
      v167._dateData = (uint64_t)v555->active_companions; /*0x8533f8*/
      if ( !v167._dateData ) /*0x8533fc*/
        goto LABEL_1546; /*0x8533fc*/
      System::Collections::Generic::List<System::Object>::GetEnumerator( /*0x853428*/
        (List_1_T_Enumerator_System_Object_ *)&v1003,
        (List_1_System_Object_ *)v167._dateData,
        MethodInfo::System::Collections::Generic::List<ActiveCompanion>::GetEnumerator);
      v1007 = *(List_1_T_Enumerator_System_Object_ *)&v1003._dictionary; /*0x853438*/
      while ( 1 ) /*0x853448*/
      {
        v556 = System::Collections::Generic::List_1_T_::Enumerator<System::Object>::MoveNext( /*0x853448*/
                 &v1007,
                 MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ActiveCompanion>::MoveNext);
        if ( (v556 & 1) == 0 ) /*0x85344c*/
          break; /*0x85344c*/
        v559 = v1007._current; /*0x853454*/
        if ( !byte_27E6C85 ) /*0x853458*/
        {
          v556 = sub_73C778(&TypeInfo::GameServerSender, v557); /*0x853460*/
          byte_27E6C85 = 1; /*0x853464*/
        }
        if ( !v559 ) /*0x853468*/
          sub_73C89C(v556, v557, v558); /*0x85837c*/
        v560 = TypeInfo::GameServerSender->static_fields->Instance; /*0x853474*/
        combat_name = ActiveCompanion::get_combat_name((ActiveCompanion *)v559, nullptr); /*0x853480*/
        if ( !v560 ) /*0x853488*/
          sub_73C89C(combat_name, combat_name, v562); /*0x858380*/
        GameServerSender::SendCreatedLocalMob(v560, combat_name, v562); /*0x853490*/
      }
      System::Collections::Generic::List_1_T_::Enumerator<System::Object>::Dispose( /*0x855b1c*/
        &v1007,
        MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<ActiveCompanion>::Dispose);
      v167._dateData = (uint64_t)TypeInfo::GameplayGUIControl->static_fields->Instance; /*0x855b28*/
      if ( !v167._dateData ) /*0x855b2c*/
        goto LABEL_1546; /*0x855b2c*/
      GameplayGUIControl::HideGameplayGui((GameplayGUIControl *)v167._dateData, nullptr); /*0x855b34*/
      v167._dateData = (uint64_t)TypeInfo::GameplayGUIControl->static_fields->Instance; /*0x855b40*/
      if ( !v167._dateData ) /*0x855b44*/
        goto LABEL_1546; /*0x855b44*/
      *(_DWORD *)(v167._dateData + 24) = 0; /*0x855b4c*/
      GameplayGUIControl::ShowGameplayGui((GameplayGUIControl *)v167._dateData, nullptr); /*0x855b50*/
      if ( !Packet::GetByte(incoming, nullptr) ) /*0x855b5c*/
      {
        v167._dateData = (uint64_t)TypeInfo::GameController; /*0x855b70*/
        if ( !TypeInfo::GameController->_1.cctor_finished_or_no_cctor ) /*0x855b74*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::GameController); /*0x855b7c*/
          v167._dateData = (uint64_t)TypeInfo::GameController; /*0x855b88*/
        }
        v795 = **(GameController ***)(v167._dateData + 184); /*0x855b98*/
        if ( !byte_27E6C86 ) /*0x855b9c*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x855ba8*/
          byte_27E6C86 = 1; /*0x855bb4*/
        }
        v796 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x855bc0*/
        if ( !v796 || !v795 ) /*0x855bc8*/
          goto LABEL_1546; /*0x855bc8*/
        SavedPlayerPositionOnServer = GameController::GetSavedPlayerPositionOnServer(v795, v796->server_name, nullptr); /*0x855bd8*/
        v797 = TypeInfo::GameController->static_fields->Instance; /*0x855c00*/
        if ( !byte_27E6C86 ) /*0x855c04*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x855c10*/
          byte_27E6C86 = 1; /*0x855c1c*/
        }
        v798 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x855c28*/
        if ( !v798 || !v797 ) /*0x855c30*/
          goto LABEL_1546; /*0x855c30*/
        SavedPlayerZoneOnServer = GameController::GetSavedPlayerZoneOnServer(v797, v798->server_name, nullptr); /*0x855c48*/
        if ( !byte_27E6C85 ) /*0x855c4c*/
        {
          sub_73C778(&TypeInfo::GameServerSender, v168); /*0x855c58*/
          byte_27E6C85 = 1; /*0x855c60*/
        }
        v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x855c6c*/
        if ( !v167._dateData ) /*0x855c70*/
          goto LABEL_1546; /*0x855c70*/
        GameServerSender::RequestZoneData( /*0x855c88*/
          (GameServerSender *)v167._dateData,
          SavedPlayerZoneOnServer,
          ZoneDataControl_change_zone_type__Enum_custom_position_no_transition,
          SavedPlayerPositionOnServer,
          v799);
      }
      if ( !byte_27E6C86 ) /*0x855c94*/
      {
        sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x855ca4*/
        byte_27E6C86 = 1; /*0x855cac*/
      }
      v801 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x855cc0*/
      v167._dateData = Packet::GetByte(incoming, nullptr); /*0x855cc4*/
      if ( !v801 ) /*0x855cc8*/
        goto LABEL_1546; /*0x855cc8*/
      v801->pvp_enabled = LOBYTE(v167._dateData) == 1; /*0x855ce0*/
      Packet::GetByte(incoming, nullptr); /*0x855ce4*/
      return; /*0x855ce8*/
    case 5:
      v568 = Packet::GetString(incoming, nullptr);// // case 0x06: CHAT /*0x853584*/
      v569 = Packet::GetString(incoming, nullptr); /*0x853594*/
      v570 = Packet::GetString(incoming, nullptr); /*0x8535a4*/
      if ( Packet::GetByte(incoming, nullptr) != 1 ) /*0x8535c8*/
        goto LABEL_618; /*0x8535c8*/
      v167._dateData = (uint64_t)TypeInfo::PlayerData->static_fields->Instance; /*0x8535d4*/
      if ( !v167._dateData ) /*0x8535d8*/
        goto LABEL_1546; /*0x8535d8*/
      GlobalString = PlayerData::GetGlobalString((PlayerData *)v167._dateData, (String *)"username_lower", nullptr); /*0x8535ec*/
      if ( System::String::op_Equality(v568, GlobalString, nullptr) ) /*0x8535fc*/
        goto LABEL_618; /*0x853600*/
      v167._dateData = (uint64_t)TypeInfo::FriendServerReceiver; /*0x853604*/
      if ( !TypeInfo::FriendServerReceiver->_1.cctor_finished_or_no_cctor ) /*0x853608*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerReceiver); /*0x853610*/
        v167._dateData = (uint64_t)TypeInfo::FriendServerReceiver; /*0x853614*/
      }
      v572 = **(_QWORD **)(v167._dateData + 184); /*0x85361c*/
      if ( !v572 ) /*0x853620*/
        goto LABEL_1546; /*0x853620*/
      v167._dateData = *(_QWORD *)(v572 + 40); /*0x853624*/
      if ( !v167._dateData ) /*0x853628*/
        goto LABEL_1546; /*0x853628*/
      System::Collections::Generic::List<System::Object>::GetEnumerator( /*0x85364c*/
        (List_1_T_Enumerator_System_Object_ *)&v1003,
        (List_1_System_Object_ *)v167._dateData,
        MethodInfo::System::Collections::Generic::List<Friend>::GetEnumerator);
      v1004 = *(List_1_T_Enumerator_System_Object_ *)&v1003._dictionary; /*0x853658*/
      while ( 1 ) /*0x853668*/
      {
        v573 = System::Collections::Generic::List_1_T_::Enumerator<System::Object>::MoveNext( /*0x853668*/
                 &v1004,
                 MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<Friend>::MoveNext);
        if ( !v573 ) /*0x85366c*/
          break; /*0x85366c*/
        if ( !v1004._current ) /*0x853674*/
          sub_73C89C(v573, v574, v575); /*0x8583a0*/
        if ( System::String::op_Equality((String *)v1004._current[1].klass, v568, nullptr) ) /*0x853684*/
        {
          System::Collections::Generic::List_1_T_::Enumerator<System::Object>::Dispose( /*0x853694*/
            &v1004,
            MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<Friend>::Dispose);
LABEL_618:
          v576 = System::String::Concat((String *)"<color=#abebff>", v569, (String *)":</color> ", v570, nullptr); /*0x853698*/
          v167._dateData = sub_73C88C(TypeInfo::chat_log); /*0x8536cc*/
          if ( v167._dateData ) /*0x8536d0*/
          {
            v577 = (chat_log *)v167._dateData; /*0x8536ec*/
            chat_log::chat_log((chat_log *)v167._dateData, v576, v570, nullptr, 0, nullptr, nullptr); /*0x8536f0*/
            if ( !byte_27E6C84 ) /*0x8536f8*/
            {
              v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x853704*/
              byte_27E6C84 = 1; /*0x85370c*/
            }
            v578 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x853718*/
            if ( v578 ) /*0x85371c*/
            {
              v167._dateData = (uint64_t)v578->game_chat; /*0x853720*/
              if ( v167._dateData ) /*0x853724*/
              {
                ChatCollection::AddLog((ChatCollection *)v167._dateData, v577, nullptr); /*0x853730*/
                if ( !byte_27E6C84 ) /*0x853738*/
                {
                  sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x853744*/
                  byte_27E6C84 = 1; /*0x85374c*/
                }
                v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x853758*/
                if ( v167._dateData ) /*0x85375c*/
                {
                  GameServerInterface::GameChatReceived((GameServerInterface *)v167._dateData, v577, (MethodInfo *)v169); /*0x853764*/
                  v579 = TypeInfo::FriendServerReceiver; /*0x853768*/
                  if ( !TypeInfo::FriendServerReceiver->_1.cctor_finished_or_no_cctor ) /*0x85376c*/
                  {
                    j_il2cpp_runtime_class_init_0(TypeInfo::FriendServerReceiver); /*0x853774*/
                    v579 = TypeInfo::FriendServerReceiver; /*0x853778*/
                  }
                  v167._dateData = (uint64_t)v579->static_fields->Instance; /*0x853780*/
                  if ( v167._dateData ) /*0x853784*/
                  {
                    FriendServerReceiver::AddToRecentlySeenPlayers( /*0x853798*/
                      (FriendServerReceiver *)v167._dateData,
                      v568,
                      v569,
                      v570,
                      nullptr);
                    return; /*0x85379c*/
                  }
                }
              }
            }
          }
          goto LABEL_1546; /*0x853784*/
        }
      }
      System::Collections::Generic::List_1_T_::Enumerator<System::Object>::Dispose( /*0x857c74*/
        &v1004,
        MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<Friend>::Dispose);
      return; /*0x857c78*/
    case 6:
      v420 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x07: UNKNOWN_0x07 /*0x8521b0*/
      v421 = Packet::GetString(incoming, nullptr); /*0x8521c0*/
      Byte = Packet::GetByte(incoming, nullptr); /*0x8521d8*/
      if ( !byte_27E6C84 ) /*0x8521dc*/
      {
        sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x8521e8*/
        byte_27E6C84 = 1; /*0x8521f0*/
      }
      v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x85220c*/
      if ( !v167._dateData ) /*0x852214*/
        goto LABEL_1546; /*0x852214*/
      GameServerInterface::ShowPlayerLogInOrOut((GameServerInterface *)v167._dateData, v421, Byte, v422); /*0x852220*/
      if ( Byte == 1 ) /*0x85222c*/
      {
        if ( !byte_27E6C86 ) /*0x856a50*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x856a5c*/
          byte_27E6C86 = 1; /*0x856a64*/
        }
        v872 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x856a70*/
        if ( !v872 ) /*0x856a74*/
          goto LABEL_1546; /*0x856a74*/
        ++v872->n_others_in_game; /*0x856a80*/
      }
      else if ( !Byte ) /*0x852230*/
      {
        if ( !byte_27E6C86 ) /*0x85223c*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x852248*/
          byte_27E6C86 = 1; /*0x852250*/
        }
        v424 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x85225c*/
        if ( !v424 ) /*0x852260*/
          goto LABEL_1546; /*0x852260*/
        is_host_cached = v424->is_host_cached; /*0x852268*/
        --v424->n_others_in_game; /*0x852270*/
        if ( is_host_cached ) /*0x852274*/
        {
          v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x852278*/
          if ( !v167._dateData ) /*0x85227c*/
            goto LABEL_1546; /*0x85227c*/
          if ( System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x852288*/
                 (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                 v420,
                 MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::ContainsKey) )
          {
            v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x852290*/
            if ( !v167._dateData ) /*0x852294*/
              goto LABEL_1546; /*0x852294*/
            v426 = TypeInfo::ConstructionControl->static_fields->Instance; /*0x8522a8*/
            v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8522ac*/
                                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                         v420,
                                         MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::get_Item);
            if ( !v426 ) /*0x8522b0*/
              goto LABEL_1546; /*0x8522b0*/
            ConstructionControl::RecycleUniqueIds(v426, (List_1_System_Int32_ *)v167._dateData, nullptr); /*0x8522c0*/
            v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x8522c4*/
            if ( !v167._dateData ) /*0x8522c8*/
              goto LABEL_1546; /*0x8522c8*/
            System::Collections::Generic::Dictionary<System::Object,System::Object>::Remove( /*0x8522dc*/
              (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
              v420,
              MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::Remove);
          }
        }
      }
      v167._dateData = (uint64_t)TypeInfo::FriendServerSender->static_fields->Instance; /*0x856a8c*/
      if ( !v167._dateData ) /*0x856a90*/
        goto LABEL_1546; /*0x856a90*/
      FriendServerSender::UpdateWorldString((FriendServerSender *)v167._dateData, (MethodInfo *)v168); /*0x856a94*/
      return; /*0x856a98*/
    case 7:
      v489 = Packet::GetString(incoming, nullptr);// // case 0x08: UNKNOWN_0x08 /*0x852be8*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x852bf4*/
      if ( !TypeInfo::PlayerData->static_fields->Instance ) /*0x852c08*/
        goto LABEL_1546; /*0x852c08*/
      v490 = (String *)v167._dateData; /*0x852c20*/
      v491 = PlayerData::GetGlobalString( /*0x852c3c*/
               TypeInfo::PlayerData->static_fields->Instance,
               (String *)"username_lower",
               nullptr);
      if ( System::String::op_Equality(v489, v491, nullptr) ) /*0x852c4c*/
        v489 = (String *)"You"; /*0x852c64*/
      v492 = System::String::op_Equality(v490, v491, nullptr) ? "you" : (char *)v490;
      v167._dateData = sub_73C7E4(TypeInfo::System::String, 5); /*0x852c84*/
      if ( !v167._dateData ) /*0x852c90*/
        goto LABEL_1546; /*0x852c90*/
      v493 = (String__Array *)v167._dateData; /*0x852c9c*/
      if ( "<color=#f2cb88>" ) /*0x852ca4*/
      {
        v167._dateData = sub_73C87C("<color=#f2cb88>", *(_QWORD *)(*(_QWORD *)v167._dateData + 64LL)); /*0x852cb8*/
        if ( !v167._dateData ) /*0x852cbc*/
          goto LABEL_1553; /*0x852cbc*/
        v494 = "<color=#f2cb88>"; /*0x852cc0*/
      }
      else
      {
        v494 = nullptr; /*0x856694*/
      }
      if ( !v493->max_length.size ) /*0x85669c*/
        goto LABEL_1547; /*0x85669c*/
      v493->vector[0] = (String *)v494; /*0x8566a4*/
      v167._dateData = sub_73C72C(v493->vector); /*0x8566a8*/
      if ( v489 ) /*0x8566ac*/
      {
        v167._dateData = sub_73C87C(v489, v493->klass->_0.element_class); /*0x8566bc*/
        if ( !v167._dateData ) /*0x8566c0*/
          goto LABEL_1553; /*0x8566c0*/
      }
      if ( v493->max_length.size <= 1u ) /*0x8566cc*/
        goto LABEL_1547; /*0x8566cc*/
      v493->vector[1] = v489; /*0x8566dc*/
      v167._dateData = sub_73C72C(&v493->vector[1]); /*0x8566e4*/
      if ( "</color><color=#ff5252> killed " ) /*0x8566ec*/
      {
        v167._dateData = sub_73C87C("</color><color=#ff5252> killed ", v493->klass->_0.element_class); /*0x856700*/
        if ( !v167._dateData ) /*0x856704*/
          goto LABEL_1553; /*0x856704*/
        v855 = "</color><color=#ff5252> killed "; /*0x856708*/
      }
      else
      {
        v855 = nullptr; /*0x856714*/
      }
      if ( v493->max_length.size <= 2u ) /*0x856720*/
        goto LABEL_1547; /*0x856720*/
      v493->vector[2] = (String *)v855; /*0x856728*/
      v167._dateData = sub_73C72C(&v493->vector[2]); /*0x85672c*/
      if ( !v492 || (v167._dateData = sub_73C87C(v492, v493->klass->_0.element_class)) != 0 ) /*0x856744*/
      {
        if ( v493->max_length.size <= 3u ) /*0x856750*/
          goto LABEL_1547; /*0x856750*/
        v493->vector[3] = (String *)v492; /*0x856760*/
        v167._dateData = sub_73C72C(&v493->vector[3]); /*0x856768*/
        if ( !"</color>" ) /*0x856770*/
        {
          v856 = nullptr; /*0x856798*/
LABEL_1143:
          if ( v493->max_length.size > 4u ) /*0x8567a4*/
          {
            v493->vector[4] = (String *)v856; /*0x8567ac*/
            sub_73C72C(&v493->vector[4]); /*0x8567b0*/
            v167._dateData = (uint64_t)System::String::Concat(v493, nullptr); /*0x8567bc*/
            v857 = TypeInfo::CompanionController; /*0x8567c0*/
            v858 = (String *)v167._dateData; /*0x8567c4*/
            if ( !TypeInfo::CompanionController->_1.cctor_finished_or_no_cctor ) /*0x8567c8*/
            {
              v167._dateData = j_il2cpp_runtime_class_init_0(TypeInfo::CompanionController); /*0x8567d4*/
              v857 = TypeInfo::CompanionController; /*0x8567d8*/
            }
            v859 = v857->static_fields->Instance; /*0x8567e0*/
            if ( !v859 ) /*0x8567e4*/
              goto LABEL_1546; /*0x8567e4*/
            companion_died_ico = v859->companion_died_ico; /*0x8567ec*/
            v167._dateData = sub_73C88C(TypeInfo::chat_log); /*0x8567f0*/
            if ( !v167._dateData ) /*0x8567f4*/
              goto LABEL_1546; /*0x8567f4*/
            v861 = (chat_log *)v167._dateData; /*0x856810*/
            chat_log::chat_log((chat_log *)v167._dateData, v858, (String *)"", companion_died_ico, 0, nullptr, nullptr); /*0x856814*/
            v862 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x856820*/
            if ( !v862 ) /*0x856824*/
              goto LABEL_1546; /*0x856824*/
            v167._dateData = (uint64_t)v862->game_chat; /*0x856828*/
            if ( !v167._dateData ) /*0x85682c*/
              goto LABEL_1546; /*0x85682c*/
            ChatCollection::AddLog((ChatCollection *)v167._dateData, v861, nullptr); /*0x856838*/
            v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x856844*/
            if ( !v167._dateData ) /*0x856848*/
              goto LABEL_1546; /*0x856848*/
            GameServerInterface::GameChatReceived((GameServerInterface *)v167._dateData, v861, (MethodInfo *)v169); /*0x856850*/
            return; /*0x856854*/
          }
LABEL_1547:
          sub_73C8A4(v167._dateData); /*0x85836c*/
        }
        v167._dateData = sub_73C87C("</color>", v493->klass->_0.element_class); /*0x856784*/
        if ( v167._dateData ) /*0x856788*/
        {
          v856 = "</color>"; /*0x85678c*/
          goto LABEL_1143; /*0x856794*/
        }
      }
      goto LABEL_1553; /*0x856788*/
    case 8:
      v495 = Packet::GetString(incoming, nullptr);// // case 0x09: GUARD_DIE_NOTIF /*0x852cdc*/
      v496 = Packet::GetString(incoming, nullptr); /*0x852ce8*/
      v497 = TypeInfo::CompanionController; /*0x852cec*/
      v498 = v496; /*0x852cf0*/
      if ( !TypeInfo::CompanionController->_1.cctor_finished_or_no_cctor ) /*0x852cf4*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::CompanionController); /*0x852d00*/
        v497 = TypeInfo::CompanionController; /*0x852d04*/
      }
      v167._dateData = (uint64_t)v497->static_fields->Instance; /*0x852d0c*/
      if ( !v167._dateData ) /*0x852d10*/
        goto LABEL_1546; /*0x852d10*/
      CompanionController::OnGuardDie((CompanionController *)v167._dateData, v495, v498, nullptr); /*0x852d20*/
      return; /*0x852d24*/
    case 9:
      v608 = Packet::GetString(incoming, nullptr);// // case 0x0A: REQ_ZONE /*0x853b94*/
      v609 = Packet::GetString(incoming, nullptr); /*0x853ba4*/
      v610 = Packet::GetByte(incoming, nullptr); /*0x853bb0*/
      v613 = v610; /*0x853bb8*/
      if ( !byte_27E6C81 ) /*0x853bbc*/
      {
        v610 = sub_73C778(&TypeInfo::UnityEngine::Vector3, v611); /*0x853bc8*/
        byte_27E6C81 = 1; /*0x853bd0*/
      }
      if ( (v613 & 0xFE) == 2 ) /*0x853be8*/
      {
        v1024 = GameServerReceiver::UnpackPosition((GameServerReceiver *)v610, incoming, v612); /*0x853bf0*/
        x = v1024.x; /*0x853bf4*/
        y = v1024.y; /*0x853bf8*/
        z = v1024.z; /*0x853bfc*/
      }
      else
      {
        static_fields = TypeInfo::UnityEngine::Vector3->static_fields; /*0x856198*/
        x = static_fields->zeroVector.x; /*0x85619c*/
        y = static_fields->zeroVector.y; /*0x85619c*/
        z = static_fields->zeroVector.z; /*0x8561a0*/
      }
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x8561a8*/
      if ( !v167._dateData ) /*0x8561ac*/
        goto LABEL_1546; /*0x8561ac*/
      v837 = (Packet *)v167._dateData; /*0x8561b8*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x8561c0*/
      Packet::PutByte(v837, 0xBu, nullptr); /*0x8561d0*/
      Packet::PutString(v837, v608, nullptr); /*0x8561e0*/
      Packet::PutString(v837, v609, nullptr); /*0x8561f0*/
      Packet::PutByte(v837, v613, nullptr); /*0x856200*/
      if ( (v613 & 0xFE) != 2 ) /*0x85620c*/
        goto LABEL_1077; /*0x85620c*/
      if ( !byte_27E6C85 ) /*0x856214*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x856220*/
        byte_27E6C85 = 1; /*0x856228*/
      }
      if ( !TypeInfo::GameServerSender->static_fields->Instance ) /*0x856234*/
        goto LABEL_1546; /*0x856234*/
      v1037.x = x; /*0x856240*/
      v1037.y = y; /*0x856244*/
      v1037.z = z; /*0x856248*/
      GameServerSender::PackPosition((GameServerSender *)v167._dateData, v837, v1037, (MethodInfo *)v169); /*0x85624c*/
LABEL_1077:
      v167._dateData = (uint64_t)TypeInfo::ZoneDataControl->static_fields->Instance; /*0x856258*/
      if ( !v167._dateData ) /*0x85625c*/
        goto LABEL_1546; /*0x85625c*/
      v167._dateData = (uint64_t)ZoneDataControl::LoadZoneDataFromDisk((ZoneDataControl *)v167._dateData, v609, nullptr); /*0x856268*/
      if ( !v167._dateData ) /*0x85626c*/
        goto LABEL_1546; /*0x85626c*/
      v838 = (ZoneData *)v167._dateData; /*0x856278*/
      ZoneData::PackForWeb((ZoneData *)v167._dateData, v837, nullptr); /*0x85627c*/
      ZoneData::ClearOutdoorLandClaims(v838, nullptr); /*0x856288*/
      v167._dateData = (uint64_t)TypeInfo::ZoneDataControl->static_fields->Instance; /*0x856294*/
      if ( !v167._dateData ) /*0x856298*/
        goto LABEL_1546; /*0x856298*/
      v167._dateData = (uint64_t)ZoneDataControl::GetZoneTrail((ZoneDataControl *)v167._dateData, v609, nullptr); /*0x8562a4*/
      if ( !v167._dateData ) /*0x8562a8*/
        goto LABEL_1546; /*0x8562a8*/
      v839 = (List_1_System_Object_ *)v167._dateData; /*0x8562b0*/
      Packet::PutShort(v837, (float)*(int *)(v167._dateData + 24), nullptr); /*0x8562c0*/
      System::Collections::Generic::List<System::Object>::GetEnumerator( /*0x8562d8*/
        (List_1_T_Enumerator_System_Object_ *)&v1003,
        v839,
        MethodInfo::System::Collections::Generic::List<System::String>::GetEnumerator);
      for ( i = *(List_1_T_Enumerator_System_Object_ *)&v1003._dictionary; /*0x8562ec*/
            System::Collections::Generic::List_1_T_::Enumerator<System::Object>::MoveNext(
              &i,
              MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::MoveNext);
            Packet::PutString(v837, (String *)i._current, nullptr) )
      {
        ; /*0x856314*/
      }
      System::Collections::Generic::List_1_T_::Enumerator<System::Object>::Dispose( /*0x856324*/
        &i,
        MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::Dispose);
      v167._dateData = (uint64_t)GameServerReceiver::get_connection(v840, v841); /*0x856328*/
      if ( !v167._dateData ) /*0x85632c*/
        goto LABEL_1546; /*0x85632c*/
      goto LABEL_1395; /*0x85632c*/
    case 10:
      if ( !byte_27E6C85 ) // // case 0x0B: ZONE_DATA /*0x853838*/
      {
        sub_73C778( /*0x853844*/
          &TypeInfo::GameServerSender,
          &MethodInfo::System::Collections::Generic::List<System::String>::Contains);
        byte_27E6C85 = 1; /*0x85384c*/
      }
      v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x853864*/
      if ( !v167._dateData ) /*0x853868*/
        goto LABEL_1546; /*0x853868*/
      v586 = *(IEnumerator **)(v167._dateData + 96); /*0x85386c*/
      if ( v586 ) /*0x853874*/
        UnityEngine::MonoBehaviour::StopCoroutine((MonoBehaviour *)v167._dateData, v586, nullptr); /*0x85387c*/
      v587 = Packet::GetByte(incoming, nullptr); /*0x85388c*/
      v167._dateData = Packet::GetByte(incoming, nullptr); /*0x853898*/
      v589 = v167._dateData; /*0x8538a0*/
      this->waiting_on_initial_zone_data = 0; /*0x8538a8*/
      if ( v587 == 1 ) /*0x8538ac*/
      {
        if ( !byte_27E6C84 ) /*0x856c7c*/
        {
          sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x856c88*/
          byte_27E6C84 = 1; /*0x856c90*/
        }
        v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x856ca4*/
        if ( !v167._dateData ) /*0x856ca8*/
          goto LABEL_1546; /*0x856ca8*/
        GameServerInterface::ProcessIncomingZoneData((GameServerInterface *)v167._dateData, incoming, v589 == 1, v588); /*0x856cbc*/
      }
      else if ( !v587 ) /*0x8538b0*/
      {
        if ( !byte_27E6C84 ) /*0x8538b8*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x8538c8*/
          byte_27E6C84 = 1; /*0x8538d0*/
        }
        if ( !TypeInfo::GameServerInterface->static_fields->Instance ) /*0x8538e8*/
          goto LABEL_1546; /*0x8538e8*/
        GameServerInterface::UnknownZoneGotoSpawn((GameServerInterface *)v167._dateData, 1, v589 == 1, v588); /*0x8538fc*/
      }
      return; /*0x853900*/
    case 11:
      v311 = Packet::GetString(incoming, nullptr);// // case 0x0C: REQ_CHUNK /*0x8512c8*/
      v312 = Packet::GetString(incoming, nullptr); /*0x8512d8*/
      v313 = Packet::GetShort(incoming, nullptr); /*0x8512e8*/
      v314 = Packet::GetShort(incoming, nullptr); /*0x8512f4*/
      v315 = TypeInfo::ChunkControl; /*0x8512fc*/
      v316 = v314; /*0x851300*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x851304*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x851310*/
        v315 = TypeInfo::ChunkControl; /*0x851318*/
      }
      v167._dateData = (uint64_t)v315->static_fields->Instance; /*0x851324*/
      if ( !v167._dateData ) /*0x851328*/
        goto LABEL_1546; /*0x851328*/
      v317 = v313; /*0x85132c*/
      v318 = v316; /*0x851330*/
      incominga = v311; /*0x851344*/
      v167._dateData = (uint64_t)ChunkControl::GetChunkString((ChunkControl *)v167._dateData, v312, v317, v316, nullptr); /*0x851348*/
      if ( !TypeInfo::ChunkControl->static_fields->Instance ) /*0x851354*/
        goto LABEL_1546; /*0x851354*/
      v319 = (String *)v167._dateData; /*0x85135c*/
      IsChunkFullyLoadedOrMidload = ChunkControl::IsChunkFullyLoadedOrMidload( /*0x85136c*/
                                      TypeInfo::ChunkControl->static_fields->Instance,
                                      (String *)v167._dateData,
                                      nullptr);
      v321 = TypeInfo::ChunkControl; /*0x851370*/
      v322 = IsChunkFullyLoadedOrMidload; /*0x851374*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x851378*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x851384*/
        v321 = TypeInfo::ChunkControl; /*0x851388*/
      }
      v167._dateData = (uint64_t)v321->static_fields->Instance; /*0x851390*/
      if ( !v167._dateData ) /*0x851394*/
        goto LABEL_1546; /*0x851394*/
      if ( v322 ) /*0x851398*/
      {
        ChunkData = ChunkControl::GetChunkData((ChunkControl *)v167._dateData, v319, nullptr); /*0x8513a8*/
        v324 = 0; /*0x8513ac*/
      }
      else
      {
        ChunkData = ChunkControl::HostGetChunk((ChunkControl *)v167._dateData, v312, v317, v318, nullptr); /*0x855e3c*/
        v324 = 1; /*0x855e40*/
      }
      v167._dateData = (uint64_t)TypeInfo::ZoneDataControl->static_fields->Instance; /*0x855e54*/
      if ( !v167._dateData ) /*0x855e5c*/
        goto LABEL_1546; /*0x855e5c*/
      v167._dateData = (uint64_t)ZoneDataControl::LoadZoneDataFromDisk((ZoneDataControl *)v167._dateData, v312, nullptr); /*0x855e68*/
      if ( !v167._dateData ) /*0x855e74*/
        goto LABEL_1546; /*0x855e74*/
      if ( !ChunkData ) /*0x855e80*/
        goto LABEL_1546; /*0x855e80*/
      v806 = (List_1_System_Object_ *)ChunkData::DetermineBanditCampsWithinChunk( /*0x855e98*/
                                        ChunkData,
                                        *(InventoryItem **)(v167._dateData + 24),
                                        nullptr);
      v167._dateData = sub_73C88C(TypeInfo::System::Collections::Generic::List<System::String>); /*0x855ea0*/
      if ( !v167._dateData ) /*0x855ea4*/
        goto LABEL_1546; /*0x855ea4*/
      v807 = (List_1_System_Object_ *)v167._dateData; /*0x855eac*/
      System::Collections::Generic::List<System::Object>::List( /*0x855eb0*/
        (List_1_System_Object_ *)v167._dateData,
        MethodInfo::System::Collections::Generic::List<System::String>::List);
      if ( !v806 ) /*0x855eb4*/
        goto LABEL_1546; /*0x855eb4*/
      System::Collections::Generic::List<System::Object>::GetEnumerator( /*0x855ecc*/
        (List_1_T_Enumerator_System_Object_ *)&v1003,
        v806,
        MethodInfo::System::Collections::Generic::List<System::String>::GetEnumerator);
      i = *(List_1_T_Enumerator_System_Object_ *)&v1003._dictionary; /*0x855edc*/
      while ( System::Collections::Generic::List_1_T_::Enumerator<System::Object>::MoveNext( /*0x855ef4*/
                &i,
                MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::MoveNext) )
      {
        full_bandit_camps_sent_to_server = (List_1_System_Object_ *)this->full_bandit_camps_sent_to_server; /*0x855ef8*/
        if ( !full_bandit_camps_sent_to_server ) /*0x855f00*/
          sub_73C89C(0, v808, v809); /*0x858378*/
        v811 = i._current; /*0x855f04*/
        v812 = System::Collections::Generic::List<System::Object>::Contains( /*0x855f10*/
                 full_bandit_camps_sent_to_server,
                 i._current,
                 MethodInfo::System::Collections::Generic::List<System::String>::Contains);
        if ( !v812 ) /*0x855f14*/
        {
          v815 = v807->_items; /*0x855f1c*/
          v816 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x855f20*/
          ++v807->_version; /*0x855f28*/
          if ( !v815 ) /*0x855f2c*/
            sub_73C89C(v812, v813, v814); /*0x858394*/
          v817 = v807->_size; /*0x855f30*/
          if ( (unsigned int)v817 >= v815->max_length.size ) /*0x855f3c*/
          {
            (*((void (__fastcall **)(List_1_System_Object_ *, Object *))v816->klass->rgctx_data[11].rgctxDataDummy + 1))( /*0x855f74*/
              v807,
              v811);
          }
          else
          {
            v818 = &v815->klass + v817; /*0x855f44*/
            v807->_size = v817 + 1; /*0x855f48*/
            v818[4] = (Object__Array__Class *)v811; /*0x855f4c*/
            sub_73C72C(v818 + 4); /*0x855f54*/
          }
          v821 = this->full_bandit_camps_sent_to_server; /*0x855f78*/
          if ( !v821 ) /*0x855f7c*/
            sub_73C89C(0, v819, v820); /*0x858398*/
          v822 = v821->_items; /*0x855f84*/
          v823 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x855f88*/
          ++v821->_version; /*0x855f90*/
          if ( !v822 ) /*0x855f94*/
            sub_73C89C(v821, v819, v820); /*0x85839c*/
          v824 = v821->_size; /*0x855f98*/
          if ( (unsigned int)v824 >= v822->max_length.size ) /*0x855fa4*/
          {
            (*((void (**)(void))v823->klass->rgctx_data[11].rgctxDataDummy + 1))(); /*0x855fdc*/
          }
          else
          {
            v825 = &v822->klass + v824; /*0x855fac*/
            v821->_size = v824 + 1; /*0x855fb0*/
            v825[4] = (String__Array__Class *)v811; /*0x855fb4*/
            sub_73C72C(v825 + 4); /*0x855fc0*/
          }
        }
      }
      System::Collections::Generic::List_1_T_::Enumerator<System::Object>::Dispose( /*0x855fec*/
        &i,
        MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::Dispose);
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x855ffc*/
      if ( !v167._dateData ) /*0x856004*/
        goto LABEL_1546; /*0x856004*/
      v826 = (Packet *)v167._dateData; /*0x85600c*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x856010*/
      Packet::PutByte(v826, 0xDu, nullptr); /*0x856020*/
      Packet::PutString(v826, incominga, nullptr); /*0x856030*/
      ChunkData::PackForWeb(ChunkData, v826, nullptr); /*0x856040*/
      Packet::PutByte(v826, v807->_size, nullptr); /*0x856050*/
      System::Collections::Generic::List<System::Object>::GetEnumerator( /*0x856068*/
        (List_1_T_Enumerator_System_Object_ *)&v1003,
        v807,
        MethodInfo::System::Collections::Generic::List<System::String>::GetEnumerator);
      i = *(List_1_T_Enumerator_System_Object_ *)&v1003._dictionary; /*0x856074*/
      while ( System::Collections::Generic::List_1_T_::Enumerator<System::Object>::MoveNext( /*0x856090*/
                &i,
                MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::MoveNext) )
      {
        v829 = TypeInfo::BanditCampsControl->static_fields->Instance; /*0x85609c*/
        if ( !v829 ) /*0x8560a0*/
          sub_73C89C(0, v827, v828); /*0x858370*/
        BanditCampInstanceByName = BanditCampsControl::GetBanditCampInstanceByName(v829, (String *)i._current, nullptr); /*0x8560ac*/
        if ( !BanditCampInstanceByName ) /*0x8560b0*/
          sub_73C89C(0, v831, v832); /*0x858374*/
        BanditCampInstance::PackForWeb(BanditCampInstanceByName, v826, nullptr); /*0x8560bc*/
      }
      System::Collections::Generic::List_1_T_::Enumerator<System::Object>::Dispose( /*0x8560cc*/
        &i,
        MethodInfo::System::Collections::Generic::List_1_T_::Enumerator<System::String>::Dispose);
      v167._dateData = (uint64_t)GameServerReceiver::get_connection(v833, v834); /*0x8560d0*/
      if ( !v167._dateData ) /*0x8560d4*/
        goto LABEL_1546; /*0x8560d4*/
      Connection::Send((Connection *)v167._dateData, v826, Connection_priority__Enum_DEFAULT, nullptr); /*0x8560e4*/
      if ( (v324 & 1) != 0 ) /*0x8560e8*/
        ChunkData::SaveLandClaimChunkTimersToDisk(ChunkData, v319, nullptr, nullptr); /*0x8560fc*/
      return; /*0x856100*/
    case 12:
      v427 = Packet::GetString(incoming, nullptr);// // case 0x0D: CHUNK_RESPONSE /*0x8522fc*/
      v428 = Packet::GetShort(incoming, nullptr); /*0x85230c*/
      v429 = Packet::GetShort(incoming, nullptr); /*0x852324*/
      v430 = TypeInfo::ChunkControl; /*0x852328*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x85232c*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x852338*/
        v430 = TypeInfo::ChunkControl; /*0x852344*/
      }
      v167._dateData = (uint64_t)v430->static_fields->Instance; /*0x852364*/
      if ( !v167._dateData ) /*0x852368*/
        goto LABEL_1546; /*0x852368*/
      ChunkString = (Object *)ChunkControl::GetChunkString((ChunkControl *)v167._dateData, v427, v428, v429, nullptr); /*0x852388*/
      v432 = Packet::GetByte(incoming, nullptr); /*0x852398*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x8523a4*/
      v433 = (String *)v167._dateData; /*0x8523b0*/
      if ( v432 != 1 ) /*0x8523b4*/
      {
        if ( v432 ) /*0x8523b8*/
        {
          Item = nullptr; /*0x856c64*/
        }
        else
        {
          v167._dateData = sub_73C88C(TypeInfo::ChunkData); /*0x8523c8*/
          if ( !v167._dateData ) /*0x8523cc*/
            goto LABEL_1546; /*0x8523cc*/
          Item = (ChunkData *)v167._dateData; /*0x8523d4*/
          ChunkData::ChunkData((ChunkData *)v167._dateData, nullptr); /*0x8523d8*/
          ChunkData::UnpackFromWeb(Item, incoming, nullptr); /*0x8523e8*/
          Item->mp_cache_key = v433; /*0x8523f0*/
          v167._dateData = sub_73C72C(&Item->mp_cache_key); /*0x8523f8*/
          if ( Item->mp_chunk_size >= 76 ) /*0x852404*/
          {
            if ( !byte_27E6C85 ) /*0x85240c*/
            {
              v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x852418*/
              byte_27E6C85 = 1; /*0x852420*/
            }
            v435 = TypeInfo::GameServerSender->static_fields->Instance; /*0x85242c*/
            if ( !v435 ) /*0x852430*/
              goto LABEL_1546; /*0x852430*/
            v167._dateData = (uint64_t)v435->cached_chunks; /*0x852434*/
            if ( !v167._dateData ) /*0x852438*/
              goto LABEL_1546; /*0x852438*/
            v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x852444*/
                               (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                               ChunkString,
                               MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::ContainsKey);
            v436 = v167._dateData; /*0x85244c*/
            if ( !byte_27E6C85 ) /*0x852450*/
            {
              v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x85245c*/
              byte_27E6C85 = 1; /*0x852464*/
            }
            v437 = TypeInfo::GameServerSender->static_fields->Instance; /*0x852470*/
            if ( !v437 ) /*0x852474*/
              goto LABEL_1546; /*0x852474*/
            v167._dateData = (uint64_t)v437->cached_chunks; /*0x852478*/
            if ( !v167._dateData ) /*0x85247c*/
              goto LABEL_1546; /*0x85247c*/
            if ( (v436 & 1) != 0 ) /*0x852480*/
            {
              System::Collections::Generic::Dictionary<System::Object,System::Object>::set_Item( /*0x852498*/
                (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                ChunkString,
                (Object *)Item,
                MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::set_Item);
            }
            else
            {
              v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Count( /*0x85811c*/
                                 (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                 MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::get_Count);
              if ( SLODWORD(v167._dateData) >= 41 ) /*0x858124*/
              {
                v975 = (String *)""; /*0x858134*/
                if ( !byte_27E6C85 ) /*0x858138*/
                {
                  v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x858144*/
                  byte_27E6C85 = 1; /*0x85814c*/
                }
                v976 = TypeInfo::GameServerSender->static_fields->Instance; /*0x858158*/
                if ( !v976 ) /*0x85815c*/
                  goto LABEL_1546; /*0x85815c*/
                v167._dateData = (uint64_t)v976->cached_chunks; /*0x858160*/
                if ( !v167._dateData ) /*0x858164*/
                  goto LABEL_1546; /*0x858164*/
                System::Collections::Generic::Dictionary<System::Object,System::Object>::GetEnumerator( /*0x858190*/
                  &v1003,
                  (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                  MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::GetEnumerator);
                v977 = 0.0; /*0x8581a0*/
                v1006 = v1003; /*0x8581a4*/
                while ( System::Collections::Generic::Dictionary_2_TKey_TValue_::Enumerator<System::Object,System::Object>::MoveNext( /*0x8581b8*/
                          &v1006,
                          MethodInfo::System::Collections::Generic::Dictionary_2_TKey_TValue_::Enumerator<System::String,ChunkData>::MoveNext) )
                {
                  key = v1006._current.key; /*0x8581c0*/
                  value = v1006._current.value; /*0x8581c0*/
                  if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x8581c4*/
                    j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x8581cc*/
                  v1016._dateData = System::DateTime::get_UtcNow(nullptr)._dateData; /*0x8581d4*/
                  if ( !value ) /*0x8581d8*/
                    sub_73C89C(v1016._dateData, v980._dateData, v981._dateData); /*0x8583a4*/
                  v1005._ticks = System::DateTime::op_Subtraction(v1016, (DateTime)value[6].monitor, nullptr)._ticks; /*0x8581f0*/
                  if ( !TypeInfo::System::TimeSpan->_1.cctor_finished_or_no_cctor ) /*0x8581f8*/
                    j_il2cpp_runtime_class_init_0(TypeInfo::System::TimeSpan); /*0x858204*/
                  TotalSeconds = System::TimeSpan::get_TotalSeconds(&v1005, nullptr); /*0x858210*/
                  if ( TotalSeconds > v977 ) /*0x858218*/
                  {
                    v977 = TotalSeconds; /*0x85821c*/
                    v975 = (String *)key; /*0x858220*/
                  }
                }
                System::Collections::Generic::Dictionary_2_TKey_TValue_::Enumerator<System::Object,System::Object>::Dispose( /*0x8582a0*/
                  &v1006,
                  MethodInfo::System::Collections::Generic::Dictionary_2_TKey_TValue_::Enumerator<System::String,ChunkData>::Dispose);
                v167._dateData = System::String::op_Inequality(v975, (String *)"", nullptr); /*0x8582b8*/
                if ( (v167._dateData & 1) != 0 ) /*0x8582c4*/
                {
                  if ( !byte_27E6C85 ) /*0x8582cc*/
                  {
                    v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x8582d8*/
                    byte_27E6C85 = 1; /*0x8582e0*/
                  }
                  v985 = TypeInfo::GameServerSender->static_fields->Instance; /*0x8582ec*/
                  if ( !v985 ) /*0x8582f0*/
                    goto LABEL_1546; /*0x8582f0*/
                  v167._dateData = (uint64_t)v985->cached_chunks; /*0x8582f4*/
                  if ( !v167._dateData ) /*0x8582f8*/
                    goto LABEL_1546; /*0x8582f8*/
                  v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::Remove( /*0x85830c*/
                                     (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                     (Object *)v975,
                                     MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::Remove);
                }
              }
              if ( !byte_27E6C85 ) /*0x858314*/
              {
                v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x858320*/
                byte_27E6C85 = 1; /*0x858328*/
              }
              v986 = TypeInfo::GameServerSender->static_fields->Instance; /*0x858338*/
              if ( !v986 ) /*0x858340*/
                goto LABEL_1546; /*0x858340*/
              v167._dateData = (uint64_t)v986->cached_chunks; /*0x858344*/
              if ( !v167._dateData ) /*0x858348*/
                goto LABEL_1546; /*0x858348*/
              System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x858360*/
                (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                ChunkString,
                (Object *)Item,
                MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::Add);
            }
          }
        }
        goto LABEL_1219; /*0x85249c*/
      }
      v873 = TypeInfo::GameServerSender->static_fields->Instance; /*0x856aa4*/
      if ( !v873 ) /*0x856aa8*/
        goto LABEL_1546; /*0x856aa8*/
      v167._dateData = (uint64_t)v873->cached_chunks; /*0x856ab0*/
      if ( !v167._dateData ) /*0x856ab8*/
        goto LABEL_1546; /*0x856ab8*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x856ac4*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         ChunkString,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::ContainsKey);
      if ( (v167._dateData & 1) != 0 ) /*0x856ac8*/
      {
        v874 = TypeInfo::GameServerSender->static_fields->Instance; /*0x856ad4*/
        if ( !v874 ) /*0x856ad8*/
          goto LABEL_1546; /*0x856ad8*/
        v167._dateData = (uint64_t)v874->cached_chunks; /*0x856adc*/
        if ( !v167._dateData ) /*0x856ae0*/
          goto LABEL_1546; /*0x856ae0*/
        v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x856af4*/
                                     (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                     ChunkString,
                                     MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::get_Item);
        if ( !v167._dateData ) /*0x856af8*/
          goto LABEL_1546; /*0x856af8*/
        v167._dateData = System::String::op_Equality(*(String **)(v167._dateData + 88), v433, nullptr); /*0x856b08*/
        if ( (v167._dateData & 1) != 0 ) /*0x856b0c*/
        {
          v875 = TypeInfo::GameServerSender->static_fields->Instance; /*0x856b18*/
          if ( !v875 ) /*0x856b1c*/
            goto LABEL_1546; /*0x856b1c*/
          v167._dateData = (uint64_t)v875->cached_chunks; /*0x856b20*/
          if ( !v167._dateData ) /*0x856b24*/
            goto LABEL_1546; /*0x856b24*/
          Item = (ChunkData *)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x856b34*/
                                (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                ChunkString,
                                MethodInfo::System::Collections::Generic::Dictionary<System::String,ChunkData>::get_Item);
LABEL_1219:
          v881 = 0; /*0x856c70*/
          goto LABEL_1243; /*0x856c74*/
        }
      }
      v889 = TypeInfo::ChunkControl; /*0x856dac*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x856db0*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x856db8*/
        v889 = TypeInfo::ChunkControl; /*0x856dc4*/
      }
      v167._dateData = (uint64_t)v889->static_fields->Instance; /*0x856dcc*/
      if ( !v167._dateData ) /*0x856dd0*/
        goto LABEL_1546; /*0x856dd0*/
      ChunkControl::ChangeChunkStatus( /*0x856de0*/
        (ChunkControl *)v167._dateData,
        (String *)ChunkString,
        Chunk_status_t__Enum_pls_load_and_build,
        nullptr);
      Item = nullptr; /*0x856de4*/
      v881 = 6; /*0x856de8*/
LABEL_1243:
      v167._dateData = Packet::GetShort(incoming, nullptr); /*0x856dec*/
      v890 = SLOWORD(v167._dateData); /*0x856df8*/
      if ( SLOWORD(v167._dateData) >= 1 ) /*0x856e00*/
      {
        do /*0x856e74*/
        {
          v167._dateData = (uint64_t)BanditCampInstance::UnpackFromWeb(incoming, nullptr); /*0x856e14*/
          v891 = TypeInfo::BanditCampsControl->static_fields->Instance; /*0x856e20*/
          if ( !v891 ) /*0x856e24*/
            goto LABEL_1546; /*0x856e24*/
          v892 = v167._dateData; /*0x856e28*/
          if ( !v167._dateData ) /*0x856e2c*/
            goto LABEL_1546; /*0x856e2c*/
          v167._dateData = (uint64_t)v891->loaded_bandit_camp_instances; /*0x856e30*/
          if ( !v167._dateData ) /*0x856e34*/
            goto LABEL_1546; /*0x856e34*/
          v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x856e40*/
                             (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                             *(Object **)(v892 + 16),
                             MethodInfo::System::Collections::Generic::Dictionary<System::String,BanditCampInstance>::ContainsKey);
          if ( (v167._dateData & 1) == 0 ) /*0x856e44*/
          {
            v893 = TypeInfo::BanditCampsControl->static_fields->Instance; /*0x856e50*/
            if ( !v893 ) /*0x856e54*/
              goto LABEL_1546; /*0x856e54*/
            v167._dateData = (uint64_t)v893->loaded_bandit_camp_instances; /*0x856e58*/
            if ( !v167._dateData ) /*0x856e5c*/
              goto LABEL_1546; /*0x856e5c*/
            System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x856e6c*/
              (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
              *(Object **)(v892 + 16),
              (Object *)v892,
              MethodInfo::System::Collections::Generic::Dictionary<System::String,BanditCampInstance>::Add);
          }
          --v890; /*0x856e70*/
        }
        while ( v890 ); /*0x856e74*/
      }
      if ( !byte_27E6C85 ) /*0x856e84*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x856e90*/
        byte_27E6C85 = 1; /*0x856ea0*/
      }
      v894 = TypeInfo::GameServerSender->static_fields->Instance; /*0x856eac*/
      if ( !v894 || (v167._dateData = (uint64_t)v894->chunks_mid_request) == 0 ) /*0x856eb8*/
LABEL_1546:
        sub_73C89C(v167._dateData, v168, v169); /*0x858368*/
      System::Collections::Generic::List<System::Object>::Remove( /*0x856ec4*/
        (List_1_System_Object_ *)v167._dateData,
        ChunkString,
        MethodInfo::System::Collections::Generic::List<System::String>::Remove);
      if ( !v881 ) /*0x856ed0*/
      {
        v895 = TypeInfo::ChunkControl; /*0x856ed4*/
        if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x856ed8*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x856ee0*/
          v895 = TypeInfo::ChunkControl; /*0x856eec*/
        }
        v167._dateData = (uint64_t)v895->static_fields->Instance; /*0x856ef4*/
        if ( !v167._dateData ) /*0x856ef8*/
          goto LABEL_1546; /*0x856ef8*/
        if ( ChunkControl::ChunkExists((ChunkControl *)v167._dateData, (String *)ChunkString, nullptr) ) /*0x856f04*/
        {
          if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x856f18*/
            j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x856f20*/
          v167._dateData = System::DateTime::get_UtcNow(nullptr)._dateData; /*0x856f28*/
          if ( !Item ) /*0x856f2c*/
            goto LABEL_1546; /*0x856f2c*/
          Item->mp_cache_last_used = v167; /*0x856f30*/
          v896 = TypeInfo::ChunkControl; /*0x856f3c*/
          if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x856f40*/
          {
            j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x856f48*/
            v896 = TypeInfo::ChunkControl; /*0x856f54*/
          }
          v167._dateData = (uint64_t)v896->static_fields->Instance; /*0x856f5c*/
          if ( !v167._dateData ) /*0x856f60*/
            goto LABEL_1546; /*0x856f60*/
          v167._dateData = (uint64_t)ChunkControl::GetChunk( /*0x856f6c*/
                                       (ChunkControl *)v167._dateData,
                                       (String *)ChunkString,
                                       nullptr);
          if ( !v167._dateData ) /*0x856f70*/
            goto LABEL_1546; /*0x856f70*/
          *(_QWORD *)(v167._dateData + 40) = Item; /*0x856f74*/
          sub_73C72C(v167._dateData + 40); /*0x856f7c*/
          v167._dateData = (uint64_t)TypeInfo::ChunkControl->static_fields->Instance; /*0x856f90*/
          if ( !v167._dateData ) /*0x856f94*/
            goto LABEL_1546; /*0x856f94*/
          ChunkControl::ChangeChunkStatus( /*0x856fa4*/
            (ChunkControl *)v167._dateData,
            (String *)ChunkString,
            Chunk_status_t__Enum_MP_got_data,
            nullptr);
        }
      }
      return; /*0x856fa8*/
    case 16:
      v381 = Packet::GetString(incoming, nullptr);// // case 0x11: POSITION /*0x851b0c*/
      v1019 = GameServerReceiver::UnpackPosition((GameServerReceiver *)v381, incoming, v382); /*0x851b10*/
      v1020 = GameServerReceiver::UnpackPosition(v383, incoming, v384); /*0x851b24*/
      v1031 = GameServerReceiver::UnpackRotation(v385, incoming, v386); /*0x851b38*/
      if ( !byte_27E6C84 ) /*0x851b54*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x851b60*/
        byte_27E6C84 = 1; /*0x851b68*/
      }
      v387 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x851b7c*/
      if ( !v387 ) /*0x851b80*/
        goto LABEL_1546; /*0x851b80*/
      v167._dateData = (uint64_t)v387->nearby_players; /*0x851b84*/
      if ( !v167._dateData ) /*0x851b88*/
        goto LABEL_1546; /*0x851b88*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x851ba0*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         (Object *)v381,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x851ba4*/
        return; /*0x851ba4*/
      if ( !byte_27E6C84 ) /*0x851bb0*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x851bbc*/
        byte_27E6C84 = 1; /*0x851bc4*/
      }
      v388 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x851bd8*/
      if ( !v388 ) /*0x851bdc*/
        goto LABEL_1546; /*0x851bdc*/
      v167._dateData = (uint64_t)v388->nearby_players; /*0x851be0*/
      if ( !v167._dateData ) /*0x851be4*/
        goto LABEL_1546; /*0x851be4*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x851bf0*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   (Object *)v381,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::get_Item);
      if ( !v167._dateData ) /*0x851bf4*/
        goto LABEL_1546; /*0x851bf4*/
      v389 = v167._dateData; /*0x851bf8*/
      v390 = *(Object_1 **)(v167._dateData + 16); /*0x851c00*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x851c04*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x851c0c*/
      if ( UnityEngine::Object::op_Equality(v390, nullptr, nullptr) ) /*0x851c1c*/
        return; /*0x851c20*/
      v167._dateData = *(_QWORD *)(v389 + 16); /*0x851c24*/
      if ( !v167._dateData ) /*0x851c28*/
        goto LABEL_1546; /*0x851c28*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x851c38*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x851c3c*/
        goto LABEL_1546; /*0x851c3c*/
      if ( *(_BYTE *)(v167._dateData + 108) ) /*0x851c40*/
        return; /*0x851c44*/
      v167._dateData = *(_QWORD *)(v389 + 16); /*0x851c48*/
      if ( !v167._dateData ) /*0x851c4c*/
        goto LABEL_1546; /*0x851c4c*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x851c5c*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x851c60*/
        goto LABEL_1546; /*0x851c60*/
      v391 = *(Object_1 **)(v167._dateData + 64); /*0x851c68*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x851c6c*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x851c78*/
      v167._dateData = UnityEngine::Object::op_Inequality(v391, nullptr, nullptr); /*0x851c88*/
      if ( (v167._dateData & 1) != 0 ) /*0x851c8c*/
        return; /*0x851c8c*/
      v392 = *(_DWORD *)(v389 + 44); /*0x851c90*/
      if ( v392 ) /*0x851c94*/
        goto LABEL_355; /*0x851c94*/
      if ( !byte_27E6C84 ) /*0x851c9c*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x851ca8*/
        byte_27E6C84 = 1; /*0x851cb0*/
      }
      if ( !TypeInfo::GameServerInterface->static_fields->Instance ) /*0x851cc4*/
        goto LABEL_1546; /*0x851cc4*/
      GameServerInterface::CreateMovementSmoother( /*0x851ce8*/
        (GameServerInterface *)v167._dateData,
        *(GameObject **)(v389 + 16),
        v1019,
        v1020,
        (MethodInfo *)v169);
      v392 = 3; /*0x851cec*/
      *(_DWORD *)(v389 + 44) = 3; /*0x851cf0*/
LABEL_355:
      *(_DWORD *)(v389 + 44) = v392 - 1; /*0x851cf8*/
      v167._dateData = *(_QWORD *)(v389 + 16); /*0x851d00*/
      if ( !v167._dateData ) /*0x851d08*/
        goto LABEL_1546; /*0x851d08*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x851d10*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x851d14*/
        goto LABEL_1546; /*0x851d14*/
      SharedCreature::SetMoveTo((SharedCreature *)v167._dateData, v1020, nullptr); /*0x851d28*/
      v167._dateData = *(_QWORD *)(v389 + 16); /*0x851d2c*/
      if ( !v167._dateData ) /*0x851d30*/
        goto LABEL_1546; /*0x851d30*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x851d38*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x851d3c*/
        goto LABEL_1546; /*0x851d3c*/
      SharedCreature::SnapSpotterRotation((SharedCreature *)v167._dateData, v1031, nullptr); /*0x851d54*/
      return; /*0x851d58*/
    case 17:
      v292 = Packet::GetShort(incoming, nullptr);// // case 0x12: UNKNOWN_0x12 /*0x850f78*/
      if ( v292 < 1 ) /*0x850f84*/
        goto LABEL_236; /*0x850f84*/
      do /*0x850fbc*/
      {
        if ( !byte_27E6C84 ) /*0x850f90*/
        {
          sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x850f98*/
          byte_27E6C84 = 1; /*0x850f9c*/
        }
        v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x850fa8*/
        if ( !v167._dateData ) /*0x850fac*/
          goto LABEL_1546; /*0x850fac*/
        GameServerInterface::NewPlayerNearby((GameServerInterface *)v167._dateData, incoming, (MethodInfo *)v169); /*0x850fb4*/
        --v292; /*0x850fb8*/
      }
      while ( v292 ); /*0x850fbc*/
LABEL_236:
      v294 = Packet::GetShort(incoming, nullptr); /*0x850fc0*/
      if ( v294 >= 1 ) /*0x850fd4*/
      {
        do /*0x851018*/
        {
          if ( !byte_27E6C84 ) /*0x850fec*/
          {
            sub_73C778(&TypeInfo::GameServerInterface, v293); /*0x850ff4*/
            byte_27E6C84 = 1; /*0x850ff8*/
          }
          v168 = (uint64_t)incoming; /*0x851000*/
          v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x851008*/
          if ( !v167._dateData ) /*0x85100c*/
            goto LABEL_1546; /*0x85100c*/
          GameServerInterface::NearbyPlayerWentAway((GameServerInterface *)v167._dateData, incoming, (MethodInfo *)v169); /*0x851010*/
          --v294; /*0x851014*/
        }
        while ( v294 ); /*0x851018*/
      }
      return; /*0x851018*/
    case 18:
      v507 = Packet::GetByte(incoming, nullptr);// // case 0x13: UNKNOWN_0x13 /*0x852df0*/
      if ( v507 ) /*0x852df4*/
      {
        if ( v507 == 1 ) /*0x852dfc*/
        {
          if ( !byte_27E6C84 ) /*0x852e04*/
          {
            sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x852e14*/
            byte_27E6C84 = 1; /*0x852e1c*/
          }
          v168 = (uint64_t)incoming; /*0x852e28*/
          v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x852e34*/
          if ( v167._dateData ) /*0x852e38*/
          {
            GameServerInterface::NewPlayerNearby((GameServerInterface *)v167._dateData, incoming, (MethodInfo *)v169); /*0x852e3c*/
            return; /*0x852e40*/
          }
          goto LABEL_1546; /*0x852e38*/
        }
      }
      else
      {
        if ( !byte_27E6C84 ) /*0x856b40*/
        {
          sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x856b4c*/
          byte_27E6C84 = 1; /*0x856b54*/
        }
        v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x856b68*/
        if ( !v167._dateData ) /*0x856b6c*/
          goto LABEL_1546; /*0x856b6c*/
        GameServerInterface::NearbyPlayerWentAway((GameServerInterface *)v167._dateData, incoming, (MethodInfo *)v169); /*0x856b74*/
      }
      return; /*0x852dfc*/
    case 20:
      v508 = Packet::GetString(incoming, nullptr);// // case 0x15: START_TELEPORT /*0x852e58*/
      if ( !byte_27E6C84 ) /*0x852e5c*/
      {
        sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x852e68*/
        byte_27E6C84 = 1; /*0x852e70*/
      }
      v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x852e84*/
      if ( !v167._dateData ) /*0x852e88*/
        goto LABEL_1546; /*0x852e88*/
      GameServerInterface::StartTeleportPlayer((GameServerInterface *)v167._dateData, v508, (MethodInfo *)v169); /*0x852e90*/
      return; /*0x852e94*/
    case 21:
      v624 = Packet::GetString(incoming, nullptr);// // case 0x16: END_TELEPORT /*0x853cf4*/
      v1025 = GameServerReceiver::UnpackPosition((GameServerReceiver *)v624, incoming, v625); /*0x853cf8*/
      if ( !byte_27E6C84 ) /*0x853d10*/
      {
        sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x853d1c*/
        byte_27E6C84 = 1; /*0x853d24*/
      }
      v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x853d38*/
      if ( !v167._dateData ) /*0x853d3c*/
        goto LABEL_1546; /*0x853d3c*/
      GameServerInterface::EndTeleportPlayer((GameServerInterface *)v167._dateData, v624, v1025, (MethodInfo *)v169); /*0x853d50*/
      return; /*0x853d54*/
    case 22:
      GameServerReceiver::ReceiveDaynight(this, incoming, (MethodInfo *)&TypeInfo::Startup);// // case 0x17: UNKNOWN_0x17 /*0x853c08*/
      return; /*0x853c0c*/
    case 23:
      v282 = Packet::GetString(incoming, nullptr);// // case 0x18: CHANGE_EQUIP /*0x850e24*/
      v283 = Packet::GetByte(incoming, nullptr); /*0x850e34*/
      v285 = InventoryItem::UnpackFromWeb(incoming, nullptr); /*0x850e4c*/
      if ( !byte_27E6C84 ) /*0x850e50*/
      {
        sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x850e5c*/
        byte_27E6C84 = 1; /*0x850e64*/
      }
      v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x850e78*/
      if ( !v167._dateData ) /*0x850e7c*/
        goto LABEL_1546; /*0x850e7c*/
      GameServerInterface::PlayerChangeEquip((GameServerInterface *)v167._dateData, v282, v283, v285, v284); /*0x850e8c*/
      return; /*0x850e90*/
    case 24:
      v393 = Packet::GetString(incoming, nullptr);// // case 0x19: UPDATE_CREATURES /*0x851d80*/
      v394 = Packet::GetShort(incoming, nullptr); /*0x851d98*/
      v167._dateData = sub_73C88C(TypeInfo::System::Collections::Generic::List<System::String>); /*0x851da4*/
      if ( !v167._dateData ) /*0x851da8*/
        goto LABEL_1546; /*0x851da8*/
      v395 = (List_1_System_String_ *)v167._dateData; /*0x851db0*/
      v396 = v394; /*0x851db4*/
      System::Collections::Generic::List<System::Object>::List( /*0x851db8*/
        (List_1_System_Object_ *)v167._dateData,
        MethodInfo::System::Collections::Generic::List<System::String>::List);
      if ( v394 < 1 ) /*0x851dcc*/
        goto LABEL_367; /*0x851dcc*/
      do /*0x851e3c*/
      {
        v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x851dd8*/
        v398 = v395->_items; /*0x851de0*/
        v399 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x851de4*/
        ++v395->_version; /*0x851dec*/
        if ( !v398 ) /*0x851df0*/
          goto LABEL_1546; /*0x851df0*/
        v400 = v395->_size; /*0x851df4*/
        v401 = v167._dateData; /*0x851dfc*/
        if ( (unsigned int)v400 >= v398->max_length.size ) /*0x851e04*/
        {
          (*((void (__fastcall **)(List_1_System_String_ *, uint64_t))v399->klass->rgctx_data[11].rgctxDataDummy + 1))( /*0x851e34*/
            v395,
            v167._dateData);
        }
        else
        {
          v402 = &v398->klass + v400; /*0x851e0c*/
          v395->_size = v400 + 1; /*0x851e10*/
          v402[4] = (String__Array__Class *)v401; /*0x851e14*/
          sub_73C72C(v402 + 4); /*0x851e18*/
        }
        --v396; /*0x851e38*/
      }
      while ( v396 ); /*0x851e3c*/
LABEL_367:
      if ( !byte_27E6C84 ) /*0x851e44*/
      {
        sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x851e50*/
        byte_27E6C84 = 1; /*0x851e58*/
      }
      v167._dateData = (uint64_t)TypeInfo::GameServerInterface->static_fields->Instance; /*0x851e64*/
      if ( v167._dateData ) /*0x851e68*/
      {
        GameServerInterface::OtherPlayerChangeCreatures((GameServerInterface *)v167._dateData, v393, v395, v397); /*0x851e74*/
        return; /*0x851e78*/
      }
      goto LABEL_1546; /*0x851e68*/
    case 26:
      v167._dateData = (uint64_t)TypeInfo::PopupControl->static_fields->Instance;// // case 0x1B: CONTAINER_RESP /*0x853fd4*/
      if ( !v167._dateData ) /*0x853fd8*/
        goto LABEL_1546; /*0x853fd8*/
      PopupControl::HideAll((PopupControl *)v167._dateData, nullptr); /*0x853fe4*/
      Long = Packet::GetLong(incoming, nullptr); /*0x853ffc*/
      v167._dateData = sub_73C88C(TypeInfo::BasketContents); /*0x854004*/
      if ( !v167._dateData ) /*0x854008*/
        goto LABEL_1546; /*0x854008*/
      v643 = v167._dateData; /*0x854014*/
      BasketContents::BasketContents((BasketContents *)v167._dateData, incoming, nullptr); /*0x854018*/
      v644 = TypeInfo::inventory_ctr; /*0x85401c*/
      if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x854020*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x854028*/
        v644 = TypeInfo::inventory_ctr; /*0x85402c*/
      }
      v167._dateData = (uint64_t)v644->static_fields->Instance; /*0x854034*/
      if ( !v167._dateData ) /*0x854038*/
        goto LABEL_1546; /*0x854038*/
      v379 = Long; /*0x85403c*/
      v380 = (BasketContents *)v643; /*0x854040*/
      goto LABEL_714; /*0x854040*/
    case 27:
      v286 = Packet::GetString(incoming, nullptr);// // case 0x1C: CLOSE_BASKET /*0x850eac*/
      v287 = Packet::GetLong(incoming, nullptr); /*0x850ec4*/
      v167._dateData = sub_73C88C(TypeInfo::BasketContents); /*0x850ed0*/
      if ( !v167._dateData ) /*0x850ed4*/
        goto LABEL_1546; /*0x850ed4*/
      v288 = (BasketContents *)v167._dateData; /*0x850edc*/
      BasketContents::BasketContents((BasketContents *)v167._dateData, nullptr); /*0x850ee0*/
      BasketContents::LoadFromDiskAsContainer(v288, v287, nullptr); /*0x850ef0*/
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x850ef8*/
      if ( !v167._dateData ) /*0x850efc*/
        goto LABEL_1546; /*0x850efc*/
      v289 = (Packet *)v167._dateData; /*0x850f04*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x850f08*/
      Packet::PutByte(v289, 0x1Bu, nullptr); /*0x850f18*/
      Packet::PutString(v289, v286, nullptr); /*0x850f28*/
      Packet::PutLong(v289, v287, nullptr); /*0x850f38*/
      BasketContents::Pack(v288, v289, nullptr); /*0x850f48*/
      v167._dateData = (uint64_t)GameServerReceiver::get_connection(v290, v291); /*0x850f4c*/
      if ( !v167._dateData ) /*0x850f50*/
        goto LABEL_1546; /*0x850f50*/
      v227 = Connection_priority__Enum_DEFAULT; /*0x850f54*/
      v228 = v289; /*0x850f58*/
      goto LABEL_1396; /*0x850f5c*/
    case 28:
      v167._dateData = (uint64_t)TypeInfo::PopupControl->static_fields->Instance;// // case 0x1D: UNKNOWN_0x1D /*0x851a28*/
      if ( !v167._dateData ) /*0x851a2c*/
        goto LABEL_1546; /*0x851a2c*/
      PopupControl::HideAll((PopupControl *)v167._dateData, nullptr); /*0x851a40*/
      v167._dateData = Packet::GetLong(incoming, nullptr); /*0x851a4c*/
      v372 = TypeInfo::GameController; /*0x851a54*/
      v373 = v167._dateData; /*0x851a5c*/
      v374 = TypeInfo::LootControl->static_fields->Instance; /*0x851a68*/
      if ( !TypeInfo::GameController->_1.cctor_finished_or_no_cctor ) /*0x851a64*/
      {
        v167._dateData = j_il2cpp_runtime_class_init_0(TypeInfo::GameController); /*0x851a78*/
        v372 = TypeInfo::GameController; /*0x851a7c*/
      }
      v375 = v372->static_fields->Instance; /*0x851a84*/
      if ( !v375 || !v374 ) /*0x851a8c*/
        goto LABEL_1546; /*0x851a8c*/
      LootChest = LootControl::GenerateLootChest(v374, v375->interacting_element_item, nullptr); /*0x851a9c*/
      v377 = TypeInfo::inventory_ctr; /*0x851aa0*/
      v378 = LootChest; /*0x851aa4*/
      if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x851aa8*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x851ab4*/
        v377 = TypeInfo::inventory_ctr; /*0x851ab8*/
      }
      v167._dateData = (uint64_t)v377->static_fields->Instance; /*0x851ac0*/
      if ( !v167._dateData ) /*0x851ac4*/
        goto LABEL_1546; /*0x851ac4*/
      inventory_ctr::AddChestRespawnAndRedraw((inventory_ctr *)v167._dateData, nullptr); /*0x851acc*/
      v167._dateData = (uint64_t)TypeInfo::inventory_ctr->static_fields->Instance; /*0x851ad8*/
      if ( !v167._dateData ) /*0x851adc*/
        goto LABEL_1546; /*0x851adc*/
      v379 = v373; /*0x851ae0*/
      v380 = v378; /*0x851ae4*/
LABEL_714:
      inventory_ctr::SucceedOpenWorldContainer((inventory_ctr *)v167._dateData, v379, v380, nullptr); /*0x854044*/
      return; /*0x85404c*/
    case 29:
      v309 = Packet::GetLong(incoming, nullptr);// // case 0x1E: UNKNOWN_0x1E /*0x85125c*/
      v167._dateData = sub_73C88C(TypeInfo::BasketContents); /*0x851268*/
      if ( !v167._dateData ) /*0x85126c*/
        goto LABEL_1546; /*0x85126c*/
      v310 = (BasketContents *)v167._dateData; /*0x851278*/
      BasketContents::BasketContents((BasketContents *)v167._dateData, incoming, nullptr); /*0x85127c*/
      Packet::GetString(incoming, nullptr); /*0x851288*/
      BasketContents::SaveToAllAsContainer(v310, v309, nullptr); /*0x851298*/
      return; /*0x85129c*/
    case 31:
      v449 = InventoryItem::UnpackFromWeb(incoming, nullptr);// // case 0x20: BUILD_FURNITURE /*0x852618*/
      v450 = Packet::GetByte(incoming, nullptr); /*0x852628*/
      v451 = Packet::GetString(incoming, nullptr); /*0x852638*/
      v452 = Packet::GetShort(incoming, nullptr); /*0x852648*/
      v453 = Packet::GetShort(incoming, nullptr); /*0x852658*/
      v992 = Packet::GetShort(incoming, nullptr); /*0x852668*/
      v454 = Packet::GetShort(incoming, nullptr); /*0x852678*/
      zonec = Packet::GetString(incoming, nullptr); /*0x852688*/
      v455 = Packet::GetString(incoming, nullptr); /*0x852694*/
      v456 = TypeInfo::ChunkControl; /*0x85269c*/
      v457 = v455; /*0x8526a0*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x8526a4*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x8526b0*/
        v456 = TypeInfo::ChunkControl; /*0x8526b8*/
      }
      v167._dateData = (uint64_t)v456->static_fields->Instance; /*0x8526c0*/
      if ( !v167._dateData ) /*0x8526c4*/
        goto LABEL_1546; /*0x8526c4*/
      v458 = v453; /*0x8526cc*/
      v167._dateData = (uint64_t)ChunkControl::GetChunkString((ChunkControl *)v167._dateData, v451, v452, v453, nullptr); /*0x8526e0*/
      if ( !TypeInfo::ChunkControl->static_fields->Instance ) /*0x8526ec*/
        goto LABEL_1546; /*0x8526f0*/
      v459 = (String *)v167._dateData; /*0x8526f4*/
      v167._dateData = ChunkControl::IsChunkFullyLoadedOrMidload( /*0x852704*/
                         TypeInfo::ChunkControl->static_fields->Instance,
                         (String *)v167._dateData,
                         nullptr);
      if ( (v167._dateData & 1) != 0 ) /*0x852708*/
      {
        v460 = TypeInfo::ChunkControl; /*0x85270c*/
        if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x852710*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x852718*/
          v460 = TypeInfo::ChunkControl; /*0x85271c*/
        }
        v167._dateData = (uint64_t)v460->static_fields->Instance; /*0x852724*/
        if ( !v167._dateData ) /*0x852728*/
          goto LABEL_1546; /*0x852728*/
        v167._dateData = (uint64_t)ChunkControl::GetChunk((ChunkControl *)v167._dateData, v459, nullptr); /*0x852734*/
        if ( !v167._dateData ) /*0x852738*/
          goto LABEL_1546; /*0x852738*/
LABEL_1068:
        v167._dateData = (uint64_t)TypeInfo::ConstructionControl->static_fields->Instance; /*0x856140*/
        if ( !v167._dateData ) /*0x856154*/
          goto LABEL_1546; /*0x856154*/
        ConstructionControl::PlayerBuildAt( /*0x85618c*/
          (ConstructionControl *)v167._dateData,
          v449,
          v451,
          v452,
          v458,
          v992,
          v454,
          v450,
          ConstructionControl_build_context_t__Enum_on_other_build_new,
          zonec,
          v457,
          nullptr);
        return; /*0x856190*/
      }
      if ( !byte_27E6C86 ) /*0x856108*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x856114*/
        byte_27E6C86 = 1; /*0x85611c*/
      }
      v835 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x856130*/
      if ( !v835 ) /*0x856134*/
        goto LABEL_1546; /*0x856134*/
      if ( v835->is_host_cached ) /*0x856138*/
        goto LABEL_1068; /*0x85613c*/
      if ( !v449 ) /*0x8574e8*/
        goto LABEL_1546; /*0x8574e8*/
      item_name = InventoryItem::get_item_name(v449, nullptr); /*0x8574f4*/
      if ( System::String::op_Equality(item_name, (String *)"3-day Land Claim", nullptr) /*0x857550*/
        || (v924 = InventoryItem::get_item_name(v449, nullptr),
            System::String::op_Equality(v924, (String *)"8-day Land Claim", nullptr))
        || (v925 = InventoryItem::get_item_name(v449, nullptr),
            System::String::op_Equality(v925, (String *)"Admin Land Claim", nullptr)) )
      {
        v926 = TypeInfo::LandClaimControl; /*0x857558*/
        if ( !TypeInfo::LandClaimControl->_1.cctor_finished_or_no_cctor ) /*0x85755c*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::LandClaimControl); /*0x857564*/
          v926 = TypeInfo::LandClaimControl; /*0x857568*/
        }
        v167._dateData = (uint64_t)v926->static_fields->Instance; /*0x857570*/
        if ( !v167._dateData ) /*0x857574*/
          goto LABEL_1546; /*0x857574*/
        LandClaimControl::AddLandClaimsToNearbyChunks( /*0x85759c*/
          (LandClaimControl *)v167._dateData,
          v451,
          v452,
          v458,
          v992,
          v454,
          v449,
          zonec,
          nullptr);
      }
      return; /*0x8575a0*/
    case 32:
      zoneb = Packet::GetString(incoming, nullptr);// // case 0x21: REMOVE_OBJECT /*0x851040*/
      v295 = Packet::GetShort(incoming, nullptr); /*0x851050*/
      v296 = Packet::GetShort(incoming, nullptr); /*0x851060*/
      v297 = Packet::GetShort(incoming, nullptr); /*0x851070*/
      v298 = Packet::GetShort(incoming, nullptr); /*0x851080*/
      v299 = Packet::GetByte(incoming, nullptr); /*0x851090*/
      v300 = InventoryItem::UnpackFromWeb(incoming, nullptr); /*0x8510a4*/
      v167._dateData = sub_73C88C(TypeInfo::ChunkElement); /*0x8510ac*/
      if ( !v167._dateData ) /*0x8510b0*/
        goto LABEL_1546; /*0x8510b0*/
      v301 = (ChunkElement *)v167._dateData; /*0x8510c0*/
      ChunkElement::ChunkElement((ChunkElement *)v167._dateData, v300, v299, nullptr); /*0x8510c4*/
      v302 = Packet::GetString(incoming, nullptr); /*0x8510d0*/
      v303 = TypeInfo::ChunkControl; /*0x8510d8*/
      mp_cache_key = v302; /*0x8510dc*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x8510e0*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x8510ec*/
        v303 = TypeInfo::ChunkControl; /*0x8510f4*/
      }
      v167._dateData = (uint64_t)v303->static_fields->Instance; /*0x8510fc*/
      if ( !v167._dateData ) /*0x851100*/
        goto LABEL_1546; /*0x851100*/
      v167._dateData = (uint64_t)ChunkControl::GetChunkString( /*0x851120*/
                                   (ChunkControl *)v167._dateData,
                                   zoneb,
                                   v295,
                                   v296,
                                   nullptr);
      if ( !TypeInfo::ChunkControl->static_fields->Instance ) /*0x85112c*/
        goto LABEL_1546; /*0x851130*/
      v167._dateData = ChunkControl::IsChunkFullyLoadedOrMidload( /*0x851148*/
                         TypeInfo::ChunkControl->static_fields->Instance,
                         (String *)v167._dateData,
                         nullptr);
      if ( (v167._dateData & 1) != 0 ) /*0x85114c*/
        goto LABEL_252; /*0x85114c*/
      if ( !byte_27E6C86 ) /*0x851154*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x851160*/
        byte_27E6C86 = 1; /*0x851168*/
      }
      v305 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x85117c*/
      if ( !v305 ) /*0x851180*/
        goto LABEL_1546; /*0x851180*/
      if ( v305->is_host_cached ) /*0x851184*/
      {
LABEL_252:
        v167._dateData = (uint64_t)TypeInfo::ConstructionControl->static_fields->Instance; /*0x85118c*/
        if ( v167._dateData ) /*0x8511a0*/
        {
          ConstructionControl::PlayerRemoveAt( /*0x8511c4*/
            (ConstructionControl *)v167._dateData,
            v301,
            zoneb,
            v295,
            v296,
            v297,
            v298,
            ConstructionControl_remove_context__Enum_other_remove,
            mp_cache_key,
            nullptr);
          return; /*0x8511c8*/
        }
        goto LABEL_1546; /*0x8511a0*/
      }
      if ( !v300 ) /*0x85742c*/
        goto LABEL_1546; /*0x85742c*/
      v919 = InventoryItem::get_item_name(v300, nullptr); /*0x857438*/
      if ( System::String::op_Equality(v919, (String *)"3-day Land Claim", nullptr) /*0x85749c*/
        || (v920 = InventoryItem::get_item_name(v300, nullptr),
            System::String::op_Equality(v920, (String *)"8-day Land Claim", nullptr))
        || (v921 = InventoryItem::get_item_name(v300, nullptr),
            System::String::op_Equality(v921, (String *)"Admin Land Claim", nullptr)) )
      {
        v922 = TypeInfo::LandClaimControl; /*0x8574a4*/
        if ( !TypeInfo::LandClaimControl->_1.cctor_finished_or_no_cctor ) /*0x8574ac*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::LandClaimControl); /*0x8574b4*/
          v922 = TypeInfo::LandClaimControl; /*0x8574b8*/
        }
        v167._dateData = (uint64_t)v922->static_fields->Instance; /*0x8574c0*/
        if ( !v167._dateData ) /*0x8574c4*/
          goto LABEL_1546; /*0x8574c4*/
        LandClaimControl::RemoveLandClaimsFromNearbyChunks( /*0x8574e0*/
          (LandClaimControl *)v167._dateData,
          zoneb,
          v295,
          v296,
          v297,
          v298,
          nullptr);
      }
      return; /*0x8574e4*/
    case 33:
      v700 = InventoryItem::UnpackFromWeb(incoming, nullptr);// // case 0x22: REPLACE_BUILDABLE /*0x854a70*/
      v701 = InventoryItem::UnpackFromWeb(incoming, nullptr); /*0x854a80*/
      v702 = Packet::GetByte(incoming, nullptr); /*0x854a90*/
      v703 = Packet::GetString(incoming, nullptr); /*0x854aa0*/
      v1010[1].m_value = Packet::GetShort(incoming, nullptr); /*0x854abc*/
      v1010[0].m_value = Packet::GetShort(incoming, nullptr); /*0x854ad0*/
      HIDWORD(v1009) = Packet::GetShort(incoming, nullptr); /*0x854ae4*/
      LODWORD(v1009) = Packet::GetShort(incoming, nullptr); /*0x854af8*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x854afc*/
      if ( !v701 ) /*0x854b00*/
        goto LABEL_1546; /*0x854b00*/
      v704 = (String *)v167._dateData; /*0x854b0c*/
      v705 = InventoryItem::get_item_name(v701, nullptr); /*0x854b18*/
      if ( !System::String::op_Equality(v705, (String *)"Music Box", nullptr) ) /*0x854b28*/
        goto LABEL_1428; /*0x854b28*/
      v706 = TypeInfo::MusicBoxControl; /*0x854b2c*/
      if ( !TypeInfo::MusicBoxControl->_1.cctor_finished_or_no_cctor ) /*0x854b30*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::MusicBoxControl); /*0x854b38*/
        v706 = TypeInfo::MusicBoxControl; /*0x854b3c*/
      }
      v707 = v706->static_fields->Instance; /*0x854b4c*/
      v167._dateData = sub_73C7E4(TypeInfo::System::String, 9); /*0x854b50*/
      if ( !v167._dateData ) /*0x854b54*/
        goto LABEL_1546; /*0x854b54*/
      v708 = (String__Array *)v167._dateData; /*0x854b58*/
      if ( v703 ) /*0x854b5c*/
      {
        v167._dateData = sub_73C87C(v703, *(_QWORD *)(*(_QWORD *)v167._dateData + 64LL)); /*0x854b6c*/
        if ( !v167._dateData ) /*0x854b70*/
          goto LABEL_1553; /*0x854b70*/
      }
      if ( !v708->max_length.size ) /*0x854b78*/
        goto LABEL_1547; /*0x854b78*/
      v708->vector[0] = v703; /*0x854b80*/
      v167._dateData = sub_73C72C(v708->vector); /*0x854b88*/
      if ( "," ) /*0x854b90*/
      {
        v167._dateData = sub_73C87C(",", v708->klass->_0.element_class); /*0x854ba4*/
        if ( !v167._dateData ) /*0x854ba8*/
          goto LABEL_1553; /*0x854ba8*/
        v709 = ","; /*0x854bac*/
      }
      else
      {
        v709 = nullptr; /*0x857944*/
      }
      if ( v708->max_length.size <= 1u ) /*0x857950*/
        goto LABEL_1547; /*0x857950*/
      v708->vector[1] = (String *)v709; /*0x857958*/
      sub_73C72C(&v708->vector[1]); /*0x85795c*/
      v167._dateData = (uint64_t)System::Int32::ToString(&v1010[1], nullptr); /*0x857968*/
      v949 = v167._dateData; /*0x85796c*/
      if ( v167._dateData ) /*0x857970*/
      {
        v167._dateData = sub_73C87C(v167._dateData, v708->klass->_0.element_class); /*0x857980*/
        if ( !v167._dateData ) /*0x857984*/
          goto LABEL_1553; /*0x857984*/
      }
      if ( v708->max_length.size <= 2u ) /*0x857990*/
        goto LABEL_1547; /*0x857990*/
      v708->vector[2] = (String *)v949; /*0x857998*/
      v167._dateData = sub_73C72C(&v708->vector[2]); /*0x8579a0*/
      if ( "," ) /*0x8579a8*/
      {
        v167._dateData = sub_73C87C(",", v708->klass->_0.element_class); /*0x8579bc*/
        if ( !v167._dateData ) /*0x8579c0*/
          goto LABEL_1553; /*0x8579c0*/
        v950 = ","; /*0x8579c4*/
      }
      else
      {
        v950 = nullptr; /*0x8579d0*/
      }
      if ( v708->max_length.size <= 3u ) /*0x8579dc*/
        goto LABEL_1547; /*0x8579dc*/
      v708->vector[3] = (String *)v950; /*0x8579e4*/
      sub_73C72C(&v708->vector[3]); /*0x8579e8*/
      v167._dateData = (uint64_t)System::Int32::ToString(v1010, nullptr); /*0x8579f4*/
      v951 = v167._dateData; /*0x8579f8*/
      if ( v167._dateData ) /*0x8579fc*/
      {
        v167._dateData = sub_73C87C(v167._dateData, v708->klass->_0.element_class); /*0x857a0c*/
        if ( !v167._dateData ) /*0x857a10*/
          goto LABEL_1553; /*0x857a10*/
      }
      if ( v708->max_length.size <= 4u ) /*0x857a1c*/
        goto LABEL_1547; /*0x857a1c*/
      v708->vector[4] = (String *)v951; /*0x857a24*/
      v167._dateData = sub_73C72C(&v708->vector[4]); /*0x857a2c*/
      if ( "," ) /*0x857a34*/
      {
        v167._dateData = sub_73C87C(",", v708->klass->_0.element_class); /*0x857a48*/
        if ( !v167._dateData ) /*0x857a4c*/
          goto LABEL_1553; /*0x857a4c*/
        v952 = ","; /*0x857a50*/
      }
      else
      {
        v952 = nullptr; /*0x857a5c*/
      }
      if ( v708->max_length.size <= 5u ) /*0x857a68*/
        goto LABEL_1547; /*0x857a68*/
      v708->vector[5] = (String *)v952; /*0x857a70*/
      sub_73C72C(&v708->vector[5]); /*0x857a74*/
      v167._dateData = (uint64_t)System::Int32::ToString((Int32 *)&v1009 + 1, nullptr); /*0x857a80*/
      v953 = v167._dateData; /*0x857a84*/
      if ( v167._dateData ) /*0x857a88*/
      {
        v167._dateData = sub_73C87C(v167._dateData, v708->klass->_0.element_class); /*0x857a98*/
        if ( !v167._dateData ) /*0x857a9c*/
          goto LABEL_1553; /*0x857a9c*/
      }
      if ( v708->max_length.size <= 6u ) /*0x857aa8*/
        goto LABEL_1547; /*0x857aa8*/
      v708->vector[6] = (String *)v953; /*0x857ab0*/
      v167._dateData = sub_73C72C(&v708->vector[6]); /*0x857ab8*/
      if ( "," ) /*0x857ac0*/
      {
        v167._dateData = sub_73C87C(",", v708->klass->_0.element_class); /*0x857ad4*/
        if ( !v167._dateData ) /*0x857ad8*/
          goto LABEL_1553; /*0x857ad8*/
        v954 = ","; /*0x857adc*/
      }
      else
      {
        v954 = nullptr; /*0x857ae8*/
      }
      if ( v708->max_length.size <= 7u ) /*0x857af4*/
        goto LABEL_1547; /*0x857af4*/
      v708->vector[7] = (String *)v954; /*0x857afc*/
      sub_73C72C(&v708->vector[7]); /*0x857b00*/
      v167._dateData = (uint64_t)System::Int32::ToString((Int32 *)&v1009, nullptr); /*0x857b0c*/
      v955 = v167._dateData; /*0x857b10*/
      if ( v167._dateData ) /*0x857b14*/
      {
        v167._dateData = sub_73C87C(v167._dateData, v708->klass->_0.element_class); /*0x857b24*/
        if ( !v167._dateData ) /*0x857b28*/
          goto LABEL_1553; /*0x857b28*/
      }
      if ( v708->max_length.size <= 8u ) /*0x857b34*/
        goto LABEL_1547; /*0x857b34*/
      v708->vector[8] = (String *)v955; /*0x857b3c*/
      sub_73C72C(&v708->vector[8]); /*0x857b44*/
      v167._dateData = (uint64_t)System::String::Concat(v708, nullptr); /*0x857b50*/
      if ( !v707 ) /*0x857b54*/
        goto LABEL_1546; /*0x857b54*/
      MusicBoxControl::remove_song(v707, (String *)v167._dateData, nullptr); /*0x857b64*/
LABEL_1428:
      v956 = TypeInfo::ChunkControl; /*0x857b68*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x857b70*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x857b78*/
        v956 = TypeInfo::ChunkControl; /*0x857b7c*/
      }
      v167._dateData = (uint64_t)v956->static_fields->Instance; /*0x857b88*/
      if ( !v167._dateData ) /*0x857b8c*/
        goto LABEL_1546; /*0x857b8c*/
      v167._dateData = (uint64_t)ChunkControl::GetChunkString( /*0x857ba0*/
                                   (ChunkControl *)v167._dateData,
                                   v703,
                                   v1010[1].m_value,
                                   v1010[0].m_value,
                                   nullptr);
      if ( !TypeInfo::ChunkControl->static_fields->Instance ) /*0x857bac*/
        goto LABEL_1546; /*0x857bb0*/
      v167._dateData = ChunkControl::IsChunkFullyLoadedOrMidload( /*0x857bc0*/
                         TypeInfo::ChunkControl->static_fields->Instance,
                         (String *)v167._dateData,
                         nullptr);
      if ( (v167._dateData & 1) != 0 ) /*0x857bc4*/
      {
        v167._dateData = (uint64_t)TypeInfo::ConstructionControl->static_fields->Instance; /*0x857bd8*/
        if ( !v167._dateData ) /*0x857bdc*/
          goto LABEL_1546; /*0x857bdc*/
        goto LABEL_1440; /*0x857bdc*/
      }
      if ( !byte_27E6C86 ) /*0x857be8*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerConnector, v168); /*0x857bf4*/
        byte_27E6C86 = 1; /*0x857bfc*/
      }
      v957 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x857c10*/
      if ( !v957 ) /*0x857c14*/
        goto LABEL_1546; /*0x857c14*/
      if ( v957->is_host_cached ) /*0x857c1c*/
      {
        v167._dateData = (uint64_t)TypeInfo::ConstructionControl->static_fields->Instance; /*0x857c30*/
        if ( !v167._dateData ) /*0x857c34*/
          goto LABEL_1546; /*0x857c34*/
LABEL_1440:
        ConstructionControl::PlayerReplaceAt( /*0x857c38*/
          (ConstructionControl *)v167._dateData,
          v700,
          v701,
          v702,
          v703,
          v1010[1].m_value,
          v1010[0].m_value,
          SHIDWORD(v1009),
          v1009,
          0,
          v704,
          nullptr);
      }
      return;
    case 34:
      zoned = Packet::GetString(incoming, nullptr);// // case 0x23: CHANGE_LAND_USER /*0x854910*/
      v993 = Packet::GetShort(incoming, nullptr); /*0x854920*/
      v690 = Packet::GetShort(incoming, nullptr); /*0x854930*/
      v691 = Packet::GetShort(incoming, nullptr); /*0x854940*/
      v692 = Packet::GetShort(incoming, nullptr); /*0x854950*/
      v693 = Packet::GetByte(incoming, nullptr); /*0x854960*/
      v694 = Packet::GetString(incoming, nullptr); /*0x854978*/
      v695 = (String__Array *)sub_73C7E4(TypeInfo::System::String, 9); /*0x85498c*/
      v696 = 0; /*0x854990*/
      vector = v695->vector; /*0x854994*/
      do /*0x8549f0*/
      {
        v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x8549a0*/
        if ( !v695 ) /*0x8549a4*/
          goto LABEL_1546; /*0x8549a4*/
        v698 = v167._dateData; /*0x8549a8*/
        if ( v167._dateData ) /*0x8549ac*/
        {
          v167._dateData = sub_73C87C(v167._dateData, v695->klass->_0.element_class); /*0x8549bc*/
          if ( !v167._dateData ) /*0x8549c0*/
            goto LABEL_1553; /*0x8549c0*/
        }
        if ( v696 >= (unsigned int)v695->max_length.size ) /*0x8549cc*/
          goto LABEL_1547; /*0x8549cc*/
        *vector = v698; /*0x8549dc*/
        sub_73C72C(vector); /*0x8549e0*/
        ++v696; /*0x8549e4*/
        ++vector; /*0x8549ec*/
      }
      while ( v696 != 9 ); /*0x8549f0*/
      v699 = TypeInfo::LandClaimControl; /*0x8549fc*/
      if ( !TypeInfo::LandClaimControl->_1.cctor_finished_or_no_cctor ) /*0x854a00*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::LandClaimControl); /*0x854a08*/
        v699 = TypeInfo::LandClaimControl; /*0x854a0c*/
      }
      v167._dateData = (uint64_t)v699->static_fields->Instance; /*0x854a14*/
      if ( !v167._dateData ) /*0x854a18*/
        goto LABEL_1546; /*0x854a18*/
      LandClaimControl::ModifyLandClaimTimer( /*0x854a40*/
        (LandClaimControl *)v167._dateData,
        zoned,
        v993,
        v690,
        v691,
        v692,
        v693,
        v694,
        v695,
        nullptr);
      return; /*0x854a44*/
    case 35:
      v335 = Packet::GetByte(incoming, nullptr);// // case 0x24: UNKNOWN_0x24 /*0x85159c*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x8515a8*/
      v336 = v335; /*0x8515ac*/
      v337 = (Object *)v167._dateData; /*0x8515b4*/
      switch ( v336 ) /*0x8515b8*/
      {
        case 2: /*0x8515b8*/
          v887 = TypeInfo::ZoneDataControl->static_fields->Instance; /*0x856d74*/
          if ( !v887 ) /*0x856d78*/
            goto LABEL_1546; /*0x856d78*/
          curr_zonedata_cache = v887->curr_zonedata_cache; /*0x856d7c*/
          if ( !curr_zonedata_cache ) /*0x856d80*/
            goto LABEL_1546; /*0x856d80*/
          v167._dateData = (uint64_t)curr_zonedata_cache->outdoor_land_claim_chunk_timers; /*0x856d84*/
          if ( !v167._dateData ) /*0x856d88*/
            goto LABEL_1546; /*0x856d88*/
          System::Collections::Generic::Dictionary<System::Object,System::Object>::Remove( /*0x856d9c*/
            (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
            v337,
            MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::Remove);
          break;
        case 1: /*0x8515b8*/
          v882 = Packet::GetByte(incoming, nullptr); /*0x856cd0*/
          v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x856cdc*/
          v883 = TypeInfo::ZoneDataControl->static_fields->Instance; /*0x856cec*/
          if ( !v883 ) /*0x856cf0*/
            goto LABEL_1546; /*0x856cf0*/
          v884 = v883->curr_zonedata_cache; /*0x856cf4*/
          if ( !v884 ) /*0x856cf8*/
            goto LABEL_1546; /*0x856cf8*/
          v416 = v167._dateData; /*0x856cfc*/
          v167._dateData = (uint64_t)v884->outdoor_land_claim_chunk_timers; /*0x856d00*/
          if ( !v167._dateData ) /*0x856d04*/
            goto LABEL_1546; /*0x856d04*/
          v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x856d10*/
                             (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                             v337,
                             MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::ContainsKey);
          if ( (v167._dateData & 1) != 0 ) /*0x856d14*/
          {
            v885 = TypeInfo::ZoneDataControl->static_fields->Instance; /*0x856d20*/
            if ( !v885 ) /*0x856d24*/
              goto LABEL_1546; /*0x856d24*/
            v886 = v885->curr_zonedata_cache; /*0x856d28*/
            if ( !v886 ) /*0x856d2c*/
              goto LABEL_1546; /*0x856d2c*/
            v167._dateData = (uint64_t)v886->outdoor_land_claim_chunk_timers; /*0x856d30*/
            if ( !v167._dateData ) /*0x856d34*/
              goto LABEL_1546; /*0x856d34*/
            v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x856d48*/
                                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                         v337,
                                         MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::get_Item);
            if ( v882 == 2 ) /*0x856d54*/
            {
              if ( !v167._dateData ) /*0x858290*/
                goto LABEL_1546; /*0x858290*/
LABEL_406:
              *(_QWORD *)(v167._dateData + 48) = v416; /*0x85217c*/
              v419 = v167._dateData + 48; /*0x85217c*/
            }
            else
            {
              if ( v882 != 1 ) /*0x856d5c*/
                return; /*0x856d5c*/
              if ( !v167._dateData ) /*0x856d60*/
                goto LABEL_1546; /*0x856d60*/
              *(_QWORD *)(v167._dateData + 40) = v416; /*0x856d64*/
              v419 = v167._dateData + 40; /*0x856d64*/
            }
LABEL_871:
            sub_73C72C(v419); /*0x854f68*/
            return; /*0x854f6c*/
          }
          break;
        case 0: /*0x8515b8*/
          v338 = Packet::GetShort(incoming, nullptr); /*0x8515e0*/
          v339 = Packet::GetShort(incoming, nullptr); /*0x8515f0*/
          v340 = Packet::GetShort(incoming, nullptr); /*0x851600*/
          v341 = Packet::GetShort(incoming, nullptr); /*0x851610*/
          v342 = Packet::GetString(incoming, nullptr); /*0x851624*/
          if ( !TypeInfo::System::DateTime->_1.cctor_finished_or_no_cctor ) /*0x851628*/
            j_il2cpp_runtime_class_init_0(TypeInfo::System::DateTime); /*0x851634*/
          v1011._dateData = System::DateTime::get_UtcNow(nullptr)._dateData; /*0x851644*/
          v1011._dateData = System::DateTime::AddSeconds(&v1011, (double)v338, nullptr)._dateData; /*0x85165c*/
          v1011._dateData = System::DateTime::AddMinutes(&v1011, (double)v339, nullptr)._dateData; /*0x851674*/
          v1011._dateData = System::DateTime::AddHours(&v1011, (double)v340, nullptr)._dateData; /*0x85168c*/
          v1011._dateData = System::DateTime::AddDays(&v1011, (double)v341, nullptr)._dateData; /*0x8516a8*/
          v167._dateData = (uint64_t)ChunkData::CreateLandClaimChunkTimer( /*0x8516bc*/
                                       (String *)v337,
                                       v342,
                                       (String *)"",
                                       (String *)"",
                                       v1011,
                                       nullptr);
          v343 = TypeInfo::ZoneDataControl->static_fields->Instance; /*0x8516c8*/
          if ( !v343 ) /*0x8516cc*/
            goto LABEL_1546; /*0x8516cc*/
          v344 = v343->curr_zonedata_cache; /*0x8516d0*/
          if ( !v344 ) /*0x8516d4*/
            goto LABEL_1546; /*0x8516d4*/
          v345 = (Object *)v167._dateData; /*0x8516d8*/
          v167._dateData = (uint64_t)v344->outdoor_land_claim_chunk_timers; /*0x8516dc*/
          if ( !v167._dateData ) /*0x8516e0*/
            goto LABEL_1546; /*0x8516e0*/
          v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x8516ec*/
                             (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                             v337,
                             MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::ContainsKey);
          v346 = TypeInfo::ZoneDataControl->static_fields; /*0x8516f4*/
          if ( !v346->Instance ) /*0x8516f8*/
            goto LABEL_1546; /*0x8516f8*/
          v347 = v346->Instance->curr_zonedata_cache; /*0x851700*/
          if ( !v347 ) /*0x851704*/
            goto LABEL_1546; /*0x851704*/
          v348 = v167._dateData; /*0x851708*/
          v167._dateData = (uint64_t)v347->outdoor_land_claim_chunk_timers; /*0x85170c*/
          if ( !v167._dateData ) /*0x851710*/
            goto LABEL_1546; /*0x851710*/
          if ( (v348 & 1) != 0 ) /*0x851714*/
            System::Collections::Generic::Dictionary<System::Object,System::Object>::set_Item( /*0x85172c*/
              (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
              v337,
              v345,
              MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::set_Item);
          else
            System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x857da8*/
              (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
              v337,
              v345,
              MethodInfo::System::Collections::Generic::Dictionary<System::String,LandClaimChunkTimer>::Add);
          break;
      }
      return; /*0x851730*/
    case 36:
      v412 = TypeInfo::ZoneDataControl->static_fields->Instance;// // case 0x25: UNKNOWN_0x25 /*0x85201c*/
      if ( !v412 ) /*0x852020*/
        goto LABEL_1546; /*0x852020*/
      v167._dateData = (uint64_t)v412->curr_zonedata_cache; /*0x852024*/
      if ( !v167._dateData ) /*0x85202c*/
        goto LABEL_1546; /*0x85202c*/
      ZoneData::ClearOutdoorLandClaims((ZoneData *)v167._dateData, nullptr); /*0x852038*/
      v167._dateData = (uint64_t)TypeInfo::ChunkControl; /*0x85203c*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x852040*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x852048*/
        v167._dateData = (uint64_t)TypeInfo::ChunkControl; /*0x85204c*/
      }
      v413 = **(_QWORD **)(v167._dateData + 184); /*0x852054*/
      if ( !v413 ) /*0x852058*/
        goto LABEL_1546; /*0x852058*/
      v167._dateData = (uint64_t)ZoneData::UnpackFromWeb(incoming, *(String **)(v413 + 104), nullptr); /*0x852068*/
      v414 = TypeInfo::ZoneDataControl->static_fields->Instance; /*0x852074*/
      if ( !v414 ) /*0x852078*/
        goto LABEL_1546; /*0x852078*/
      v414->curr_zonedata_cache = (ZoneData *)v167._dateData; /*0x85207c*/
      sub_73C72C(&v414->curr_zonedata_cache); /*0x852088*/
      v167._dateData = (uint64_t)TypeInfo::ZoneDataControl->static_fields->Instance; /*0x852094*/
      if ( !v167._dateData ) /*0x852098*/
        goto LABEL_1546; /*0x852098*/
      ZoneDataControl::UpdateZoneItemOnChangedOutside((ZoneDataControl *)v167._dateData, nullptr); /*0x8520a0*/
      return; /*0x8520a4*/
    case 37:
      v518 = Packet::GetShort(incoming, nullptr);// // case 0x26: LOGIN /*0x85308c*/
      v167._dateData = sub_73C88C(TypeInfo::System::Collections::Generic::List<System::String>); /*0x853098*/
      if ( !v167._dateData ) /*0x85309c*/
        goto LABEL_1546; /*0x85309c*/
      v519 = (List_1_System_Object_ *)v167._dateData; /*0x8530a4*/
      v520 = v518; /*0x8530a8*/
      System::Collections::Generic::List<System::Object>::List( /*0x8530ac*/
        (List_1_System_Object_ *)v167._dateData,
        MethodInfo::System::Collections::Generic::List<System::String>::List);
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x8530b8*/
      v521 = (String *)v167._dateData; /*0x8530c8*/
      if ( v520 < 1 ) /*0x8530cc*/
        goto LABEL_556; /*0x8530cc*/
      v522 = v520; /*0x8530d0*/
      do /*0x853148*/
      {
        v523 = v519->_items; /*0x8530d8*/
        v524 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x8530dc*/
        ++v519->_version; /*0x8530e4*/
        if ( !v523 ) /*0x8530e8*/
          goto LABEL_1546; /*0x8530e8*/
        v525 = v519->_size; /*0x8530ec*/
        if ( (unsigned int)v525 >= v523->max_length.size ) /*0x8530f8*/
        {
          (*((void (__fastcall **)(List_1_System_Object_ *, String *))v524->klass->rgctx_data[11].rgctxDataDummy + 1))( /*0x853130*/
            v519,
            v521);
        }
        else
        {
          v526 = &v523->klass + v525; /*0x853100*/
          v519->_size = v525 + 1; /*0x853104*/
          v526[4] = (Object__Array__Class *)v521; /*0x853108*/
          sub_73C72C(v526 + 4); /*0x853110*/
        }
        v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x85313c*/
        --v522; /*0x853140*/
        v521 = (String *)v167._dateData; /*0x853144*/
      }
      while ( v522 ); /*0x853148*/
LABEL_556:
      v527 = Packet::GetString(incoming, nullptr); /*0x85314c*/
      v528 = Packet::GetByte(incoming, nullptr); /*0x853164*/
      v531 = v528; /*0x85316c*/
      if ( !byte_27E6C81 ) /*0x853170*/
      {
        v528 = sub_73C778(&TypeInfo::UnityEngine::Vector3, v529); /*0x85317c*/
        byte_27E6C81 = 1; /*0x853184*/
      }
      if ( (v531 & 0xFE) == 2 ) /*0x853190*/
      {
        v1023 = GameServerReceiver::UnpackPosition((GameServerReceiver *)v528, incoming, v530); /*0x853198*/
        v532 = v1023.x; /*0x85319c*/
        v533 = v1023.y; /*0x8531a0*/
        v534 = v1023.z; /*0x8531a4*/
      }
      else
      {
        v842 = TypeInfo::UnityEngine::Vector3->static_fields; /*0x856340*/
        v532 = v842->zeroVector.x; /*0x856344*/
        v533 = v842->zeroVector.y; /*0x856344*/
        v534 = v842->zeroVector.z; /*0x856348*/
      }
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x85635c*/
      if ( !v167._dateData ) /*0x856360*/
        goto LABEL_1546; /*0x856360*/
      v837 = (Packet *)v167._dateData; /*0x856368*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x85636c*/
      Packet::PutByte(v837, 0x26u, nullptr); /*0x85637c*/
      Packet::PutShort(v837, (float)v520, nullptr); /*0x85638c*/
      if ( v520 < 1 ) /*0x856394*/
        goto LABEL_1094; /*0x856394*/
      for ( j = 0; j != v520; ++j ) /*0x856398*/
      {
        v844 = System::Collections::Generic::List<System::Object>::get_Item( /*0x8563a8*/
                 v519,
                 j,
                 MethodInfo::System::Collections::Generic::List<System::String>::get_Item);
        Packet::PutString(v837, (String *)v844, nullptr); /*0x8563b8*/
        v845 = TypeInfo::ZoneDataControl->static_fields->Instance; /*0x8563d0*/
        v167._dateData = (uint64_t)System::Collections::Generic::List<System::Object>::get_Item( /*0x8563d4*/
                                     v519,
                                     j,
                                     MethodInfo::System::Collections::Generic::List<System::String>::get_Item);
        if ( !v845 ) /*0x8563d8*/
          goto LABEL_1546; /*0x8563d8*/
        v167._dateData = (uint64_t)ZoneDataControl::LoadZoneDataFromDisk(v845, (String *)v167._dateData, nullptr); /*0x8563e8*/
        if ( !v167._dateData ) /*0x8563ec*/
          goto LABEL_1546; /*0x8563ec*/
        v846 = (ZoneData *)v167._dateData; /*0x8563f8*/
        ZoneData::PackForWeb((ZoneData *)v167._dateData, v837, nullptr); /*0x8563fc*/
        ZoneData::ClearOutdoorLandClaims(v846, nullptr); /*0x856408*/
      }
LABEL_1094:
      Packet::PutString(v837, v521, nullptr); /*0x856418*/
      Packet::PutString(v837, v527, nullptr); /*0x85643c*/
      Packet::PutByte(v837, v531, nullptr); /*0x85644c*/
      if ( (v531 & 0xFE) != 2 ) /*0x856454*/
        goto LABEL_1394; /*0x856454*/
      if ( !byte_27E6C85 ) /*0x856460*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x85646c*/
        byte_27E6C85 = 1; /*0x856474*/
      }
      if ( !TypeInfo::GameServerSender->static_fields->Instance ) /*0x856484*/
        goto LABEL_1546; /*0x856484*/
      v1038.x = v532; /*0x85648c*/
      v1038.y = v533; /*0x856490*/
      v1038.z = v534; /*0x856494*/
      GameServerSender::PackPosition((GameServerSender *)v167._dateData, v837, v1038, (MethodInfo *)v169); /*0x856498*/
      goto LABEL_1394; /*0x85649c*/
    case 38:
      v415 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x27: CLAIM_OBJECT /*0x8520c0*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x8520cc*/
      v416 = v167._dateData; /*0x8520d8*/
      if ( !byte_27E6C84 ) /*0x8520dc*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x8520e8*/
        byte_27E6C84 = 1; /*0x8520f0*/
      }
      v417 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x852104*/
      if ( !v417 ) /*0x852108*/
        goto LABEL_1546; /*0x852108*/
      v167._dateData = (uint64_t)v417->nearby_players; /*0x85210c*/
      if ( !v167._dateData ) /*0x852110*/
        goto LABEL_1546; /*0x852110*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x852124*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v415,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x852128*/
        return; /*0x852128*/
      if ( !byte_27E6C84 ) /*0x852130*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x852140*/
        byte_27E6C84 = 1; /*0x852148*/
      }
      v418 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x85215c*/
      if ( v418 ) /*0x852160*/
      {
        v167._dateData = (uint64_t)v418->nearby_players; /*0x852164*/
        if ( v167._dateData ) /*0x852168*/
        {
          v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x852174*/
                                       (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                       v415,
                                       MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::get_Item);
          if ( v167._dateData ) /*0x852178*/
            goto LABEL_406; /*0x852178*/
        }
      }
      goto LABEL_1546; /*0x852178*/
    case 39:
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr);// // case 0x28: RELEASE_INTERACTING /*0x854eb0*/
      v724 = (Object *)v167._dateData; /*0x854ebc*/
      if ( !byte_27E6C84 ) /*0x854ec0*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x854ecc*/
        byte_27E6C84 = 1; /*0x854ed4*/
      }
      v725 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x854ee8*/
      if ( !v725 ) /*0x854eec*/
        goto LABEL_1546; /*0x854eec*/
      v167._dateData = (uint64_t)v725->nearby_players; /*0x854ef0*/
      if ( !v167._dateData ) /*0x854ef4*/
        goto LABEL_1546; /*0x854ef4*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x854f08*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v724,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x854f0c*/
        return; /*0x854f0c*/
      if ( !byte_27E6C84 ) /*0x854f14*/
      {
        v167._dateData = sub_73C778(&TypeInfo::GameServerInterface, v168); /*0x854f24*/
        byte_27E6C84 = 1; /*0x854f2c*/
      }
      v726 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x854f40*/
      if ( !v726 ) /*0x854f44*/
        goto LABEL_1546; /*0x854f44*/
      v167._dateData = (uint64_t)v726->nearby_players; /*0x854f48*/
      if ( !v167._dateData ) /*0x854f4c*/
        goto LABEL_1546; /*0x854f4c*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x854f58*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v724,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::get_Item);
      if ( !v167._dateData ) /*0x854f5c*/
        goto LABEL_1546; /*0x854f5c*/
      *(_QWORD *)(v167._dateData + 48) = ""; /*0x854f64*/
      v419 = v167._dateData + 48; /*0x854f64*/
      goto LABEL_871; /*0x854f64*/
    case 40:
      v325 = Packet::GetString(incoming, nullptr);// // case 0x29: REQ_MORE_IDS /*0x8513d8*/
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x8513e4*/
      if ( !v167._dateData ) /*0x8513e8*/
        goto LABEL_1546; /*0x8513e8*/
      v326 = (Packet *)v167._dateData; /*0x8513f0*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x8513f4*/
      Packet::PutByte(v326, 0x2Au, nullptr); /*0x851404*/
      Packet::PutString(v326, v325, nullptr); /*0x851414*/
      Packet::PutShort(v326, 10.0, nullptr); /*0x851424*/
      v327 = 10; /*0x851434*/
      do /*0x851540*/
      {
        v167._dateData = (uint64_t)TypeInfo::ConstructionControl->static_fields->Instance; /*0x851444*/
        if ( !v167._dateData ) /*0x851448*/
          goto LABEL_1546; /*0x851448*/
        v328 = ConstructionControl::GetNewUniqueId((ConstructionControl *)v167._dateData, 1, nullptr); /*0x851458*/
        Packet::PutLong(v326, v328, nullptr); /*0x851468*/
        v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x85146c*/
        if ( !v167._dateData ) /*0x851470*/
          goto LABEL_1546; /*0x851470*/
        if ( !System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x851480*/
                (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                (Object *)v325,
                MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::ContainsKey) )
        {
          v329 = (Dictionary_2_System_Object_System_Object_ *)this->unique_ids_given_away; /*0x851488*/
          v167._dateData = sub_73C88C(TypeInfo::System::Collections::Generic::List<int>); /*0x85148c*/
          if ( !v167._dateData ) /*0x851490*/
            goto LABEL_1546; /*0x851490*/
          v330 = (Object *)v167._dateData; /*0x85149c*/
          System::Collections::Generic::List<int>::List( /*0x8514a4*/
            (List_1_System_Int32_ *)v167._dateData,
            MethodInfo::System::Collections::Generic::List<int>::List);
          if ( !v329 ) /*0x8514a8*/
            goto LABEL_1546; /*0x8514a8*/
          System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x8514c4*/
            v329,
            (Object *)v325,
            v330,
            MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::Add);
        }
        v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x8514d0*/
        if ( !v167._dateData ) /*0x8514d4*/
          goto LABEL_1546; /*0x8514d4*/
        v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8514e0*/
                                     (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                     (Object *)v325,
                                     MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::get_Item);
        if ( !v167._dateData ) /*0x8514e4*/
          goto LABEL_1546; /*0x8514e4*/
        v331 = *(_QWORD *)(v167._dateData + 16); /*0x8514ec*/
        v332 = MethodInfo::System::Collections::Generic::List<int>::Add; /*0x8514f0*/
        ++*(_DWORD *)(v167._dateData + 28); /*0x8514f8*/
        if ( !v331 ) /*0x8514fc*/
          goto LABEL_1546; /*0x8514fc*/
        v333 = *(int *)(v167._dateData + 24); /*0x851500*/
        if ( (unsigned int)v333 >= *(_DWORD *)(v331 + 24) ) /*0x85150c*/
        {
          v167._dateData = (*((__int64 (__fastcall **)(uint64_t, _QWORD))v332->klass->rgctx_data[11].rgctxDataDummy + 1))( /*0x851538*/
                             v167._dateData,
                             v328);
        }
        else
        {
          *(_DWORD *)(v167._dateData + 24) = v333 + 1; /*0x851518*/
          *(_DWORD *)(v331 + 4 * v333 + 32) = v328; /*0x85151c*/
        }
        --v327; /*0x85153c*/
      }
      while ( v327 ); /*0x851540*/
      v167._dateData = (uint64_t)GameServerReceiver::get_connection( /*0x851544*/
                                   (GameServerReceiver *)v167._dateData,
                                   (MethodInfo *)v168);
      if ( !v167._dateData ) /*0x851548*/
        goto LABEL_1546; /*0x851548*/
      Connection::Send((Connection *)v167._dateData, v326, Connection_priority__Enum_DEFAULT, nullptr); /*0x851558*/
      if ( !TypeInfo::UnityEngine::Debug->_1.cctor_finished_or_no_cctor ) /*0x851568*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Debug); /*0x851570*/
      v334 = "sent:10 more unique ids"; /*0x85157c*/
LABEL_859:
      UnityEngine::Debug::Log((Object *)v334, nullptr); /*0x854e90*/
      return; /*0x854e98*/
    case 41:
      v167._dateData = Packet::GetShort(incoming, nullptr);// // case 0x2A: UNIQUE_ID_SEND /*0x853c1c*/
      v617 = SLOWORD(v167._dateData); /*0x853c30*/
      if ( SLOWORD(v167._dateData) < 1 ) /*0x853c38*/
        goto LABEL_688; /*0x853c38*/
      do /*0x853cbc*/
      {
        v618 = TypeInfo::ConstructionControl->static_fields->Instance; /*0x853c44*/
        if ( !v618 ) /*0x853c48*/
          goto LABEL_1546; /*0x853c48*/
        v619 = v618->online_unique_ids_; /*0x853c4c*/
        v167._dateData = Packet::GetLong(incoming, nullptr); /*0x853c58*/
        if ( !v619 ) /*0x853c5c*/
          goto LABEL_1546; /*0x853c5c*/
        v620 = v619->_items; /*0x853c64*/
        v621 = MethodInfo::System::Collections::Generic::List<int>::Add; /*0x853c68*/
        ++v619->_version; /*0x853c70*/
        if ( !v620 ) /*0x853c74*/
          goto LABEL_1546; /*0x853c74*/
        v622 = v619->_size; /*0x853c78*/
        v168 = LODWORD(v167._dateData); /*0x853c80*/
        if ( (unsigned int)v622 >= v620->max_length.size ) /*0x853c88*/
        {
          v167._dateData = (*((__int64 (__fastcall **)(List_1_System_Int32_ *, _QWORD))v621->klass->rgctx_data[11].rgctxDataDummy /*0x853cb4*/
                            + 1))(
                             v619,
                             LODWORD(v167._dateData));
        }
        else
        {
          v619->_size = v622 + 1; /*0x853c94*/
          v620->vector[v622] = v167._dateData; /*0x853c98*/
        }
        --v617; /*0x853cb8*/
      }
      while ( v617 ); /*0x853cbc*/
LABEL_688:
      v623 = TypeInfo::GameServerSender->static_fields->Instance; /*0x853cc0*/
      if ( !v623 ) /*0x853cd4*/
        goto LABEL_1546; /*0x853cd4*/
      v623->requesting_unique_ids = 0; /*0x853cd8*/
      return; /*0x853cdc*/
    case 42:
      v722 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x2B: USED_UNIQUE_ID /*0x854e10*/
      v167._dateData = Packet::GetLong(incoming, nullptr); /*0x854e1c*/
      if ( !this->unique_ids_given_away ) /*0x854e28*/
        goto LABEL_1546; /*0x854e28*/
      v723 = v167._dateData; /*0x854e30*/
      if ( !System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x854e44*/
              (Dictionary_2_System_Object_System_Object_ *)this->unique_ids_given_away,
              v722,
              MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::ContainsKey) )
        goto LABEL_856; /*0x854e44*/
      v167._dateData = (uint64_t)this->unique_ids_given_away; /*0x854e48*/
      if ( !v167._dateData ) /*0x854e4c*/
        goto LABEL_1546; /*0x854e4c*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x854e58*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v722,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,System::Collections::Generic::List<int>>::get_Item);
      if ( !v167._dateData ) /*0x854e5c*/
        goto LABEL_1546; /*0x854e5c*/
      System::Collections::Generic::List<int>::Remove( /*0x854e70*/
        (List_1_System_Int32_ *)v167._dateData,
        v723,
        MethodInfo::System::Collections::Generic::List<int>::Remove);
LABEL_856:
      if ( !TypeInfo::UnityEngine::Debug->_1.cctor_finished_or_no_cctor ) /*0x854e7c*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Debug); /*0x854e88*/
      v334 = "[unique id used up!]"; /*0x854e8c*/
      goto LABEL_859; /*0x854e8c*/
    case 44:
      v265 = Packet::GetString(incoming, nullptr);// // case 0x2D: MUSIC_BOX_NOTE /*0x850b88*/
      v266 = Packet::GetByte(incoming, nullptr); /*0x850b98*/
      v267 = Packet::GetShort(incoming, nullptr); /*0x850ba8*/
      v268 = Packet::GetShort(incoming, nullptr); /*0x850bb8*/
      v1013[0].m_value = Packet::GetShort(incoming, nullptr); /*0x850bd0*/
      if ( v266 ) /*0x850bd4*/
      {
        if ( v266 == 1 ) /*0x850bdc*/
        {
          v269 = TypeInfo::MusicBoxControl; /*0x850be0*/
          if ( !TypeInfo::MusicBoxControl->_1.cctor_finished_or_no_cctor ) /*0x850be4*/
          {
            j_il2cpp_runtime_class_init_0(TypeInfo::MusicBoxControl); /*0x850bec*/
            v269 = TypeInfo::MusicBoxControl; /*0x850bf0*/
          }
          v167._dateData = (uint64_t)v269->static_fields->Instance; /*0x850bf8*/
          if ( v167._dateData ) /*0x850bfc*/
          {
            MusicBoxControl::online_finger_pressed( /*0x850c14*/
              (MusicBoxControl *)v167._dateData,
              v265,
              v267,
              v268,
              v1013[0].m_value,
              nullptr);
            return; /*0x850c18*/
          }
          goto LABEL_1546; /*0x850bfc*/
        }
        return; /*0x850bdc*/
      }
      v868 = TypeInfo::MusicBoxControl; /*0x8569bc*/
      if ( !TypeInfo::MusicBoxControl->_1.cctor_finished_or_no_cctor ) /*0x8569c0*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::MusicBoxControl); /*0x8569c8*/
        v868 = TypeInfo::MusicBoxControl; /*0x8569cc*/
      }
      v869 = v868->static_fields->Instance; /*0x8569e0*/
      v167._dateData = sub_73C7E4(TypeInfo::System::String, 5); /*0x8569e4*/
      if ( !v167._dateData ) /*0x8569e8*/
        goto LABEL_1546; /*0x8569e8*/
      v870 = (String__Array *)v167._dateData; /*0x8569ec*/
      if ( v265 ) /*0x8569f0*/
      {
        v167._dateData = sub_73C87C(v265, *(_QWORD *)(*(_QWORD *)v167._dateData + 64LL)); /*0x856a00*/
        if ( !v167._dateData ) /*0x856a04*/
          goto LABEL_1553; /*0x856a04*/
      }
      if ( !v870->max_length.size ) /*0x856a0c*/
        goto LABEL_1547; /*0x856a0c*/
      v870->vector[0] = v265; /*0x856a14*/
      v167._dateData = sub_73C72C(v870->vector); /*0x856a1c*/
      if ( "," ) /*0x856a24*/
      {
        v167._dateData = sub_73C87C(",", v870->klass->_0.element_class); /*0x856a38*/
        if ( !v167._dateData ) /*0x856a3c*/
          goto LABEL_1553; /*0x856a3c*/
        v871 = ","; /*0x856a40*/
      }
      else
      {
        v871 = nullptr; /*0x857c7c*/
      }
      if ( v870->max_length.size <= 1u ) /*0x857c88*/
        goto LABEL_1547; /*0x857c88*/
      v870->vector[1] = (String *)v871; /*0x857c90*/
      sub_73C72C(&v870->vector[1]); /*0x857c94*/
      v1012.m_value = v268 + v267; /*0x857ca4*/
      v167._dateData = (uint64_t)System::Int32::ToString(&v1012, nullptr); /*0x857ca8*/
      v958 = v167._dateData; /*0x857cac*/
      if ( v167._dateData ) /*0x857cb0*/
      {
        v167._dateData = sub_73C87C(v167._dateData, v870->klass->_0.element_class); /*0x857cc0*/
        if ( !v167._dateData ) /*0x857cc4*/
          goto LABEL_1553; /*0x857cc4*/
      }
      if ( v870->max_length.size <= 2u ) /*0x857cd0*/
        goto LABEL_1547; /*0x857cd0*/
      v870->vector[2] = (String *)v958; /*0x857cd8*/
      v167._dateData = sub_73C72C(&v870->vector[2]); /*0x857ce0*/
      if ( "," ) /*0x857ce8*/
      {
        v167._dateData = sub_73C87C(",", v870->klass->_0.element_class); /*0x857cfc*/
        if ( !v167._dateData ) /*0x857d00*/
          goto LABEL_1553; /*0x857d00*/
        v959 = ","; /*0x857d04*/
      }
      else
      {
        v959 = nullptr; /*0x857d10*/
      }
      if ( v870->max_length.size <= 3u ) /*0x857d1c*/
        goto LABEL_1547; /*0x857d1c*/
      v870->vector[3] = (String *)v959; /*0x857d24*/
      sub_73C72C(&v870->vector[3]); /*0x857d28*/
      v167._dateData = (uint64_t)System::Int32::ToString(v1013, nullptr); /*0x857d34*/
      v960 = v167._dateData; /*0x857d38*/
      if ( !v167._dateData || (v167._dateData = sub_73C87C(v167._dateData, v870->klass->_0.element_class)) != 0 ) /*0x857d50*/
      {
        if ( v870->max_length.size > 4u ) /*0x857d5c*/
        {
          v870->vector[4] = (String *)v960; /*0x857d64*/
          sub_73C72C(&v870->vector[4]); /*0x857d6c*/
          v167._dateData = (uint64_t)System::String::Concat(v870, nullptr); /*0x857d78*/
          if ( !v869 ) /*0x857d7c*/
            goto LABEL_1546; /*0x857d7c*/
          MusicBoxControl::remove_online_finger_note(v869, (String *)v167._dateData, nullptr); /*0x857d8c*/
          return; /*0x857d90*/
        }
        goto LABEL_1547; /*0x857d5c*/
      }
LABEL_1553:
      v987 = sub_73C8C0(); /*0x858384*/
      sub_73C864(v987, 0); /*0x85838c*/
    case 45:
      v580 = Packet::GetString(incoming, nullptr);// // case 0x2E: REQ_TELE_PAGE /*0x8537b8*/
      v581 = Packet::GetByte(incoming, nullptr); /*0x8537c8*/
      if ( v581 == 1 ) /*0x8537d0*/
      {
        v876 = Packet::GetString(incoming, nullptr); /*0x856b88*/
        v877 = Packet::GetShort(incoming, nullptr); /*0x856b98*/
        v878 = Packet::GetShort(incoming, nullptr); /*0x856ba8*/
        v879 = Packet::GetShort(incoming, nullptr); /*0x856bb8*/
        v167._dateData = Packet::GetShort(incoming, nullptr); /*0x856bc4*/
        if ( !TypeInfo::CustomTeleporterControl->static_fields->Instance ) /*0x856bd0*/
          goto LABEL_1546; /*0x856bd0*/
        v167._dateData = CustomTeleporterControl::GetCustomTeleId( /*0x856bf4*/
                           TypeInfo::CustomTeleporterControl->static_fields->Instance,
                           v876,
                           v877,
                           v878,
                           v879,
                           SLOWORD(v167._dateData),
                           nullptr);
        if ( !TypeInfo::CustomTeleporterControl->static_fields->Instance ) /*0x856c08*/
          goto LABEL_1546; /*0x856c08*/
        CorrespondingTelePage = CustomTeleporterControl::FindCorrespondingTelePage( /*0x856c28*/
                                  TypeInfo::CustomTeleporterControl->static_fields->Instance,
                                  v167._dateData,
                                  nullptr);
        if ( !byte_27E6C85 ) /*0x856c2c*/
        {
          sub_73C778(&TypeInfo::GameServerSender, v168); /*0x856c38*/
          byte_27E6C85 = 1; /*0x856c40*/
        }
        v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x856c4c*/
        if ( !v167._dateData ) /*0x856c50*/
          goto LABEL_1546; /*0x856c50*/
        v585 = v580; /*0x856c54*/
        v584 = CorrespondingTelePage; /*0x856c58*/
      }
      else
      {
        if ( v581 ) /*0x8537d4*/
          return; /*0x8537d4*/
        v583 = Packet::GetShort(incoming, nullptr); /*0x8537ec*/
        if ( !byte_27E6C85 ) /*0x8537f0*/
        {
          sub_73C778(&TypeInfo::GameServerSender, v168); /*0x8537fc*/
          byte_27E6C85 = 1; /*0x853804*/
        }
        v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x853818*/
        if ( !v167._dateData ) /*0x85381c*/
          goto LABEL_1546; /*0x85381c*/
        v584 = v583; /*0x853820*/
        v585 = v580; /*0x853824*/
      }
      GameServerSender::PackPageOfTeleporters((GameServerSender *)v167._dateData, v585, v584, v582); /*0x856c5c*/
      return; /*0x856c60*/
    case 46:
      v167._dateData = (uint64_t)TypeInfo::PopupControl->static_fields->Instance;// // case 0x2F: REQ_TELEPORTERS /*0x850838*/
      if ( !v167._dateData ) /*0x85083c*/
        goto LABEL_1546; /*0x85083c*/
      PopupControl::HideAll((PopupControl *)v167._dateData, nullptr); /*0x85084c*/
      v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x850850*/
      if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x85085c*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x850864*/
        v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x850868*/
      }
      v252 = **(_QWORD **)(v167._dateData + 184); /*0x850870*/
      if ( !v252 ) /*0x850874*/
        goto LABEL_1546; /*0x850874*/
      v167._dateData = *(_QWORD *)(v252 + 1072); /*0x850878*/
      if ( !v167._dateData ) /*0x85087c*/
        goto LABEL_1546; /*0x85087c*/
      UnityEngine::GameObject::SetActive((GameObject *)v167._dateData, 1, nullptr); /*0x850888*/
      v167._dateData = (uint64_t)TypeInfo::inventory_ctr->static_fields->Instance; /*0x850894*/
      if ( !v167._dateData ) /*0x850898*/
        goto LABEL_1546; /*0x850898*/
      inventory_ctr::LayOutCraftingTab( /*0x8508ac*/
        (inventory_ctr *)v167._dateData,
        inventory_ctr_background_strip_layout__Enum_normal,
        nullptr);
      v253 = Packet::GetShort(incoming, nullptr); /*0x8508bc*/
      v254 = Packet::GetByte(incoming, nullptr); /*0x8508cc*/
      v255 = Packet::GetByte(incoming, nullptr); /*0x8508dc*/
      v256 = 0; /*0x8508e0*/
      while ( 2 ) /*0x8508f8*/
      {
        if ( Packet::GetByte(incoming, nullptr) == 1 ) /*0x8508f8*/
        {
          v167._dateData = sub_73C88C(TypeInfo::OnlineTeleporter); /*0x850900*/
          if ( !v167._dateData ) /*0x850904*/
            goto LABEL_1546; /*0x850904*/
          v257 = (OnlineTeleporter *)v167._dateData; /*0x850908*/
          OnlineTeleporter::OnlineTeleporter((OnlineTeleporter *)v167._dateData, (MethodInfo *)v168); /*0x85090c*/
          v257->title = Packet::GetString(incoming, nullptr); /*0x850924*/
          sub_73C72C(&v257->title); /*0x850928*/
          v257->description = Packet::GetString(incoming, nullptr); /*0x850940*/
          sub_73C72C(&v257->description); /*0x850944*/
          v257->tele_str = Packet::GetString(incoming, nullptr); /*0x85095c*/
          sub_73C72C(&v257->tele_str); /*0x850960*/
          v257->to_zone = Packet::GetString(incoming, nullptr); /*0x850978*/
          sub_73C72C(&v257->to_zone); /*0x85097c*/
          v257->to_chunkX = Packet::GetShort(incoming, nullptr); /*0x850998*/
          v257->to_chunkZ = Packet::GetShort(incoming, nullptr); /*0x8509ac*/
          v257->to_innerX = Packet::GetShort(incoming, nullptr); /*0x8509c0*/
          v257->to_innerZ = Packet::GetShort(incoming, nullptr); /*0x8509d4*/
          v257->built_by = Packet::GetString(incoming, nullptr); /*0x8509e4*/
          v167._dateData = sub_73C72C(&v257->built_by); /*0x8509e8*/
          if ( v256 == 2 ) /*0x8509f0*/
          {
            v263 = TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x850ad8*/
            if ( !v263 ) /*0x850adc*/
              goto LABEL_1546; /*0x850adc*/
            p_teleporter_R = &v263->teleporter_R; /*0x850ae0*/
          }
          else if ( v256 == 1 ) /*0x8509f8*/
          {
            v262 = TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x850ac0*/
            if ( !v262 ) /*0x850ac4*/
              goto LABEL_1546; /*0x850ac4*/
            p_teleporter_R = &v262->teleporter_mid; /*0x850ac8*/
          }
          else
          {
            if ( v256 ) /*0x8509fc*/
            {
LABEL_192:
              v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x850af0*/
              if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x850af4*/
              {
                j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x850afc*/
                v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x850b00*/
              }
              v264 = **(_QWORD **)(v167._dateData + 184); /*0x850b08*/
              if ( !v264 ) /*0x850b0c*/
                goto LABEL_1546; /*0x850b0c*/
              v167._dateData = *(_QWORD *)(v264 + 384); /*0x850b10*/
              if ( !v167._dateData ) /*0x850b14*/
                goto LABEL_1546; /*0x850b14*/
              v167._dateData = (uint64_t)System::Collections::Generic::List<System::Object>::get_Item( /*0x850b20*/
                                           (List_1_System_Object_ *)v167._dateData,
                                           v256,
                                           MethodInfo::System::Collections::Generic::List<CraftingSlot>::get_Item);
              if ( !v167._dateData ) /*0x850b24*/
                goto LABEL_1546; /*0x850b24*/
              v167._dateData = (uint64_t)UnityEngine::Component::get_gameObject((Component *)v167._dateData, nullptr); /*0x850b2c*/
              if ( !v167._dateData ) /*0x850b30*/
                goto LABEL_1546; /*0x850b30*/
              UnityEngine::GameObject::SetActive((GameObject *)v167._dateData, 1, nullptr); /*0x850b3c*/
              v167._dateData = (uint64_t)TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x850b48*/
              if ( !v167._dateData ) /*0x850b4c*/
                goto LABEL_1546; /*0x850b4c*/
              CustomTeleporterControl::DrawOnlineTeleporterSlot( /*0x850b5c*/
                (CustomTeleporterControl *)v167._dateData,
                v256,
                v257,
                nullptr);
LABEL_200:
              if ( ++v256 == 3 ) /*0x850b68*/
                goto LABEL_1159; /*0x850b68*/
              continue; /*0x850b68*/
            }
            v258 = TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x850a08*/
            if ( !v258 ) /*0x850a0c*/
              goto LABEL_1546; /*0x850a0c*/
            p_teleporter_R = &v258->teleporter_L; /*0x850a10*/
          }
          *p_teleporter_R = v257; /*0x850ae8*/
          sub_73C72C(p_teleporter_R); /*0x850aec*/
          goto LABEL_192; /*0x850aec*/
        }
        break;
      }
      v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x850a18*/
      if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x850a1c*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x850a24*/
        v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x850a28*/
      }
      v260 = **(_QWORD **)(v167._dateData + 184); /*0x850a30*/
      if ( !v260 ) /*0x850a34*/
        goto LABEL_1546; /*0x850a34*/
      v167._dateData = *(_QWORD *)(v260 + 384); /*0x850a38*/
      if ( !v167._dateData ) /*0x850a3c*/
        goto LABEL_1546; /*0x850a3c*/
      v167._dateData = (uint64_t)System::Collections::Generic::List<System::Object>::get_Item( /*0x850a48*/
                                   (List_1_System_Object_ *)v167._dateData,
                                   v256,
                                   MethodInfo::System::Collections::Generic::List<CraftingSlot>::get_Item);
      if ( !v167._dateData ) /*0x850a4c*/
        goto LABEL_1546; /*0x850a4c*/
      v167._dateData = (uint64_t)UnityEngine::Component::get_gameObject((Component *)v167._dateData, nullptr); /*0x850a54*/
      if ( !v167._dateData ) /*0x850a58*/
        goto LABEL_1546; /*0x850a58*/
      UnityEngine::GameObject::SetActive((GameObject *)v167._dateData, 0, nullptr); /*0x850a64*/
      if ( v256 ) /*0x850a68*/
      {
        if ( v256 != 1 ) /*0x850a70*/
        {
          if ( v256 != 2 ) /*0x850a78*/
            goto LABEL_200; /*0x850a78*/
          v167._dateData = (uint64_t)TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x85689c*/
          if ( !v167._dateData ) /*0x8568a0*/
            goto LABEL_1546; /*0x8568a0*/
          *(_QWORD *)(v167._dateData + 56) = 0; /*0x8568a4*/
          v167._dateData = sub_73C72C(v167._dateData + 56); /*0x8568ac*/
LABEL_1159:
          if ( v254 == 1 ) /*0x8568b8*/
          {
            v863 = TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x8568c4*/
            if ( !v863 ) /*0x8568c8*/
              goto LABEL_1546; /*0x8568c8*/
            v863->search_page = v253; /*0x8568cc*/
            v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x8568d0*/
          }
          else
          {
            v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x8568d8*/
            if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x8568dc*/
            {
              j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x8568e4*/
              v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x8568e8*/
            }
            v864 = **(_QWORD **)(v167._dateData + 184); /*0x8568f0*/
            if ( !v864 ) /*0x8568f4*/
              goto LABEL_1546; /*0x8568f4*/
            *(_DWORD *)(v864 + 824) = v253; /*0x8568f8*/
          }
          if ( !*(_DWORD *)(v167._dateData + 224) ) /*0x8568fc*/
          {
            j_il2cpp_runtime_class_init_0(v167._dateData); /*0x856904*/
            v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x856908*/
          }
          v865 = **(_QWORD **)(v167._dateData + 184); /*0x856910*/
          if ( !v865 ) /*0x856914*/
            goto LABEL_1546; /*0x856914*/
          v167._dateData = *(_QWORD *)(v865 + 416); /*0x856918*/
          if ( !v167._dateData ) /*0x85691c*/
            goto LABEL_1546; /*0x85691c*/
          UnityEngine::GameObject::SetActive((GameObject *)v167._dateData, v253 != 0, nullptr); /*0x85692c*/
          v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x856930*/
          if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x856934*/
          {
            j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x85693c*/
            v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x856940*/
          }
          v866 = **(_QWORD **)(v167._dateData + 184); /*0x856948*/
          if ( !v866 ) /*0x85694c*/
            goto LABEL_1546; /*0x85694c*/
          v167._dateData = *(_QWORD *)(v866 + 424); /*0x856950*/
          if ( !v167._dateData ) /*0x856954*/
            goto LABEL_1546; /*0x856954*/
          UnityEngine::GameObject::SetActive((GameObject *)v167._dateData, v255 == 1, nullptr); /*0x856968*/
          v867 = TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x856974*/
          if ( !v867 ) /*0x856978*/
            goto LABEL_1546; /*0x856978*/
          if ( !v867->in_search_screen || v867->teleporter_L || v867->teleporter_mid || v867->teleporter_R || v253 ) /*0x85699c*/
            return; /*0x85699c*/
          v167._dateData = (uint64_t)TypeInfo::PopupControl->static_fields->Instance; /*0x8569a8*/
          if ( !v167._dateData ) /*0x8569ac*/
            goto LABEL_1546; /*0x8569ac*/
          v566 = &StringLiteral__0_results_found; /*0x8569b4*/
LABEL_605:
          v567 = (String *)*v566; /*0x853554*/
LABEL_1490:
          PopupControl::ShowMessage((PopupControl *)v167._dateData, v567, PopupControl_context__Enum_message, nullptr); /*0x857fc8*/
          return; /*0x857fd0*/
        }
        v167._dateData = (uint64_t)TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x850a88*/
        if ( !v167._dateData ) /*0x850a8c*/
          goto LABEL_1546; /*0x850a8c*/
        *(_QWORD *)(v167._dateData + 48) = 0; /*0x850a90*/
        v261 = v167._dateData + 48; /*0x850a90*/
      }
      else
      {
        v167._dateData = (uint64_t)TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x850aa0*/
        if ( !v167._dateData ) /*0x850aa4*/
          goto LABEL_1546; /*0x850aa4*/
        *(_QWORD *)(v167._dateData + 40) = 0; /*0x850aa8*/
        v261 = v167._dateData + 40; /*0x850aa8*/
      }
      v167._dateData = sub_73C72C(v261); /*0x850ab0*/
      goto LABEL_200; /*0x850ab4*/
    case 47:
      zonea = Packet::GetString(incoming, nullptr);// // case 0x30: TELE_SCREENSHOT /*0x850660*/
      v238 = Packet::GetShort(incoming, nullptr); /*0x850670*/
      v239 = Packet::GetShort(incoming, nullptr); /*0x850680*/
      v240 = Packet::GetShort(incoming, nullptr); /*0x850690*/
      v241 = Packet::GetShort(incoming, nullptr); /*0x8506a0*/
      v242 = Packet::GetLong(incoming, nullptr); /*0x8506b8*/
      v243 = (Byte__Array *)sub_73C7E4(TypeInfo::System::Byte, (unsigned int)v242); /*0x8506d0*/
      if ( v242 < 1 ) /*0x8506d4*/
        goto LABEL_150; /*0x8506d4*/
      for ( k = 0; k != v242; v243->vector[k++] = v167._dateData ) /*0x8506d8*/
      {
        v167._dateData = Packet::GetByte(incoming, nullptr); /*0x8506ec*/
        if ( !v243 ) /*0x8506f0*/
          goto LABEL_1546; /*0x8506f0*/
        if ( k >= (unsigned int)v243->max_length.size ) /*0x8506fc*/
          goto LABEL_1547; /*0x8506fc*/
      }
LABEL_150:
      v167._dateData = (uint64_t)TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x850710*/
      if ( !v167._dateData ) /*0x85071c*/
        goto LABEL_1546; /*0x85071c*/
      v1013[1].m_value = CustomTeleporterControl::GetCustomTeleId( /*0x85073c*/
                           (CustomTeleporterControl *)v167._dateData,
                           zonea,
                           v238,
                           v239,
                           v240,
                           v241,
                           nullptr);
      if ( v1013[1].m_value != -1 ) /*0x85074c*/
      {
        persistentDataPath = TypeInfo::Startup->static_fields->persistentDataPath; /*0x850764*/
        if ( !TypeInfo::System::IO::Path->_1.cctor_finished_or_no_cctor ) /*0x850760*/
          j_il2cpp_runtime_class_init_0(TypeInfo::System::IO::Path); /*0x85076c*/
        if ( !TypeInfo::System::Char->_1.cctor_finished_or_no_cctor ) /*0x850780*/
          j_il2cpp_runtime_class_init_0(TypeInfo::System::Char); /*0x85078c*/
        v167._dateData = (uint64_t)System::Char::ToString( /*0x8507a0*/
                                     (Char *)&TypeInfo::System::IO::Path->static_fields->DirectorySeparatorChar,
                                     nullptr);
        if ( TypeInfo::PlayerData->static_fields->Instance ) /*0x8507b4*/
        {
          v246 = (String *)v167._dateData; /*0x8507bc*/
          CurrentSlotFolder = PlayerData::GetCurrentSlotFolder(TypeInfo::PlayerData->static_fields->Instance, nullptr); /*0x8507c8*/
          v248 = System::String::Concat(persistentDataPath, v246, CurrentSlotFolder, nullptr); /*0x8507e0*/
          v249 = System::Int32::ToString(&v1013[1], nullptr); /*0x8507ec*/
          v250 = System::String::Concat((String *)"tele_graphic_", v249, nullptr); /*0x850800*/
          v251 = System::IO::Path::Combine(v248, v250, nullptr); /*0x850810*/
          System::IO::File::WriteAllBytes(v251, v243, nullptr); /*0x85081c*/
          return; /*0x850820*/
        }
        goto LABEL_1546; /*0x8507b8*/
      }
      return; /*0x85074c*/
    case 48:
      v349 = Packet::GetString(incoming, nullptr);// // case 0x31: REQ_TELE_SCREENSHOT /*0x85175c*/
      v350 = Packet::GetString(incoming, nullptr); /*0x85176c*/
      v351 = Packet::GetShort(incoming, nullptr); /*0x85177c*/
      v352 = Packet::GetShort(incoming, nullptr); /*0x85178c*/
      v353 = Packet::GetShort(incoming, nullptr); /*0x85179c*/
      v167._dateData = Packet::GetShort(incoming, nullptr); /*0x8517a8*/
      if ( !TypeInfo::CustomTeleporterControl->static_fields->Instance ) /*0x8517c0*/
        goto LABEL_1546; /*0x8517c0*/
      v354 = SLOWORD(v167._dateData); /*0x8517c4*/
      v355 = v352; /*0x8517cc*/
      v356 = v351; /*0x8517d0*/
      LODWORD(v1014) = CustomTeleporterControl::GetCustomTeleId( /*0x8517f4*/
                         TypeInfo::CustomTeleporterControl->static_fields->Instance,
                         v350,
                         v351,
                         v355,
                         v353,
                         SLOWORD(v167._dateData),
                         nullptr);
      if ( (_DWORD)v1014 == -1 ) /*0x851804*/
        return; /*0x851804*/
      v357 = TypeInfo::Startup->static_fields->persistentDataPath; /*0x851818*/
      if ( !TypeInfo::System::IO::Path->_1.cctor_finished_or_no_cctor ) /*0x851814*/
        j_il2cpp_runtime_class_init_0(TypeInfo::System::IO::Path); /*0x851820*/
      if ( !TypeInfo::System::Char->_1.cctor_finished_or_no_cctor ) /*0x851828*/
        j_il2cpp_runtime_class_init_0(TypeInfo::System::Char); /*0x851830*/
      v167._dateData = (uint64_t)System::Char::ToString( /*0x851844*/
                                   (Char *)&TypeInfo::System::IO::Path->static_fields->DirectorySeparatorChar,
                                   nullptr);
      if ( !TypeInfo::PlayerData->static_fields->Instance ) /*0x851854*/
        goto LABEL_1546; /*0x851854*/
      v358 = (String *)v167._dateData; /*0x851858*/
      v359 = PlayerData::GetCurrentSlotFolder(TypeInfo::PlayerData->static_fields->Instance, nullptr); /*0x851864*/
      v360 = System::String::Concat(v357, v358, v359, nullptr); /*0x85187c*/
      v361 = System::Int32::ToString((Int32 *)&v1014, nullptr); /*0x851888*/
      v362 = System::String::Concat((String *)"tele_graphic_", v361, nullptr); /*0x8518a4*/
      v363 = System::IO::Path::Combine(v360, v362, nullptr); /*0x8518b4*/
      if ( !System::IO::File::Exists(v363, nullptr) ) /*0x8518c0*/
        return; /*0x8518c0*/
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x8518c8*/
      if ( !v167._dateData ) /*0x8518cc*/
        goto LABEL_1546; /*0x8518cc*/
      v364 = (Packet *)v167._dateData; /*0x8518d4*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x8518d8*/
      Packet::PutByte(v364, 0x32u, nullptr); /*0x8518e8*/
      Packet::PutString(v364, v349, nullptr); /*0x8518f8*/
      Packet::PutString(v364, v350, nullptr); /*0x851908*/
      Packet::PutShort(v364, (float)v356, nullptr); /*0x851918*/
      Packet::PutShort(v364, (float)v355, nullptr); /*0x851928*/
      Packet::PutShort(v364, (float)v353, nullptr); /*0x851938*/
      Packet::PutShort(v364, (float)v354, nullptr); /*0x851948*/
      v365 = System::Int32::ToString((Int32 *)&v1014, nullptr); /*0x851954*/
      v366 = System::String::Concat((String *)"tele_graphic_", v365, nullptr); /*0x85197c*/
      if ( !TypeInfo::System::IO::Path->_1.cctor_finished_or_no_cctor ) /*0x851984*/
        j_il2cpp_runtime_class_init_0(TypeInfo::System::IO::Path); /*0x851990*/
      v367 = System::IO::Path::Combine(v360, v366, nullptr); /*0x8519a0*/
      v167._dateData = (uint64_t)System::IO::File::ReadAllBytes(v367, nullptr); /*0x8519a8*/
      if ( !v167._dateData ) /*0x8519ac*/
        goto LABEL_1546; /*0x8519ac*/
      v368 = v167._dateData; /*0x8519b4*/
      Packet::PutLong(v364, *(_DWORD *)(v167._dateData + 24), nullptr); /*0x8519c0*/
      v370 = *(_QWORD *)(v368 + 24); /*0x8519c4*/
      if ( (int)v370 < 1 ) /*0x8519cc*/
        goto LABEL_317; /*0x8519cc*/
      v371 = 0; /*0x8519d0*/
      do /*0x851a00*/
      {
        if ( v371 >= (unsigned int)v370 ) /*0x8519e0*/
          goto LABEL_1547; /*0x8519e0*/
        Packet::PutByte(v364, *(_BYTE *)(v368 + 32 + v371), nullptr); /*0x8519f0*/
        LODWORD(v370) = *(_DWORD *)(v368 + 24); /*0x8519f4*/
        ++v371; /*0x8519f8*/
      }
      while ( (__int64)v371 < (int)v370 ); /*0x851a00*/
LABEL_317:
      v167._dateData = (uint64_t)GameServerReceiver::get_connection((GameServerReceiver *)v167._dateData, v369); /*0x851a04*/
      if ( !v167._dateData ) /*0x851a08*/
        goto LABEL_1546; /*0x851a08*/
      v227 = Connection_priority__Enum_LOW; /*0x851a0c*/
      v228 = v364; /*0x851a10*/
      goto LABEL_1396; /*0x851a14*/
    case 49:
      v461 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x32: UNKNOWN_0x32 /*0x852764*/
      v462 = Packet::GetLong(incoming, nullptr); /*0x85277c*/
      v463 = (Byte__Array *)sub_73C7E4(TypeInfo::System::Byte, (unsigned int)v462); /*0x852794*/
      if ( v462 < 1 ) /*0x852798*/
        goto LABEL_463; /*0x852798*/
      for ( m = 0; m != v462; v463->vector[m++] = v167._dateData ) /*0x85279c*/
      {
        v167._dateData = Packet::GetByte(incoming, nullptr); /*0x8527b0*/
        if ( !v463 ) /*0x8527b4*/
          goto LABEL_1546; /*0x8527b4*/
        if ( m >= (unsigned int)v463->max_length.size ) /*0x8527c0*/
          goto LABEL_1547; /*0x8527c0*/
      }
LABEL_463:
      v167._dateData = sub_73C88C(TypeInfo::UnityEngine::Texture2D); /*0x8527d4*/
      if ( !v167._dateData ) /*0x8527e4*/
        goto LABEL_1546; /*0x8527e4*/
      v465 = (Texture2D *)v167._dateData; /*0x8527f4*/
      UnityEngine::Texture2D::Texture2D((Texture2D *)v167._dateData, 150, 150, nullptr); /*0x8527f8*/
      UnityEngine::ImageConversion::LoadImage(v465, v463, nullptr); /*0x852808*/
      v466 = ((__int64 (__fastcall *)(Texture2D *, const MethodInfo *))v465->klass->vtable.get_width.methodPtr)( /*0x852820*/
               v465,
               v465->klass->vtable.get_width.method);
      v467 = ((__int64 (__fastcall *)(Texture2D *, const MethodInfo *))v465->klass->vtable.get_height.methodPtr)( /*0x85282c*/
               v465,
               v465->klass->vtable.get_height.method);
      v1003._dictionary = nullptr; /*0x852848*/
      *(_QWORD *)&v1003._version = 0; /*0x852848*/
      UnityEngine::Rect::Rect((Rect *)&v1003, 0.0, 0.0, (float)v466, (float)v467, nullptr); /*0x85284c*/
      v1035.x = 0.5; /*0x852858*/
      v1035.y = 0.5; /*0x852860*/
      v167._dateData = (uint64_t)UnityEngine::Sprite::Create(v465, *(Rect *)&v1003._dictionary, v1035, nullptr); /*0x852868*/
      if ( !zone[1].monitor ) /*0x852870*/
        goto LABEL_1546; /*0x852870*/
      v468 = (Object *)v167._dateData; /*0x852880*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x852890*/
                         (Dictionary_2_System_Object_System_Object_ *)zone[1].monitor,
                         v461,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::ContainsKey);
      if ( !zone[1].monitor ) /*0x852894*/
        goto LABEL_1546; /*0x852894*/
      if ( (v167._dateData & 1) != 0 ) /*0x85289c*/
        System::Collections::Generic::Dictionary<System::Object,System::Object>::set_Item( /*0x8528b8*/
          (Dictionary_2_System_Object_System_Object_ *)zone[1].monitor,
          v461,
          v468,
          MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::set_Item);
      else
        System::Collections::Generic::Dictionary<System::Object,System::Object>::Add( /*0x8565f0*/
          (Dictionary_2_System_Object_System_Object_ *)zone[1].monitor,
          v461,
          v468,
          MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::Add);
      v849 = TypeInfo::WindowControl->static_fields->Instance; /*0x8565fc*/
      if ( !v849 ) /*0x856600*/
        goto LABEL_1546; /*0x856600*/
      if ( v849->curr_miniwindow != 3 ) /*0x85660c*/
        return; /*0x85660c*/
      v850 = TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x856618*/
      if ( !v850 ) /*0x85661c*/
        goto LABEL_1546; /*0x85661c*/
      teleporter_L = v850->teleporter_L; /*0x856620*/
      v852 = zone; /*0x856624*/
      if ( !teleporter_L ) /*0x856628*/
        goto LABEL_1546; /*0x856628*/
      v167._dateData = System::String::op_Equality(teleporter_L->tele_str, (String *)v461, nullptr); /*0x856648*/
      if ( (v167._dateData & 1) != 0 ) /*0x85664c*/
      {
        v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x856650*/
        if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x856654*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x85665c*/
          v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x856660*/
        }
        v853 = **(_QWORD **)(v167._dateData + 184); /*0x856668*/
        if ( !v853 ) /*0x85666c*/
          goto LABEL_1546; /*0x85666c*/
        v167._dateData = *(_QWORD *)(v853 + 384); /*0x856670*/
        if ( !v167._dateData ) /*0x856674*/
          goto LABEL_1546; /*0x856674*/
        v167._dateData = (uint64_t)System::Collections::Generic::List<System::Object>::get_Item( /*0x856680*/
                                     (List_1_System_Object_ *)v167._dateData,
                                     0,
                                     MethodInfo::System::Collections::Generic::List<CraftingSlot>::get_Item);
        if ( !v167._dateData ) /*0x856684*/
          goto LABEL_1546; /*0x856684*/
        monitor = (Dictionary_2_System_Object_System_Object_ *)zone[1].monitor; /*0x856688*/
        if ( !monitor ) /*0x85668c*/
          goto LABEL_1546; /*0x85668c*/
      }
      else
      {
        v902 = TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x857158*/
        if ( !v902 ) /*0x85715c*/
          goto LABEL_1546; /*0x85715c*/
        teleporter_mid = v902->teleporter_mid; /*0x857160*/
        if ( !teleporter_mid ) /*0x857164*/
          goto LABEL_1546; /*0x857164*/
        v167._dateData = System::String::op_Equality(teleporter_mid->tele_str, (String *)v461, nullptr); /*0x857174*/
        if ( (v167._dateData & 1) != 0 ) /*0x857178*/
        {
          v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x85717c*/
          if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x857180*/
          {
            j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x857188*/
            v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x85718c*/
          }
          v904 = **(_QWORD **)(v167._dateData + 184); /*0x857194*/
          if ( !v904 ) /*0x857198*/
            goto LABEL_1546; /*0x857198*/
          v167._dateData = *(_QWORD *)(v904 + 384); /*0x85719c*/
          if ( !v167._dateData ) /*0x8571a0*/
            goto LABEL_1546; /*0x8571a0*/
          v905 = MethodInfo::System::Collections::Generic::List<CraftingSlot>::get_Item; /*0x8571a4*/
          v906 = 1; /*0x8571a8*/
        }
        else
        {
          v965 = TypeInfo::CustomTeleporterControl->static_fields->Instance; /*0x857e9c*/
          if ( !v965 ) /*0x857ea0*/
            goto LABEL_1546; /*0x857ea0*/
          teleporter_R = v965->teleporter_R; /*0x857ea4*/
          if ( !teleporter_R ) /*0x857ea8*/
            goto LABEL_1546; /*0x857ea8*/
          if ( !System::String::op_Equality(teleporter_R->tele_str, (String *)v461, nullptr) ) /*0x857ebc*/
            return; /*0x857ebc*/
          v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x857ec4*/
          if ( !TypeInfo::inventory_ctr->_1.cctor_finished_or_no_cctor ) /*0x857ec8*/
          {
            j_il2cpp_runtime_class_init_0(TypeInfo::inventory_ctr); /*0x857ed4*/
            v167._dateData = (uint64_t)TypeInfo::inventory_ctr; /*0x857ed8*/
          }
          v852 = zone; /*0x857ee0*/
          v967 = **(_QWORD **)(v167._dateData + 184); /*0x857ee4*/
          if ( !v967 ) /*0x857ee8*/
            goto LABEL_1546; /*0x857ee8*/
          v167._dateData = *(_QWORD *)(v967 + 384); /*0x857eec*/
          if ( !v167._dateData ) /*0x857ef0*/
            goto LABEL_1546; /*0x857ef0*/
          v905 = MethodInfo::System::Collections::Generic::List<CraftingSlot>::get_Item; /*0x857ef4*/
          v906 = 2; /*0x857ef8*/
        }
        v167._dateData = (uint64_t)System::Collections::Generic::List<System::Object>::get_Item( /*0x857efc*/
                                     (List_1_System_Object_ *)v167._dateData,
                                     v906,
                                     v905);
        if ( !v167._dateData ) /*0x857f00*/
          goto LABEL_1546; /*0x857f00*/
        monitor = (Dictionary_2_System_Object_System_Object_ *)v852[1].monitor; /*0x857f04*/
        if ( !monitor ) /*0x857f08*/
          goto LABEL_1546; /*0x857f08*/
      }
      v968 = *(Image **)(v167._dateData + 32); /*0x857f10*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x857f1c*/
                                   monitor,
                                   v461,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::Sprite>::get_Item);
      if ( !v968 ) /*0x857f20*/
        goto LABEL_1546; /*0x857f20*/
      UnityEngine::UI::Image::set_sprite(v968, (Sprite *)v167._dateData, nullptr); /*0x857f30*/
      return; /*0x857f34*/
    case 50:
      v632 = Packet::GetString(incoming, nullptr);// // case 0x33: EDIT_TELEPORTER /*0x853e4c*/
      v633 = Packet::GetString(incoming, nullptr); /*0x853e5c*/
      v634 = Packet::GetString(incoming, nullptr); /*0x853e6c*/
      v635 = Packet::GetShort(incoming, nullptr); /*0x853e7c*/
      v636 = Packet::GetShort(incoming, nullptr); /*0x853e8c*/
      v637 = Packet::GetShort(incoming, nullptr); /*0x853e9c*/
      v167._dateData = Packet::GetShort(incoming, nullptr); /*0x853ea8*/
      if ( !TypeInfo::CustomTeleporterControl->static_fields->Instance ) /*0x853ec0*/
        goto LABEL_1546; /*0x853ec0*/
      HIDWORD(v1014) = CustomTeleporterControl::GetCustomTeleId( /*0x853ee8*/
                         TypeInfo::CustomTeleporterControl->static_fields->Instance,
                         v634,
                         v635,
                         v636,
                         v637,
                         SLOWORD(v167._dateData),
                         nullptr);
      if ( HIDWORD(v1014) == -1 ) /*0x853eec*/
        return; /*0x853eec*/
      v638 = TypeInfo::PlayerData->static_fields->Instance; /*0x853f10*/
      v639 = System::Int32::ToString((Int32 *)&v1014 + 1, nullptr); /*0x853f1c*/
      v167._dateData = (uint64_t)System::String::Concat((String *)"teleporter_", v639, (String *)"_name", nullptr); /*0x853f34*/
      if ( !v638 ) /*0x853f38*/
        goto LABEL_1546; /*0x853f38*/
      PlayerData::SetSlotString( /*0x853f68*/
        v638,
        (String *)v167._dateData,
        v632,
        PlayerData_filename_t__Enum_teleporters,
        (String *)"default",
        -1,
        nullptr);
      v640 = TypeInfo::PlayerData->static_fields->Instance; /*0x853f7c*/
      v641 = System::Int32::ToString((Int32 *)&v1014 + 1, nullptr); /*0x853f80*/
      v167._dateData = (uint64_t)System::String::Concat((String *)"teleporter_", v641, (String *)"_desc", nullptr); /*0x853f98*/
      if ( !v640 ) /*0x853f9c*/
        goto LABEL_1546; /*0x853f9c*/
      PlayerData::SetSlotString( /*0x853fbc*/
        v640,
        (String *)v167._dateData,
        v633,
        PlayerData_filename_t__Enum_teleporters,
        (String *)"default",
        -1,
        nullptr);
      return; /*0x853fc0*/
    case 52:
      v199 = Packet::GetString(incoming, nullptr);// // case 0x35: MINIGAME_CHALLENGE /*0x84fff0*/
      v200 = Packet::GetByte(incoming, nullptr); /*0x84fffc*/
      if ( v200 > 1u ) /*0x850008*/
      {
        if ( v200 != 2 ) /*0x855d5c*/
          return; /*0x855d5c*/
        v803 = (Object_1 *)TypeInfo::TradingTableControl->static_fields->Instance; /*0x855d7c*/
        if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x855d74*/
          j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x855d84*/
        v167._dateData = UnityEngine::Object::op_Inequality(v803, nullptr, nullptr); /*0x855d94*/
        if ( (v167._dateData & 1) == 0 ) /*0x855d98*/
          return; /*0x855d98*/
        v804 = TypeInfo::TradingTableControl->static_fields->Instance; /*0x855da4*/
        if ( !v804 ) /*0x855da8*/
          goto LABEL_1546; /*0x855da8*/
        other_player_has_joined = v804->other_player_has_joined; /*0x855db8*/
        if ( !byte_27E6C85 ) /*0x855dc0*/
        {
          sub_73C778(&TypeInfo::GameServerSender, v168); /*0x855dcc*/
          byte_27E6C85 = 1; /*0x855dd4*/
        }
        v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x855de0*/
        if ( !v167._dateData ) /*0x855de4*/
          goto LABEL_1546; /*0x855de4*/
        if ( other_player_has_joined ) /*0x855de8*/
          v206 = 2; /*0x855dec*/
        else
          v206 = 3; /*0x85826c*/
        v983 = 2; /*0x858270*/
        v984 = v199; /*0x858274*/
      }
      else
      {
        v201 = v200; /*0x850010*/
        v202 = (Object_1 *)TypeInfo::MinigameMenu->static_fields->Instance; /*0x850020*/
        if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x85001c*/
          j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x850028*/
        v167._dateData = UnityEngine::Object::op_Inequality(v202, nullptr, nullptr); /*0x850038*/
        if ( (v167._dateData & 1) == 0 ) /*0x85003c*/
          return; /*0x85003c*/
        v204 = TypeInfo::MinigameMenu->static_fields->Instance; /*0x850048*/
        if ( !v204 ) /*0x85004c*/
          goto LABEL_1546; /*0x85004c*/
        curr_menu = v204->curr_menu; /*0x850050*/
        if ( curr_menu == 6 ) /*0x850064*/
        {
          if ( !byte_27E6C85 ) /*0x858010*/
          {
            sub_73C778(&TypeInfo::GameServerSender, v168); /*0x85801c*/
            byte_27E6C85 = 1; /*0x858024*/
          }
          v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x858030*/
          if ( !v167._dateData ) /*0x858034*/
            goto LABEL_1546; /*0x858034*/
          v206 = 2; /*0x858038*/
        }
        else if ( curr_menu == 5 ) /*0x85006c*/
        {
          if ( !byte_27E6C85 ) /*0x850074*/
          {
            sub_73C778(&TypeInfo::GameServerSender, v168); /*0x850080*/
            byte_27E6C85 = 1; /*0x850088*/
          }
          v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x850094*/
          if ( !v167._dateData ) /*0x850098*/
            goto LABEL_1546; /*0x850098*/
          v206 = 1; /*0x85009c*/
        }
        else
        {
          if ( !byte_27E6C85 ) /*0x858044*/
          {
            sub_73C778(&TypeInfo::GameServerSender, v168); /*0x858050*/
            byte_27E6C85 = 1; /*0x858058*/
          }
          v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x858064*/
          if ( !v167._dateData ) /*0x858068*/
            goto LABEL_1546; /*0x858068*/
          if ( curr_menu == 3 ) /*0x858070*/
            v206 = 3; /*0x858074*/
          else
            v206 = 0; /*0x85827c*/
        }
        v984 = v199; /*0x858280*/
        v983 = v201; /*0x858284*/
      }
      GameServerSender::SendMinigameResponse((GameServerSender *)v167._dateData, v206, v984, v983, v203); /*0x858288*/
      return; /*0x85828c*/
    case 53:
      v167._dateData = sub_73C88C(TypeInfo::GameServerReceiver::__c__DisplayClass18_0);// // case 0x36: MINIGAME_RESPONSE /*0x850c2c*/
      if ( !v167._dateData ) /*0x850c30*/
        goto LABEL_1546; /*0x850c30*/
      v270 = v167._dateData; /*0x850c60*/
      System::Object::Object((Object *)v167._dateData, nullptr); /*0x850c64*/
      v271 = Packet::GetByte(incoming, nullptr); /*0x850c78*/
      *(_QWORD *)(v270 + 16) = Packet::GetString(incoming, nullptr); /*0x850c8c*/
      v272 = (String **)(v270 + 16); /*0x850c8c*/
      sub_73C72C(v270 + 16); /*0x850c98*/
      v273 = Packet::GetByte(incoming, nullptr); /*0x850ca4*/
      *(_BYTE *)(v270 + 24) = v273; /*0x850cb0*/
      if ( v273 > 1u ) /*0x850cb4*/
      {
        if ( v273 != 2 ) /*0x855df8*/
          return; /*0x855df8*/
        if ( v271 != 3 ) /*0x855e08*/
        {
          if ( v271 != 2 ) /*0x855e10*/
            return; /*0x855e10*/
          v274 = TypeInfo::PopupControl->static_fields; /*0x855e1c*/
          v275 = &StringLiteral___color__is_currently_trading_wi; /*0x855e20*/
LABEL_1487:
          v503 = *v272; /*0x857fa0*/
          v505 = "<color=#43de4f>"; /*0x857fa4*/
          v504 = v274->Instance; /*0x857fa8*/
          v506 = (char *)*v275; /*0x857fac*/
LABEL_1488:
          v167._dateData = (uint64_t)System::String::Concat((String *)v505, v503, (String *)v506, nullptr); /*0x857fb4*/
          if ( !v504 ) /*0x857fb8*/
            goto LABEL_1546; /*0x857fb8*/
          v567 = (String *)v167._dateData; /*0x857fbc*/
          v167._dateData = (uint64_t)v504; /*0x857fc4*/
          goto LABEL_1490; /*0x857fc4*/
        }
        v969 = TypeInfo::PopupControl->static_fields->Instance; /*0x858088*/
        v167._dateData = sub_73C88C(TypeInfo::System::Action); /*0x85808c*/
        if ( !v167._dateData ) /*0x858090*/
          goto LABEL_1546; /*0x858090*/
        v970 = v167._dateData; /*0x8580a4*/
        System::Action::Action( /*0x8580ac*/
          (Action *)v167._dateData,
          (Object *)v270,
          MethodInfo::GameServerReceiver::__c__DisplayClass18_0::_OnReceive_b__1,
          nullptr);
        if ( !v969 ) /*0x8580b0*/
          goto LABEL_1546; /*0x8580b0*/
        v971 = (String **)&StringLiteral_Trade_with__color__43de4f_; /*0x8580b8*/
      }
      else
      {
        switch ( v271 ) /*0x850ce0*/
        {
          case 0u: /*0x850ce0*/
            v274 = TypeInfo::PopupControl->static_fields; /*0x850cec*/
            v275 = &StringLiteral___color__is_setting_up_a_game_u000AP; /*0x850cf0*/
            goto LABEL_1487; /*0x850cf4*/
          case 1u: /*0x850ce0*/
            v274 = TypeInfo::PopupControl->static_fields; /*0x857f98*/
            v275 = &StringLiteral___color__is_currently_playing_ag; /*0x857f9c*/
            goto LABEL_1487; /*0x857f9c*/
          case 2u: /*0x850ce0*/
            v274 = TypeInfo::PopupControl->static_fields; /*0x857f40*/
            v275 = &StringLiteral___color__is_currently_playing_ag_0; /*0x857f44*/
            goto LABEL_1487; /*0x857f48*/
          case 3u: /*0x850ce0*/
            v969 = TypeInfo::PopupControl->static_fields->Instance; /*0x857f58*/
            v167._dateData = sub_73C88C(TypeInfo::System::Action); /*0x857f5c*/
            if ( !v167._dateData ) /*0x857f60*/
              goto LABEL_1546; /*0x857f60*/
            v970 = v167._dateData; /*0x857f74*/
            System::Action::Action( /*0x857f7c*/
              (Action *)v167._dateData,
              (Object *)v270,
              MethodInfo::GameServerReceiver::__c__DisplayClass18_0::_OnReceive_b__0,
              nullptr);
            if ( !v969 ) /*0x857f80*/
              goto LABEL_1546; /*0x857f80*/
            v971 = (String **)&StringLiteral_Play_against__color__43de4f_; /*0x857f88*/
            break; /*0x857f8c*/
          default:
            return;
        }
      }
      v969->on_yes_pressed = (Action *)v970; /*0x8580bc*/
      sub_73C72C(&v969->on_yes_pressed); /*0x8580c8*/
      v974 = TypeInfo::PopupControl->static_fields->Instance; /*0x8580e4*/
      v167._dateData = (uint64_t)System::String::Concat(*v971, *v272, (String *)"?</color>", nullptr); /*0x8580e8*/
      if ( !v974 ) /*0x8580ec*/
        goto LABEL_1546; /*0x8580ec*/
      PopupControl::ShowYesNo( /*0x858108*/
        v974,
        (String *)v167._dateData,
        (String *)"Yes",
        (String *)"No",
        PopupControl_context__Enum_yesno_ACTION,
        nullptr);
      return; /*0x85810c*/
    case 54:
      v499 = Packet::GetString(incoming, nullptr);// // case 0x37: BEGIN_MINIGAME /*0x852d48*/
      v500 = Packet::GetByte(incoming, nullptr); /*0x852d5c*/
      v501 = Packet::GetByte(incoming, nullptr); /*0x852d68*/
      v502 = v501; /*0x852da8*/
      switch ( v500 ) /*0x852dac*/
      {
        case 0: /*0x852dac*/
          v503 = v499; /*0x852dbc*/
          v504 = TypeInfo::PopupControl->static_fields->Instance; /*0x852dcc*/
          v505 = "Could not start game\n<color=#43de4f>"; /*0x852dd0*/
          v506 = "</color> left!"; /*0x852dd4*/
          goto LABEL_1488; /*0x852dd8*/
        case 1: /*0x852dac*/
          v503 = v499; /*0x857408*/
          v504 = TypeInfo::PopupControl->static_fields->Instance; /*0x85741c*/
          v505 = "Could not join\n<color=#43de4f>"; /*0x857420*/
          v506 = "</color> already started a game!"; /*0x857424*/
          goto LABEL_1488; /*0x857428*/
        case 2: /*0x852dac*/
          if ( v501 ) /*0x8571b4*/
            return; /*0x8571b4*/
          v907 = (Int32__Array *)sub_73C7E4(TypeInfo::System::Int32, 14); /*0x8571c8*/
          for ( n = 0; n != 14; ++n ) /*0x8571cc*/
          {
            v167._dateData = Packet::GetByte(incoming, nullptr); /*0x8571dc*/
            if ( !v907 ) /*0x8571e0*/
              goto LABEL_1546; /*0x8571e0*/
            if ( n >= (unsigned int)v907->max_length.size ) /*0x8571ec*/
              goto LABEL_1547; /*0x8571ec*/
            v907->vector[n] = LOBYTE(v167._dateData); /*0x8571f4*/
          }
          v167._dateData = (uint64_t)TypeInfo::PopupControl->static_fields->Instance; /*0x85720c*/
          if ( !v167._dateData ) /*0x857210*/
            goto LABEL_1546; /*0x857210*/
          PopupControl::HideAll((PopupControl *)v167._dateData, nullptr); /*0x857218*/
          v909 = TypeInfo::GameController; /*0x85721c*/
          if ( !TypeInfo::GameController->_1.cctor_finished_or_no_cctor ) /*0x857220*/
          {
            j_il2cpp_runtime_class_init_0(TypeInfo::GameController); /*0x857228*/
            v909 = TypeInfo::GameController; /*0x85722c*/
          }
          v167._dateData = (uint64_t)v909->static_fields->Instance; /*0x857234*/
          if ( !v167._dateData ) /*0x857238*/
            goto LABEL_1546; /*0x857238*/
          GameController::OpenPoolTable((GameController *)v167._dateData, v499, v907, nullptr); /*0x857248*/
          return; /*0x85724c*/
        case 3: /*0x852dac*/
          v910 = (Object_1 *)TypeInfo::MinigameMenu->static_fields->Instance; /*0x857264*/
          if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x857260*/
            j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x85726c*/
          v167._dateData = UnityEngine::Object::op_Inequality(v910, nullptr, nullptr); /*0x85727c*/
          if ( (v167._dateData & 1) != 0 ) /*0x85728c*/
          {
            v912 = TypeInfo::MinigameMenu->static_fields->Instance; /*0x857298*/
            if ( !v912 ) /*0x85729c*/
              goto LABEL_1546; /*0x85729c*/
            if ( v912->curr_menu == 3 ) /*0x8572a8*/
            {
              if ( !v502 ) /*0x8572b0*/
              {
                v913 = (Int32__Array *)sub_73C7E4(TypeInfo::System::Int32, 14); /*0x8572c4*/
                for ( ii = 0; ii != 14; ++ii ) /*0x8572c8*/
                {
                  v167._dateData = Packet::GetByte(incoming, nullptr); /*0x8572d8*/
                  if ( !v913 ) /*0x8572dc*/
                    goto LABEL_1546; /*0x8572dc*/
                  if ( ii >= (unsigned int)v913->max_length.size ) /*0x8572e8*/
                    goto LABEL_1547; /*0x8572e8*/
                  v913->vector[ii] = LOBYTE(v167._dateData); /*0x8572f0*/
                }
                v915 = TypeInfo::PoolGameControl; /*0x857300*/
                if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x857304*/
                {
                  j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x857310*/
                  v915 = TypeInfo::PoolGameControl; /*0x857314*/
                }
                v916 = (Object_1 *)v915->static_fields->Instance; /*0x857324*/
                if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x857320*/
                  j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x857330*/
                if ( UnityEngine::Object::op_Inequality(v916, nullptr, nullptr) ) /*0x857340*/
                {
                  v918 = TypeInfo::PoolGameControl; /*0x857348*/
                  if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x85734c*/
                  {
                    j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x857354*/
                    v918 = TypeInfo::PoolGameControl; /*0x857358*/
                  }
                  v167._dateData = (uint64_t)v918->static_fields->Instance; /*0x857360*/
                  if ( !v167._dateData ) /*0x857364*/
                    goto LABEL_1546; /*0x857364*/
                  *(_QWORD *)(v167._dateData + 200) = v499; /*0x857368*/
                  sub_73C72C(v167._dateData + 200); /*0x857370*/
                  v167._dateData = (uint64_t)TypeInfo::PoolGameControl->static_fields->Instance; /*0x85737c*/
                  if ( !v167._dateData ) /*0x857380*/
                    goto LABEL_1546; /*0x857380*/
                  PoolGameControl::ArrangeBalls((PoolGameControl *)v167._dateData, v913, nullptr); /*0x85738c*/
                  v167._dateData = (uint64_t)TypeInfo::PoolGameControl->static_fields->Instance; /*0x857398*/
                  if ( !v167._dateData ) /*0x85739c*/
                    goto LABEL_1546; /*0x85739c*/
                  PoolGameControl::StartMpGame((PoolGameControl *)v167._dateData, 1, nullptr); /*0x8573a8*/
                }
                if ( !byte_27E6C85 ) /*0x8573b4*/
                {
                  sub_73C778(&TypeInfo::GameServerSender, v168); /*0x8573c0*/
                  byte_27E6C85 = 1; /*0x8573c8*/
                }
                v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x8573dc*/
                if ( !v167._dateData ) /*0x8573e0*/
                  goto LABEL_1546; /*0x8573e0*/
                GameServerSender::SendBeginMinigame((GameServerSender *)v167._dateData, v499, 2u, 0, v913, v917); /*0x8573f4*/
              }
              return; /*0x8573f8*/
            }
            if ( !byte_27E6C85 ) /*0x85822c*/
            {
              sub_73C778(&TypeInfo::GameServerSender, v168); /*0x858238*/
              byte_27E6C85 = 1; /*0x858240*/
            }
            v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x85824c*/
            if ( !v167._dateData ) /*0x858250*/
              goto LABEL_1546; /*0x858250*/
            v973 = 1; /*0x858254*/
            v972 = v499; /*0x858258*/
          }
          else
          {
            if ( !byte_27E6C85 ) /*0x857fd8*/
            {
              sub_73C778(&TypeInfo::GameServerSender, v168); /*0x857fe4*/
              byte_27E6C85 = 1; /*0x857fec*/
            }
            v167._dateData = (uint64_t)TypeInfo::GameServerSender->static_fields->Instance; /*0x857ff8*/
            if ( !v167._dateData ) /*0x857ffc*/
              goto LABEL_1546; /*0x857ffc*/
            v972 = v499; /*0x858000*/
            v973 = 0; /*0x858004*/
          }
          GameServerSender::SendBeginMinigame((GameServerSender *)v167._dateData, v972, v973, v502, nullptr, v911); /*0x858264*/
          return; /*0x858268*/
        default:
          return;
      }
    case 55:
      v563 = TypeInfo::PoolGameControl; // // case 0x38: EXIT_MINIGAME /*0x8534a4*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x8534a8*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x8534b8*/
        v563 = TypeInfo::PoolGameControl; /*0x8534bc*/
      }
      v564 = (Object_1 *)v563->static_fields->Instance; /*0x8534d8*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x8534d4*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x8534e4*/
      if ( !UnityEngine::Object::op_Inequality(v564, nullptr, nullptr) ) /*0x8534f8*/
        return; /*0x8534f8*/
      v167._dateData = (uint64_t)TypeInfo::PoolGameControl; /*0x8534fc*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x853500*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x85350c*/
        v167._dateData = (uint64_t)TypeInfo::PoolGameControl; /*0x853510*/
      }
      v565 = **(_QWORD **)(v167._dateData + 184); /*0x853518*/
      if ( !v565 ) /*0x85351c*/
        goto LABEL_1546; /*0x85351c*/
      *(_BYTE *)(v565 + 336) = 0; /*0x853520*/
      v167._dateData = (uint64_t)TypeInfo::WindowControl->static_fields->Instance; /*0x85352c*/
      if ( !v167._dateData ) /*0x853530*/
        goto LABEL_1546; /*0x853530*/
      WindowControl::PressClose((WindowControl *)v167._dateData, nullptr); /*0x853538*/
      v167._dateData = (uint64_t)TypeInfo::PopupControl->static_fields->Instance; /*0x853544*/
      if ( !v167._dateData ) /*0x853548*/
        goto LABEL_1546; /*0x853548*/
      v566 = &StringLiteral_Other_player_left; /*0x853550*/
      goto LABEL_605; /*0x853550*/
    case 56:
      v727 = TypeInfo::PoolGameControl; // // case 0x39: POOL_CUE_POS /*0x854f78*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x854f7c*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x854f88*/
        v727 = TypeInfo::PoolGameControl; /*0x854f8c*/
      }
      v728 = (Object_1 *)v727->static_fields->Instance; /*0x854fa4*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x854fa0*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x854fb0*/
      if ( !UnityEngine::Object::op_Inequality(v728, nullptr, nullptr) ) /*0x854fc4*/
        return; /*0x854fc4*/
      v729 = Packet::GetLong(incoming, nullptr); /*0x854fd4*/
      v730 = TypeInfo::PoolGameControl; /*0x854fd8*/
      v731 = v729; /*0x854fdc*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x854fe0*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x854fec*/
        v730 = TypeInfo::PoolGameControl; /*0x854ff0*/
      }
      v167._dateData = (uint64_t)v730->static_fields->Instance; /*0x854ff8*/
      if ( !v167._dateData ) /*0x854ffc*/
        goto LABEL_1546; /*0x854ffc*/
      PoolGameControl::TryUpdateCuePosition((PoolGameControl *)v167._dateData, (float)v731 / 100.0, nullptr); /*0x855014*/
      return; /*0x855018*/
    case 57:
      v509 = TypeInfo::PoolGameControl; // // case 0x3A: POOL_SHOOT /*0x852ea8*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x852eac*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x852eb8*/
        v509 = TypeInfo::PoolGameControl; /*0x852ebc*/
      }
      v510 = (Object_1 *)v509->static_fields->Instance; /*0x852ed4*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x852ed0*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x852ee0*/
      if ( !UnityEngine::Object::op_Inequality(v510, nullptr, nullptr) ) /*0x852ef4*/
        return; /*0x852ef4*/
      v511 = Packet::GetLong(incoming, nullptr); /*0x852f10*/
      v512 = Packet::GetShort(incoming, nullptr); /*0x852f20*/
      v513 = Packet::GetLong(incoming, nullptr); /*0x852f34*/
      v514 = (Byte__Array *)sub_73C7E4(TypeInfo::System::Byte, (unsigned int)v513); /*0x852f48*/
      if ( v513 < 1 ) /*0x852f4c*/
        goto LABEL_539; /*0x852f4c*/
      for ( jj = 0; jj != v513; v514->vector[jj++] = v167._dateData ) /*0x852f50*/
      {
        v167._dateData = Packet::GetByte(incoming, nullptr); /*0x852f64*/
        if ( !v514 ) /*0x852f68*/
          goto LABEL_1546; /*0x852f68*/
        if ( jj >= (unsigned int)v514->max_length.size ) /*0x852f74*/
          goto LABEL_1547; /*0x852f74*/
      }
LABEL_539:
      v167._dateData = sub_73C88C(TypeInfo::PoolGameRecording); /*0x852f88*/
      if ( !v167._dateData ) /*0x852f98*/
        goto LABEL_1546; /*0x852f98*/
      v516 = (PoolGameRecording *)v167._dateData; /*0x852fa0*/
      PoolGameRecording::PoolGameRecording((PoolGameRecording *)v167._dateData, nullptr); /*0x852fa4*/
      PoolGameRecording::unpack_from_web(v516, v514, nullptr); /*0x852fb4*/
      v167._dateData = (uint64_t)TypeInfo::PoolGameControl; /*0x852fb8*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x852fbc*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x852fc4*/
        v167._dateData = (uint64_t)TypeInfo::PoolGameControl; /*0x852fc8*/
      }
      v517 = **(_QWORD **)(v167._dateData + 184); /*0x852fd0*/
      if ( !v517 ) /*0x852fd4*/
        goto LABEL_1546; /*0x852fd4*/
      *(float *)(v517 + 300) = (float)v511 / 100.0; /*0x852ffc*/
      *(float *)(v517 + 296) = (float)v512 / 100.0; /*0x853000*/
      *(_QWORD *)(v517 + 304) = v516; /*0x853004*/
      sub_73C72C(v517 + 304); /*0x853008*/
      v167._dateData = (uint64_t)TypeInfo::PoolGameControl->static_fields->Instance; /*0x853014*/
      if ( !v167._dateData ) /*0x853018*/
        goto LABEL_1546; /*0x853018*/
      if ( *(_DWORD *)(v167._dateData + 212) == 18 ) /*0x853024*/
      {
        if ( TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor /*0x853044*/
          || (j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl),
              (v167._dateData = (uint64_t)TypeInfo::PoolGameControl->static_fields->Instance) != 0) )
        {
          PoolGameControl::ShowMpRecording((PoolGameControl *)v167._dateData, nullptr); /*0x85304c*/
          return; /*0x853050*/
        }
        goto LABEL_1546; /*0x853044*/
      }
      return; /*0x853024*/
    case 58:
      v235 = TypeInfo::PoolGameControl; // // case 0x3B: POOL_SYNC_READY /*0x8505c4*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x8505c8*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x8505d4*/
        v235 = TypeInfo::PoolGameControl; /*0x8505d8*/
      }
      v236 = (Object_1 *)v235->static_fields->Instance; /*0x8505f0*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x8505ec*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x8505fc*/
      if ( !UnityEngine::Object::op_Inequality(v236, nullptr, nullptr) ) /*0x850610*/
        return; /*0x850610*/
      v237 = TypeInfo::PoolGameControl; /*0x850614*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x850618*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x850624*/
        v237 = TypeInfo::PoolGameControl; /*0x850628*/
      }
      v167._dateData = (uint64_t)v237->static_fields->Instance; /*0x850630*/
      if ( !v167._dateData ) /*0x850634*/
        goto LABEL_1546; /*0x850634*/
      PoolGameControl::OnOtherPlayerReady((PoolGameControl *)v167._dateData, nullptr); /*0x85063c*/
      return; /*0x850640*/
    case 59:
      v207 = TypeInfo::PoolGameControl; // // case 0x3C: POOL_PLACE_BALL /*0x8500ac*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x8500b0*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x8500bc*/
        v207 = TypeInfo::PoolGameControl; /*0x8500c0*/
      }
      v208 = (Object_1 *)v207->static_fields->Instance; /*0x8500d8*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x8500d4*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x8500e4*/
      if ( !UnityEngine::Object::op_Inequality(v208, nullptr, nullptr) ) /*0x8500f8*/
        return; /*0x8500f8*/
      v209 = Packet::GetLong(incoming, nullptr); /*0x850110*/
      v210 = Packet::GetLong(incoming, nullptr); /*0x85011c*/
      v211 = TypeInfo::PoolGameControl; /*0x850120*/
      v212 = v210; /*0x850124*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x850128*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x850134*/
        v211 = TypeInfo::PoolGameControl; /*0x850138*/
      }
      v167._dateData = (uint64_t)v211->static_fields->Instance; /*0x850140*/
      if ( !v167._dateData ) /*0x850144*/
        goto LABEL_1546; /*0x850144*/
      v1034.x = (float)v209; /*0x850148*/
      v1034.y = (float)v212; /*0x85014c*/
      PoolGameControl::PlaceWhiteBallAt((PoolGameControl *)v167._dateData, v1034, nullptr); /*0x850154*/
      return; /*0x850158*/
    case 60:
      v756 = (Int32__Array *)sub_73C7E4(TypeInfo::System::Int32, 14);// // case 0x3D: POOL_PLAY_AGAIN /*0x855448*/
      for ( kk = 0; kk != 14; ++kk ) /*0x85544c*/
      {
        v167._dateData = Packet::GetByte(incoming, nullptr); /*0x85545c*/
        if ( !v756 ) /*0x855460*/
          goto LABEL_1546; /*0x855460*/
        if ( kk >= (unsigned int)v756->max_length.size ) /*0x85546c*/
          goto LABEL_1547; /*0x85546c*/
        v756->vector[kk] = LOBYTE(v167._dateData); /*0x855474*/
      }
      v758 = TypeInfo::PoolGameControl; /*0x855484*/
      if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x855488*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x855490*/
        v758 = TypeInfo::PoolGameControl; /*0x855494*/
      }
      v759 = (Object_1 *)v758->static_fields->Instance; /*0x8554a4*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x8554a0*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x8554b0*/
      if ( UnityEngine::Object::op_Inequality(v759, nullptr, nullptr) ) /*0x8554c0*/
      {
        v760 = TypeInfo::PoolGameControl; /*0x8554c8*/
        if ( !TypeInfo::PoolGameControl->_1.cctor_finished_or_no_cctor ) /*0x8554d0*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::PoolGameControl); /*0x8554d8*/
          v760 = TypeInfo::PoolGameControl; /*0x8554dc*/
        }
        v167._dateData = (uint64_t)v760->static_fields->Instance; /*0x8554e4*/
        if ( !v167._dateData ) /*0x8554e8*/
          goto LABEL_1546; /*0x8554e8*/
        PoolGameControl::ArrangeBalls((PoolGameControl *)v167._dateData, v756, nullptr); /*0x8554f4*/
        v167._dateData = (uint64_t)TypeInfo::PoolGameControl->static_fields->Instance; /*0x855500*/
        if ( !v167._dateData ) /*0x855504*/
          goto LABEL_1546; /*0x855504*/
        PoolGameControl::RestartMpGame((PoolGameControl *)v167._dateData, nullptr); /*0x85550c*/
      }
      return; /*0x855510*/
    case 61:
      v718 = Packet::GetString(incoming, nullptr);// // case 0x3E: FINISH_SIT /*0x854d50*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x854d5c*/
      if ( !TypeInfo::GameServerInterface->static_fields->Instance ) /*0x854d74*/
        goto LABEL_1546; /*0x854d74*/
      v719 = (String *)v167._dateData; /*0x854d78*/
      PlayerByUsername = (Object_1 *)GameServerInterface::GetPlayerByUsername( /*0x854d8c*/
                                       TypeInfo::GameServerInterface->static_fields->Instance,
                                       v718,
                                       (MethodInfo *)v169);
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x854d90*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x854d9c*/
      if ( !UnityEngine::Object::op_Inequality(PlayerByUsername, nullptr, nullptr) ) /*0x854db0*/
        return; /*0x854db0*/
      v167._dateData = System::String::op_Inequality(v719, (String *)"", nullptr); /*0x854dc0*/
      if ( !PlayerByUsername ) /*0x854dc4*/
        goto LABEL_1546; /*0x854dc4*/
      v721 = v167._dateData; /*0x854dd0*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x854ddc*/
                                   (GameObject *)PlayerByUsername,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x854de0*/
        goto LABEL_1546; /*0x854de0*/
      if ( (v721 & 1) != 0 ) /*0x854de4*/
        SharedCreature::TrySitInChairObj((SharedCreature *)v167._dateData, v719, nullptr); /*0x854df0*/
      else
        SharedCreature::EndSittingInChair((SharedCreature *)v167._dateData, nullptr); /*0x856ff0*/
      return; /*0x854df4*/
    case 62:
      v229 = Packet::GetByte(incoming, nullptr);// // case 0x3F: CLAIM_MOBS /*0x8503f0*/
      if ( !v229 ) /*0x8503f4*/
        return; /*0x8503f4*/
      do /*0x8505b4*/
      {
        v230 = (Object *)Packet::GetString(incoming, nullptr); /*0x850438*/
        v167._dateData = Packet::GetByte(incoming, nullptr); /*0x850444*/
        if ( LOBYTE(v167._dateData) == 1 ) /*0x850450*/
        {
          if ( !byte_27E6C85 ) /*0x850458*/
          {
            v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x850460*/
            byte_27E6C85 = 1; /*0x850464*/
          }
          v231 = TypeInfo::GameServerSender->static_fields->Instance; /*0x850470*/
          if ( !v231 ) /*0x850474*/
            goto LABEL_1546; /*0x850474*/
          v167._dateData = (uint64_t)v231->mobs_I_am_trying_to_claim_awaiting_response; /*0x850478*/
          if ( !v167._dateData ) /*0x85047c*/
            goto LABEL_1546; /*0x85047c*/
          v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x850488*/
                             (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                             v230,
                             MethodInfo::System::Collections::Generic::Dictionary<System::String,CreatureStruct>::ContainsKey);
          if ( (v167._dateData & 1) != 0 ) /*0x85048c*/
          {
            v232 = TypeInfo::MobControl->static_fields->Instance; /*0x8504a0*/
            if ( !v232 ) /*0x8504a4*/
              goto LABEL_1546; /*0x8504a4*/
            v167._dateData = (uint64_t)v232->active_combatants; /*0x8504a8*/
            if ( !v167._dateData ) /*0x8504ac*/
              goto LABEL_1546; /*0x8504ac*/
            v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x8504c0*/
                               (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                               v230,
                               MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
            if ( (v167._dateData & 1) == 0 ) /*0x8504c4*/
            {
              if ( !byte_27E6C85 ) /*0x8504cc*/
              {
                v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x8504d4*/
                byte_27E6C85 = 1; /*0x8504d8*/
              }
              v233 = TypeInfo::GameServerSender->static_fields->Instance; /*0x8504e4*/
              if ( !v233 ) /*0x8504e8*/
                goto LABEL_1546; /*0x8504e8*/
              v167._dateData = (uint64_t)v233->mobs_I_am_trying_to_claim_awaiting_response; /*0x8504ec*/
              if ( !v167._dateData ) /*0x8504f0*/
                goto LABEL_1546; /*0x8504f0*/
              v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8504fc*/
                                           (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                           v230,
                                           MethodInfo::System::Collections::Generic::Dictionary<System::String,CreatureStruct>::get_Item);
              if ( !v167._dateData ) /*0x850500*/
                goto LABEL_1546; /*0x850500*/
              v168 = v167._dateData; /*0x85050c*/
              v167._dateData = (uint64_t)TypeInfo::MobControl->static_fields->Instance; /*0x850518*/
              if ( !v167._dateData ) /*0x85051c*/
                goto LABEL_1546; /*0x85051c*/
              v1036.x = (float)((float)((float)(10 * *(_DWORD *)(v168 + 144)) + (float)*(int *)(v168 + 152)) /*0x850568*/
                              + (float)*(int *)(v168 + 160))
                      + 0.5;
              v1036.z = (float)((float)((float)(10 * *(_DWORD *)(v168 + 148)) + (float)*(int *)(v168 + 156)) /*0x85056c*/
                              + (float)*(int *)(v168 + 164))
                      + 0.5;
              v1036.y = 1.5; /*0x850570*/
              v167._dateData = (uint64_t)MobControl::SpawnLocalMob( /*0x850574*/
                                           (MobControl *)v167._dateData,
                                           (CreatureStruct *)v168,
                                           v1036,
                                           nullptr);
            }
          }
        }
        if ( !byte_27E6C85 ) /*0x85057c*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x850584*/
          byte_27E6C85 = 1; /*0x850588*/
        }
        v234 = TypeInfo::GameServerSender->static_fields->Instance; /*0x850594*/
        if ( !v234 ) /*0x850598*/
          goto LABEL_1546; /*0x850598*/
        v167._dateData = (uint64_t)v234->mobs_I_am_trying_to_claim_awaiting_response; /*0x85059c*/
        if ( !v167._dateData ) /*0x8505a0*/
          goto LABEL_1546; /*0x8505a0*/
        System::Collections::Generic::Dictionary<System::Object,System::Object>::Remove( /*0x8505ac*/
          (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
          v230,
          MethodInfo::System::Collections::Generic::Dictionary<System::String,CreatureStruct>::Remove);
        --v229; /*0x8505b0*/
      }
      while ( v229 ); /*0x8505b4*/
      return; /*0x8505b4*/
    case 63:
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr);// // case 0x40: DELOAD_MOB /*0x85391c*/
      v590 = TypeInfo::MobControl->static_fields->Instance; /*0x853930*/
      if ( !v590 ) /*0x853934*/
        goto LABEL_1546; /*0x853934*/
      v591 = (Object *)v167._dateData; /*0x853938*/
      v167._dateData = (uint64_t)v590->active_combatants; /*0x85393c*/
      if ( !v167._dateData ) /*0x853940*/
        goto LABEL_1546; /*0x853940*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x853954*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v591,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x853958*/
        return; /*0x853958*/
      v592 = TypeInfo::MobControl->static_fields->Instance; /*0x85396c*/
      if ( !v592 ) /*0x853970*/
        goto LABEL_1546; /*0x853970*/
      v167._dateData = (uint64_t)v592->active_combatants; /*0x853978*/
      if ( !v167._dateData ) /*0x853980*/
        goto LABEL_1546; /*0x853980*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x853994*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v591,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      v593 = TypeInfo::ChunkControl; /*0x85399c*/
      v594 = (GameObject *)v167._dateData; /*0x8539a0*/
      if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x8539a4*/
      {
        v167._dateData = j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x8539b0*/
        v593 = TypeInfo::ChunkControl; /*0x8539b8*/
      }
      if ( !v594 ) /*0x8539bc*/
        goto LABEL_1546; /*0x8539bc*/
      v595 = v593->static_fields->Instance; /*0x8539cc*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::get_transform(v594, nullptr); /*0x8539d0*/
      if ( !v167._dateData ) /*0x8539d4*/
        goto LABEL_1546; /*0x8539d4*/
      position = UnityEngine::Transform::get_position((Transform *)v167._dateData, nullptr); /*0xf1c0000000000090*/
      if ( !v595 ) /*0x8539e0*/
        goto LABEL_1546; /*0x8539e0*/
      v596 = ChunkControl::GetChunkString(v595, position, nullptr); /*0x8539f4*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8539fc*/
                                   v594,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x853a00*/
        goto LABEL_1546; /*0x853a00*/
      if ( *(_DWORD *)(v167._dateData + 184) == 9 ) /*0x853a0c*/
        goto LABEL_659; /*0x853a0c*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x856fb4*/
                                   v594,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x856fb8*/
        goto LABEL_1546; /*0x856fb8*/
      if ( *(_DWORD *)(v167._dateData + 184) == 6 ) /*0x856fc4*/
      {
        v597 = TypeInfo::UnityEngine::Object; /*0x856fc8*/
      }
      else
      {
        v961 = TypeInfo::ChunkControl; /*0x857db0*/
        if ( !TypeInfo::ChunkControl->_1.cctor_finished_or_no_cctor ) /*0x857db4*/
        {
          j_il2cpp_runtime_class_init_0(TypeInfo::ChunkControl); /*0x857dbc*/
          v961 = TypeInfo::ChunkControl; /*0x857dc0*/
        }
        v167._dateData = (uint64_t)v961->static_fields->Instance; /*0x857dc8*/
        if ( !v167._dateData ) /*0x857dcc*/
          goto LABEL_1546; /*0x857dcc*/
        if ( ChunkControl::IsChunkFullyLoadedOrMidload((ChunkControl *)v167._dateData, v596, nullptr) ) /*0x857dd8*/
        {
          v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x857de4*/
          if ( !v167._dateData ) /*0x857de8*/
            goto LABEL_1546; /*0x857de8*/
          v962 = (Packet *)v167._dateData; /*0x857df0*/
          Packet::Packet((Packet *)v167._dateData, nullptr); /*0x857df4*/
          Packet::PutByte(v962, 0x44u, nullptr); /*0x857e04*/
          Packet::PutString(v962, (String *)v591, nullptr); /*0x857e14*/
          v167._dateData = (uint64_t)GameServerReceiver::get_connection(v963, v964); /*0x857e18*/
          if ( !v167._dateData ) /*0x857e1c*/
            goto LABEL_1546; /*0x857e1c*/
          v227 = Connection_priority__Enum_DEFAULT; /*0x857e20*/
          v228 = v962; /*0x857e24*/
LABEL_1396:
          Connection::Send((Connection *)v167._dateData, v228, v227, nullptr); /*0x857938*/
          return; /*0x857940*/
        }
LABEL_659:
        v597 = TypeInfo::UnityEngine::Object; /*0x853a10*/
      }
      if ( !v597->_1.cctor_finished_or_no_cctor ) /*0x856fd0*/
        j_il2cpp_runtime_class_init_0(v597); /*0x856fd8*/
      v737 = (Object_1 *)v594; /*0x856fdc*/
LABEL_1276:
      UnityEngine::Object::Destroy(v737, nullptr); /*0x856fe0*/
      return; /*0x856fe8*/
    case 64:
      v167._dateData = sub_73C88C(TypeInfo::System::Collections::Generic::List<System::String>);// // case 0x41: MOB_POSITIONS /*0x853d7c*/
      if ( !v167._dateData ) /*0x853d80*/
        goto LABEL_1546; /*0x853d80*/
      v626 = (List_1_System_Object_ *)v167._dateData; /*0x853d88*/
      System::Collections::Generic::List<System::Object>::List( /*0x853d8c*/
        (List_1_System_Object_ *)v167._dateData,
        MethodInfo::System::Collections::Generic::List<System::String>::List);
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x853d9c*/
      v627 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x853dbc*/
      if ( !v627 ) /*0x853dc8*/
        goto LABEL_1546; /*0x853dc8*/
      v628 = (Object *)v167._dateData; /*0x853dcc*/
      v167._dateData = (uint64_t)v627->nearby_players; /*0x853dd0*/
      if ( !v167._dateData ) /*0x853dd4*/
        goto LABEL_1546; /*0x853dd4*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x853de8*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v628,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::ContainsKey);
      str = (String *)v628; /*0x853dec*/
      if ( (v167._dateData & 1) != 0 ) /*0x853df0*/
      {
        v629 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x853e04*/
        if ( !v629 ) /*0x853e08*/
          goto LABEL_1546; /*0x853e08*/
        v167._dateData = (uint64_t)v629->nearby_players; /*0x853e0c*/
        if ( !v167._dateData ) /*0x853e10*/
          goto LABEL_1546; /*0x853e10*/
        v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x853e1c*/
                                     (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                     v628,
                                     MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::get_Item);
        if ( !v167._dateData ) /*0x853e20*/
          goto LABEL_1546; /*0x853e20*/
        v630 = *(_DWORD *)(v167._dateData + 40); /*0x853e24*/
        if ( v630 ) /*0x853e28*/
        {
          v631 = 0; /*0x853e2c*/
        }
        else
        {
          v630 = 5; /*0x8575a4*/
          v631 = 1; /*0x8575a8*/
          *(_DWORD *)(v167._dateData + 40) = 5; /*0x8575ac*/
        }
        *(_DWORD *)(v167._dateData + 40) = v630 - 1; /*0x8575b4*/
      }
      else
      {
        v631 = 0; /*0x856334*/
      }
      v927 = Packet::GetByte(incoming, nullptr); /*0x8575c4*/
      if ( !v927 ) /*0x8575c8*/
        goto LABEL_1389; /*0x8575c8*/
      do /*0x857884*/
      {
        v928 = Packet::GetString(incoming, nullptr); /*0x8575e0*/
        v1029 = GameServerReceiver::UnpackPosition((GameServerReceiver *)v928, incoming, v929); /*0x8575e4*/
        v1030 = GameServerReceiver::UnpackPosition(v930, incoming, v931); /*0x8575f8*/
        v1033 = GameServerReceiver::UnpackRotation(v932, incoming, v933); /*0x85760c*/
        v934 = TypeInfo::MobControl->static_fields->Instance; /*0x857620*/
        if ( !v934 ) /*0x857624*/
          goto LABEL_1546; /*0x857624*/
        v167._dateData = (uint64_t)v934->active_combatants; /*0x85762c*/
        if ( !v167._dateData ) /*0x857630*/
          goto LABEL_1546; /*0x857630*/
        v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x85764c*/
                           (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                           (Object *)v928,
                           MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
        if ( (v167._dateData & 1) != 0 ) /*0x857650*/
        {
          v935 = TypeInfo::MobControl->static_fields->Instance; /*0x857664*/
          if ( !v935 ) /*0x857668*/
            goto LABEL_1546; /*0x857668*/
          v167._dateData = (uint64_t)v935->active_combatants; /*0x85766c*/
          if ( !v167._dateData ) /*0x857670*/
            goto LABEL_1546; /*0x857670*/
          v936 = System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x85768c*/
                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                   (Object *)v928,
                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
          if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x857690*/
            j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x85769c*/
          v167._dateData = UnityEngine::Object::op_Inequality((Object_1 *)v936, nullptr, nullptr); /*0x8576ac*/
          if ( (v167._dateData & 1) != 0 ) /*0x8576b0*/
          {
            if ( v631 ) /*0x8576b4*/
            {
              if ( !TypeInfo::GameServerInterface->static_fields->Instance ) /*0x8576cc*/
                goto LABEL_1546; /*0x8576cc*/
              GameServerInterface::CreateMovementSmoother( /*0x8576ec*/
                (GameServerInterface *)v167._dateData,
                (GameObject *)v936,
                v1029,
                v1030,
                (MethodInfo *)v169);
            }
            if ( !v936 ) /*0x8576f0*/
              goto LABEL_1546; /*0x8576f0*/
            v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8576fc*/
                                         (GameObject *)v936,
                                         MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
            if ( !v167._dateData ) /*0x857700*/
              goto LABEL_1546; /*0x857700*/
            SharedCreature::SetMoveTo((SharedCreature *)v167._dateData, v1030, nullptr); /*0x857714*/
            v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x857720*/
                                         (GameObject *)v936,
                                         MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
            if ( !v167._dateData ) /*0x857724*/
              goto LABEL_1546; /*0x857724*/
            SharedCreature::SnapSpotterRotation((SharedCreature *)v167._dateData, v1033, nullptr); /*0x857738*/
          }
        }
        else
        {
          if ( !byte_27E6C85 ) /*0x857748*/
          {
            v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x857750*/
            byte_27E6C85 = 1; /*0x857758*/
          }
          v937 = TypeInfo::GameServerSender->static_fields->Instance; /*0x857764*/
          if ( !v937 ) /*0x857768*/
            goto LABEL_1546; /*0x857768*/
          v167._dateData = (uint64_t)v937->other_players_mobs_that_I_inquired_about; /*0x85776c*/
          if ( !v167._dateData ) /*0x857770*/
            goto LABEL_1546; /*0x857770*/
          v167._dateData = System::Collections::Generic::List<System::Object>::Contains( /*0x85777c*/
                             (List_1_System_Object_ *)v167._dateData,
                             (Object *)v928,
                             MethodInfo::System::Collections::Generic::List<System::String>::Contains);
          if ( (v167._dateData & 1) == 0 ) /*0x857780*/
          {
            v938 = v626->_items; /*0x85778c*/
            v939 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x857798*/
            ++v626->_version; /*0x85779c*/
            if ( !v938 ) /*0x8577a0*/
              goto LABEL_1546; /*0x8577a0*/
            v940 = v626->_size; /*0x8577a4*/
            if ( (unsigned int)v940 >= v938->max_length.size ) /*0x8577b0*/
            {
              v167._dateData = (*((__int64 (__fastcall **)(List_1_System_Object_ *, String *))v939->klass->rgctx_data[11].rgctxDataDummy /*0x8577e8*/
                                + 1))(
                                 v626,
                                 v928);
            }
            else
            {
              v941 = &v938->klass + v940; /*0x8577b8*/
              v626->_size = v940 + 1; /*0x8577bc*/
              v941[4] = (Object__Array__Class *)v928; /*0x8577c0*/
              v167._dateData = sub_73C72C(v941 + 4); /*0x8577c8*/
            }
            if ( !byte_27E6C85 ) /*0x8577f0*/
            {
              v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x8577f8*/
              byte_27E6C85 = 1; /*0x8577fc*/
            }
            v942 = TypeInfo::GameServerSender->static_fields->Instance; /*0x857808*/
            if ( !v942 ) /*0x85780c*/
              goto LABEL_1546; /*0x85780c*/
            v167._dateData = (uint64_t)v942->other_players_mobs_that_I_inquired_about; /*0x857810*/
            if ( !v167._dateData ) /*0x857814*/
              goto LABEL_1546; /*0x857814*/
            v943 = *(_QWORD *)(v167._dateData + 16); /*0x857820*/
            v944 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x85782c*/
            ++*(_DWORD *)(v167._dateData + 28); /*0x857830*/
            if ( !v943 ) /*0x857834*/
              goto LABEL_1546; /*0x857834*/
            v945 = *(int *)(v167._dateData + 24); /*0x857838*/
            if ( (unsigned int)v945 >= *(_DWORD *)(v943 + 24) ) /*0x857844*/
            {
              (*((void (**)(void))v944->klass->rgctx_data[11].rgctxDataDummy + 1))(); /*0x85787c*/
            }
            else
            {
              v946 = v943 + 8 * v945; /*0x85784c*/
              *(_DWORD *)(v167._dateData + 24) = v945 + 1; /*0x857850*/
              *(_QWORD *)(v946 + 32) = v928; /*0x857854*/
              sub_73C72C(v946 + 32); /*0x857860*/
            }
          }
        }
        --v927; /*0x857880*/
      }
      while ( v927 ); /*0x857884*/
LABEL_1389:
      if ( !v626->_size ) /*0x857894*/
        return; /*0x857894*/
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x85789c*/
      if ( !v167._dateData ) /*0x8578a0*/
        goto LABEL_1546; /*0x8578a0*/
      v837 = (Packet *)v167._dateData; /*0x8578a8*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x8578ac*/
      Packet::PutByte(v837, 0x42u, nullptr); /*0x8578bc*/
      Packet::PutString(v837, str, nullptr); /*0x8578cc*/
      Packet::PutByte(v837, v626->_size, nullptr); /*0x8578dc*/
      if ( v626->_size >= 1 ) /*0x8578f0*/
      {
        v947 = 0; /*0x8578f4*/
        do /*0x857924*/
        {
          v948 = System::Collections::Generic::List<System::Object>::get_Item( /*0x857904*/
                   v626,
                   v947,
                   MethodInfo::System::Collections::Generic::List<System::String>::get_Item);
          Packet::PutString(v837, (String *)v948, nullptr); /*0x857914*/
          ++v947; /*0x85791c*/
        }
        while ( v947 < v626->_size ); /*0x857924*/
      }
LABEL_1394:
      v167._dateData = (uint64_t)GameServerReceiver::get_connection( /*0x857928*/
                                   (GameServerReceiver *)v167._dateData,
                                   (MethodInfo *)v168);
      if ( !v167._dateData ) /*0x85792c*/
        goto LABEL_1546; /*0x85792c*/
LABEL_1395:
      v227 = Connection_priority__Enum_DEFAULT; /*0x857930*/
      v228 = v837; /*0x857934*/
      goto LABEL_1396; /*0x857934*/
    case 65:
      v213 = Packet::GetString(incoming, nullptr);// // case 0x42: UNKNOWN_0x42 /*0x850178*/
      v167._dateData = sub_73C88C(TypeInfo::Packet); /*0x850184*/
      if ( !v167._dateData ) /*0x850188*/
        goto LABEL_1546; /*0x850188*/
      v214 = (Packet *)v167._dateData; /*0x850190*/
      Packet::Packet((Packet *)v167._dateData, nullptr); /*0x850194*/
      Packet::PutByte(v214, 0x43u, nullptr); /*0x8501a4*/
      Packet::PutString(v214, v213, nullptr); /*0x8501b4*/
      v215 = Packet::GetByte(incoming, nullptr); /*0x8501c4*/
      Packet::PutByte(v214, v215, nullptr); /*0x8501d4*/
      v218 = v215; /*0x8501e8*/
      if ( !v215 ) /*0x8501f0*/
        goto LABEL_111; /*0x8501f0*/
      do /*0x8503cc*/
      {
        v219 = Packet::GetString(incoming, nullptr); /*0x850204*/
        Packet::PutString(v214, v219, nullptr); /*0x850214*/
        v220 = TypeInfo::MobControl->static_fields->Instance; /*0x850228*/
        if ( !v220 ) /*0x85022c*/
          goto LABEL_1546; /*0x85022c*/
        v167._dateData = (uint64_t)v220->active_combatants; /*0x850230*/
        if ( !v167._dateData ) /*0x850234*/
          goto LABEL_1546; /*0x850234*/
        v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x850248*/
                           (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                           (Object *)v219,
                           MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
        if ( (v167._dateData & 1) == 0 ) /*0x85024c*/
          goto LABEL_109; /*0x85024c*/
        v221 = TypeInfo::MobControl->static_fields->Instance; /*0x850260*/
        if ( !v221 ) /*0x850264*/
          goto LABEL_1546; /*0x850264*/
        v167._dateData = (uint64_t)v221->active_combatants; /*0x850268*/
        if ( !v167._dateData ) /*0x85026c*/
          goto LABEL_1546; /*0x85026c*/
        v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x850280*/
                                     (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                     (Object *)v219,
                                     MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
        if ( !v167._dateData ) /*0x850284*/
          goto LABEL_1546; /*0x850284*/
        v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x85028c*/
                                     (GameObject *)v167._dateData,
                                     MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
        v222 = TypeInfo::MobControl->static_fields->Instance; /*0x8502a0*/
        if ( !v222 ) /*0x8502a4*/
          goto LABEL_1546; /*0x8502a4*/
        v223 = v167._dateData; /*0x8502a8*/
        v167._dateData = (uint64_t)v222->my_claimed_creatures; /*0x8502ac*/
        if ( !v167._dateData ) /*0x8502b0*/
          goto LABEL_1546; /*0x8502b0*/
        v167._dateData = System::Collections::Generic::List<System::Object>::Contains( /*0x8502bc*/
                           (List_1_System_Object_ *)v167._dateData,
                           (Object *)v219,
                           MethodInfo::System::Collections::Generic::List<System::String>::Contains);
        if ( (v167._dateData & 1) != 0 ) /*0x8502c0*/
          goto LABEL_99; /*0x8502c0*/
        if ( !v223 ) /*0x8502c4*/
          goto LABEL_1546; /*0x8502c4*/
        if ( *(_BYTE *)(v223 + 172) && *(_DWORD *)(v223 + 184) == 6 ) /*0x8502d8*/
        {
LABEL_99:
          Packet::PutByte(v214, 1u, nullptr); /*0x8502e8*/
          v224 = TypeInfo::MobControl->static_fields->Instance; /*0x8502fc*/
          if ( !v224 ) /*0x850300*/
            goto LABEL_1546; /*0x850300*/
          v167._dateData = (uint64_t)v224->active_combatants; /*0x850304*/
          if ( !v167._dateData ) /*0x850308*/
            goto LABEL_1546; /*0x850308*/
          v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x85031c*/
                                       (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                       (Object *)v219,
                                       MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
          if ( !TypeInfo::MobControl->static_fields->Instance ) /*0x850330*/
            goto LABEL_1546; /*0x850330*/
          v225 = (GameObject *)v167._dateData; /*0x850338*/
          v167._dateData = (uint64_t)MobControl::ObjToCreatureStruct( /*0x850348*/
                                       TypeInfo::MobControl->static_fields->Instance,
                                       (GameObject *)v167._dateData,
                                       nullptr);
          if ( !v167._dateData ) /*0x85034c*/
            goto LABEL_1546; /*0x85034c*/
          CreatureStruct::Pack((CreatureStruct *)v167._dateData, v214, nullptr); /*0x850358*/
          Packet::PutString(v214, v219, nullptr); /*0x850368*/
          if ( !byte_27E6C85 ) /*0x850370*/
          {
            v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x850378*/
            byte_27E6C85 = 1; /*0x85037c*/
          }
          if ( !v225 ) /*0x850380*/
            goto LABEL_1546; /*0x850380*/
          v226 = TypeInfo::GameServerSender->static_fields->Instance; /*0x850394*/
          v167._dateData = (uint64_t)UnityEngine::GameObject::get_transform(v225, nullptr); /*0x850398*/
          if ( !v167._dateData ) /*0x85039c*/
            goto LABEL_1546; /*0x85039c*/
          v1039 = UnityEngine::Transform::get_position((Transform *)v167._dateData, nullptr); /*0xf1c000000000002c*/
          if ( !v226 ) /*0x8503a8*/
            goto LABEL_1546; /*0x8503a8*/
          GameServerSender::PackPosition((GameServerSender *)v167._dateData, v214, v1039, (MethodInfo *)v169); /*0x8503b0*/
        }
        else
        {
LABEL_109:
          Packet::PutByte(v214, 0, nullptr); /*0x8503c4*/
        }
        --v218; /*0x8503c8*/
      }
      while ( v218 ); /*0x8503cc*/
LABEL_111:
      v167._dateData = (uint64_t)GameServerReceiver::get_connection(v216, v217); /*0x8503d0*/
      if ( !v167._dateData ) /*0x8503d4*/
        goto LABEL_1546; /*0x8503d4*/
      v227 = Connection_priority__Enum_DEFAULT; /*0x8503d8*/
      v228 = v214; /*0x8503dc*/
      goto LABEL_1396; /*0x8503e0*/
    case 66:
      v682 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x43: UNKNOWN_0x43 /*0x8547a8*/
      v683 = Packet::GetByte(incoming, nullptr); /*0x8547b8*/
      if ( !v683 ) /*0x8547bc*/
        return; /*0x8547bc*/
      do /*0x8548f8*/
      {
        v684 = (Object *)Packet::GetString(incoming, nullptr); /*0x8547e8*/
        v167._dateData = Packet::GetByte(incoming, nullptr); /*0x8547f4*/
        if ( LOBYTE(v167._dateData) == 1 ) /*0x854800*/
        {
          if ( !TypeInfo::CreatureStruct->_1.cctor_finished_or_no_cctor ) /*0x854808*/
            j_il2cpp_runtime_class_init_0(TypeInfo::CreatureStruct); /*0x854810*/
          v685 = CreatureStruct::PacketToCreatureStruct(incoming, nullptr); /*0x854820*/
          v686 = Packet::GetString(incoming, nullptr); /*0x854834*/
          v1027 = GameServerReceiver::UnpackPosition((GameServerReceiver *)v686, incoming, v687); /*0x854838*/
          v688 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x85484c*/
          if ( !v688 ) /*0x854850*/
            goto LABEL_1546; /*0x854850*/
          v167._dateData = (uint64_t)v688->nearby_players; /*0x854854*/
          if ( !v167._dateData ) /*0x854858*/
            goto LABEL_1546; /*0x854858*/
          v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x854878*/
                             (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                             v682,
                             MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::ContainsKey);
          if ( (v167._dateData & 1) != 0 ) /*0x85487c*/
          {
            v167._dateData = (uint64_t)TypeInfo::MobControl->static_fields->Instance; /*0x854890*/
            if ( !v167._dateData ) /*0x854894*/
              goto LABEL_1546; /*0x854894*/
            MobControl::SpawnNetMob((MobControl *)v167._dateData, v685, v1027, v686, nullptr); /*0x8548b0*/
          }
        }
        if ( !byte_27E6C85 ) /*0x8548bc*/
        {
          v167._dateData = sub_73C778(&TypeInfo::GameServerSender, v168); /*0x8548c4*/
          byte_27E6C85 = 1; /*0x8548cc*/
        }
        v689 = TypeInfo::GameServerSender->static_fields->Instance; /*0x8548d8*/
        if ( !v689 ) /*0x8548dc*/
          goto LABEL_1546; /*0x8548dc*/
        v167._dateData = (uint64_t)v689->other_players_mobs_that_I_inquired_about; /*0x8548e0*/
        if ( !v167._dateData ) /*0x8548e4*/
          goto LABEL_1546; /*0x8548e4*/
        System::Collections::Generic::List<System::Object>::Remove( /*0x8548f0*/
          (List_1_System_Object_ *)v167._dateData,
          v684,
          MethodInfo::System::Collections::Generic::List<System::String>::Remove);
        --v683; /*0x8548f4*/
      }
      while ( v683 ); /*0x8548f8*/
      return; /*0x8548f8*/
    case 68:
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr);// // case 0x45: UNKNOWN_0x45 /*0x854060*/
      v645 = TypeInfo::MobControl->static_fields->Instance; /*0x854074*/
      if ( !v645 ) /*0x854078*/
        goto LABEL_1546; /*0x854078*/
      v646 = (Object *)v167._dateData; /*0x85407c*/
      v167._dateData = (uint64_t)v645->active_combatants; /*0x854080*/
      if ( !v167._dateData ) /*0x854084*/
        goto LABEL_1546; /*0x854084*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x854098*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v646,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x85409c*/
        return; /*0x85409c*/
      v647 = TypeInfo::MobControl->static_fields->Instance; /*0x8540b0*/
      if ( !v647 ) /*0x8540b4*/
        goto LABEL_1546; /*0x8540b4*/
      v167._dateData = (uint64_t)v647->active_combatants; /*0x8540b8*/
      if ( !v167._dateData ) /*0x8540bc*/
        goto LABEL_1546; /*0x8540bc*/
      v648 = System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8540d8*/
               (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
               v646,
               MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x8540dc*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x8540e8*/
      v167._dateData = UnityEngine::Object::op_Equality((Object_1 *)v648, nullptr, nullptr); /*0x8540f8*/
      if ( (v167._dateData & 1) != 0 ) /*0x8540fc*/
        return; /*0x8540fc*/
      v649 = TypeInfo::MobControl->static_fields->Instance; /*0x854110*/
      if ( !v649 ) /*0x854114*/
        goto LABEL_1546; /*0x854114*/
      v167._dateData = (uint64_t)v649->active_combatants; /*0x85411c*/
      if ( !v167._dateData ) /*0x854124*/
        goto LABEL_1546; /*0x854124*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x854138*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v646,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !v167._dateData ) /*0x85413c*/
        goto LABEL_1546; /*0x85413c*/
      v650 = (GameObject *)v167._dateData; /*0x854144*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::get_transform((GameObject *)v167._dateData, nullptr); /*0x854148*/
      if ( !v167._dateData ) /*0x85414c*/
        goto LABEL_1546; /*0x85414c*/
      v1026 = UnityEngine::Transform::get_position((Transform *)v167._dateData, nullptr); /*0x854154*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::get_transform(v650, nullptr); /*0x85416c*/
      if ( !v167._dateData ) /*0x854170*/
        goto LABEL_1546; /*0x854170*/
      rotation = UnityEngine::Transform::get_rotation((Transform *)v167._dateData, nullptr); /*0x854178*/
      v167._dateData = (uint64_t)TypeInfo::MobControl->static_fields->Instance; /*0x85418c*/
      if ( !v167._dateData ) /*0x854190*/
        goto LABEL_1546; /*0x854190*/
      v651 = MobControl::ObjToCreatureStruct((MobControl *)v167._dateData, v650, nullptr); /*0x8541b4*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8541bc*/
                                   v650,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x8541c0*/
        goto LABEL_1546; /*0x8541c0*/
      SharedCreature::Delete((SharedCreature *)v167._dateData, nullptr); /*0x8541c8*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8541d4*/
                                   v650,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
      if ( !v167._dateData ) /*0x8541d8*/
        goto LABEL_1546; /*0x8541d8*/
      Combatant::Delete((Combatant *)v167._dateData, nullptr); /*0x8541e0*/
      gameObject = (Object_1 *)UnityEngine::GameObject::get_gameObject(v650, nullptr); /*0x8541f4*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x8541f8*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x854204*/
      UnityEngine::Object::Destroy(gameObject, nullptr); /*0x854210*/
      v167._dateData = (uint64_t)TypeInfo::MobControl->static_fields->Instance; /*0x854224*/
      if ( !v167._dateData ) /*0x854228*/
        goto LABEL_1546; /*0x854228*/
      v167._dateData = (uint64_t)MobControl::SpawnLocalMob((MobControl *)v167._dateData, v651, v1026, nullptr); /*0x854240*/
      if ( !v167._dateData ) /*0x854244*/
        goto LABEL_1546; /*0x854244*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::get_transform((GameObject *)v167._dateData, nullptr); /*0x85424c*/
      if ( !v167._dateData ) /*0x854250*/
        goto LABEL_1546; /*0x854250*/
      UnityEngine::Transform::set_rotation((Transform *)v167._dateData, rotation, nullptr); /*0x854268*/
      return; /*0x85426c*/
    case 69:
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr);// // case 0x46: ATTACK_ANIM /*0x8557e0*/
      v779 = TypeInfo::MobControl->static_fields->Instance; /*0x8557f4*/
      if ( !v779 ) /*0x8557f8*/
        goto LABEL_1546; /*0x8557f8*/
      v780 = (Object *)v167._dateData; /*0x8557fc*/
      v167._dateData = (uint64_t)v779->active_combatants; /*0x855800*/
      if ( !v167._dateData ) /*0x855804*/
        goto LABEL_1546; /*0x855804*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x855818*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v780,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x85581c*/
        return; /*0x85581c*/
      v781 = TypeInfo::MobControl->static_fields->Instance; /*0x855830*/
      if ( !v781 ) /*0x855834*/
        goto LABEL_1546; /*0x855834*/
      v167._dateData = (uint64_t)v781->active_combatants; /*0x85583c*/
      if ( !v167._dateData ) /*0x855844*/
        goto LABEL_1546; /*0x855844*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x855858*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v780,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !v167._dateData ) /*0x85585c*/
        goto LABEL_1546; /*0x85585c*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x855864*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x855868*/
        goto LABEL_1546; /*0x855868*/
      SharedCreature::VisuallyAttack((SharedCreature *)v167._dateData, nullptr); /*0x855870*/
      return; /*0x855874*/
    case 70:
      v738 = Packet::GetString(incoming, nullptr);// // case 0x47: HIT_MOB /*0x855164*/
      Packet::GetLong(incoming, nullptr); /*0x855170*/
      Packet::GetLong(incoming, nullptr); /*0x855180*/
      Packet::GetByte(incoming, nullptr); /*0x855190*/
      Packet::GetByte(incoming, nullptr); /*0x8551a0*/
      Packet::GetByte(incoming, nullptr); /*0x8551b0*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x8551c0*/
      if ( !TypeInfo::PlayerData->static_fields->Instance ) /*0x8551d4*/
        goto LABEL_1546; /*0x8551d4*/
      v739 = (Object *)v167._dateData; /*0x8551e4*/
      v740 = PlayerData::GetGlobalString( /*0x8551f4*/
               TypeInfo::PlayerData->static_fields->Instance,
               (String *)"username_lower",
               nullptr);
      v167._dateData = System::String::op_Equality(v738, v740, nullptr); /*0x855204*/
      v741 = TypeInfo::MobControl->static_fields->Instance; /*0x855224*/
      v742 = (v167._dateData & 1) != 0 ? (Object *)"LOCAL" : (Object *)v738;
      if ( !v741 ) /*0x855230*/
        goto LABEL_1546; /*0x855230*/
      v167._dateData = (uint64_t)v741->active_combatants; /*0x855234*/
      if ( !v167._dateData ) /*0x855238*/
        goto LABEL_1546; /*0x855238*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x85524c*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v742,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x855250*/
        return; /*0x855250*/
      v743 = TypeInfo::MobControl->static_fields->Instance; /*0x855264*/
      if ( !v743 ) /*0x855268*/
        goto LABEL_1546; /*0x855268*/
      v167._dateData = (uint64_t)v743->active_combatants; /*0x85526c*/
      if ( !v167._dateData ) /*0x855270*/
        goto LABEL_1546; /*0x855270*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x855284*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v739,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x855288*/
        goto LABEL_1560; /*0x855288*/
      v744 = TypeInfo::MobControl->static_fields->Instance; /*0x85529c*/
      if ( v744 ) /*0x8552a0*/
      {
        v167._dateData = (uint64_t)v744->active_combatants; /*0x8552a4*/
        if ( v167._dateData ) /*0x8552a8*/
        {
          System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8552bc*/
            (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
            v739,
            MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
LABEL_1560:
          JUMPOUT(0x861FD8); /*0x861fd8*/
        }
      }
      goto LABEL_1546; /*0x8552a8*/
    case 71:
      v761 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x48: MOB_DIE /*0x855530*/
      zonee = Packet::GetShort(incoming, nullptr); /*0x855540*/
      v994 = Packet::GetShort(incoming, nullptr); /*0x855550*/
      v762 = Packet::GetString(incoming, nullptr); /*0x855560*/
      v763 = Packet::GetShort(incoming, nullptr); /*0x855570*/
      v764 = Packet::GetShort(incoming, nullptr); /*0x855580*/
      v765 = Packet::GetShort(incoming, nullptr); /*0x855590*/
      v766 = Packet::GetShort(incoming, nullptr); /*0x8555a0*/
      stra = Packet::GetShort(incoming, nullptr); /*0x8555b0*/
      v767 = Packet::GetString(incoming, nullptr); /*0x8555c0*/
      v989 = Packet::GetByte(incoming, nullptr); /*0x8555d0*/
      v988 = Packet::GetByte(incoming, nullptr); /*0x8555e0*/
      incomingb = InventoryItem::UnpackFromWeb(incoming, nullptr); /*0x8555f4*/
      v768 = System::String::op_Equality(v762, (String *)"", nullptr); /*0x855610*/
      v167._dateData = (uint64_t)TypeInfo::PlayerData->static_fields->Instance; /*0x85561c*/
      if ( !v167._dateData ) /*0x855630*/
        goto LABEL_1546; /*0x855630*/
      v769 = PlayerData::GetGlobalString((PlayerData *)v167._dateData, (String *)"username_lower", nullptr); /*0x855644*/
      v167._dateData = System::String::op_Equality(v767, v769, nullptr); /*0x855654*/
      v770 = TypeInfo::MobControl->static_fields->Instance; /*0x855674*/
      v771 = (v167._dateData & 1) != 0 ? (Object *)"LOCAL" : (Object *)v767;
      if ( !v770 ) /*0x855680*/
        goto LABEL_1546; /*0x855680*/
      v167._dateData = (uint64_t)v770->active_combatants; /*0x855684*/
      if ( !v167._dateData ) /*0x855688*/
        goto LABEL_1546; /*0x855688*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x8556a0*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v761,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x8556a4*/
      {
        v847 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x856524*/
        if ( !v847 ) /*0x856528*/
          goto LABEL_1546; /*0x856528*/
        if ( v847->is_host_cached && (((unsigned __int16)(v764 | v763 | v765) | (unsigned __int16)v766) != 0 || !v768) ) /*0x856534*/
        {
          v848 = TypeInfo::QuestControl; /*0x856548*/
          if ( !TypeInfo::QuestControl->_1.cctor_finished_or_no_cctor ) /*0x85654c*/
          {
            j_il2cpp_runtime_class_init_0(TypeInfo::QuestControl); /*0x856554*/
            v848 = TypeInfo::QuestControl; /*0x856558*/
          }
          v167._dateData = (uint64_t)v848->static_fields->Instance; /*0x856560*/
          if ( !v167._dateData ) /*0x856564*/
            goto LABEL_1546; /*0x856564*/
          QuestControl::TryNoteQuestMobKilled( /*0x85659c*/
            (QuestControl *)v167._dateData,
            v762,
            v763,
            v764,
            v765,
            v766,
            incomingb,
            (String *)v761,
            nullptr);
          v167._dateData = (uint64_t)TypeInfo::QuestControl->static_fields->Instance; /*0x8565a8*/
          if ( !v167._dateData ) /*0x8565ac*/
            goto LABEL_1546; /*0x8565ac*/
          QuestControl::CheckIfAllQuestMobsKilled( /*0x8565d0*/
            (QuestControl *)v167._dateData,
            v762,
            v763,
            v764,
            v765,
            v766,
            incomingb,
            (String *)v761,
            nullptr);
        }
        return; /*0x8565d4*/
      }
      v772 = TypeInfo::MobControl->static_fields->Instance; /*0x8556b8*/
      if ( !v772 ) /*0x8556bc*/
        goto LABEL_1546; /*0x8556bc*/
      v167._dateData = (uint64_t)v772->active_combatants; /*0x8556c0*/
      if ( !v167._dateData ) /*0x8556c4*/
        goto LABEL_1546; /*0x8556c4*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x8556d8*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v771,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) != 0 ) /*0x8556dc*/
      {
        v773 = TypeInfo::MobControl->static_fields->Instance; /*0x8556f0*/
        if ( !v773 ) /*0x8556f4*/
          goto LABEL_1546; /*0x8556f4*/
        v167._dateData = (uint64_t)v773->active_combatants; /*0x8556f8*/
        if ( !v167._dateData ) /*0x8556fc*/
          goto LABEL_1546; /*0x8556fc*/
        v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x855710*/
                                     (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                     v771,
                                     MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
        v774 = (GameObject *)v167._dateData; /*0x855714*/
      }
      else
      {
        v774 = nullptr; /*0x857078*/
      }
      v897 = TypeInfo::MobControl->static_fields->Instance; /*0x85708c*/
      if ( !v897 ) /*0x857090*/
        goto LABEL_1546; /*0x857090*/
      v167._dateData = (uint64_t)v897->active_combatants; /*0x857094*/
      if ( !v167._dateData ) /*0x857098*/
        goto LABEL_1546; /*0x857098*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8570ac*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v761,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      v898 = (GameObject *)v167._dateData; /*0x8570b4*/
      if ( v989 == 1 ) /*0x8570c0*/
      {
        if ( !v167._dateData ) /*0x8570cc*/
          goto LABEL_1546; /*0x8570cc*/
        v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8570d8*/
                                     (GameObject *)v167._dateData,
                                     MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
        v899 = TypeInfo::PerkControl->static_fields->Instance; /*0x8570e4*/
        if ( !v899 || !v167._dateData ) /*0x8570ec*/
          goto LABEL_1546; /*0x8570ec*/
        p_prefab_darksword_kill = &v899->prefab_darksword_kill; /*0x8570f0*/
      }
      else
      {
        if ( v988 != 1 ) /*0x85710c*/
        {
          if ( !v167._dateData ) /*0x857e48*/
            goto LABEL_1546; /*0x857e48*/
          goto LABEL_1468; /*0x857e48*/
        }
        if ( !v167._dateData ) /*0x857110*/
          goto LABEL_1546; /*0x857110*/
        v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x85711c*/
                                     (GameObject *)v167._dateData,
                                     MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
        v901 = TypeInfo::PerkControl->static_fields->Instance; /*0x857128*/
        if ( !v901 || !v167._dateData ) /*0x857130*/
          goto LABEL_1546; /*0x857130*/
        p_prefab_darksword_kill = &v901->prefab_aether_banish; /*0x857134*/
      }
      Combatant::BeginDarkswordParticles((Combatant *)v167._dateData, *p_prefab_darksword_kill, nullptr); /*0x857140*/
LABEL_1468:
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x857e4c*/
                                   v898,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
      if ( !v167._dateData ) /*0x857e58*/
        goto LABEL_1546; /*0x857e58*/
      Combatant::Die((Combatant *)v167._dateData, v774, (float)zonee / 10.0, (float)v994 / 10.0, stra, nullptr); /*0x857e8c*/
      return; /*0x857e90*/
    case 73:
      v653 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x4A: CREATURE_STATS /*0x854290*/
      v654 = Packet::GetLong(incoming, nullptr); /*0x8542a0*/
      v655 = Packet::GetLong(incoming, nullptr); /*0x8542b0*/
      v656 = Packet::GetLong(incoming, nullptr); /*0x8542c0*/
      v167._dateData = Packet::GetLong(incoming, nullptr); /*0x8542cc*/
      v657 = TypeInfo::MobControl->static_fields->Instance; /*0x8542e0*/
      if ( !v657 ) /*0x8542e4*/
        goto LABEL_1546; /*0x8542e4*/
      v658 = v167._dateData; /*0x8542e8*/
      v167._dateData = (uint64_t)v657->active_combatants; /*0x8542ec*/
      if ( !v167._dateData ) /*0x8542f0*/
        goto LABEL_1546; /*0x8542f0*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x854304*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v653,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x854308*/
        return; /*0x854308*/
      v659 = TypeInfo::MobControl->static_fields->Instance; /*0x85431c*/
      if ( !v659 ) /*0x854320*/
        goto LABEL_1546; /*0x854320*/
      v167._dateData = (uint64_t)v659->active_combatants; /*0x854328*/
      if ( !v167._dateData ) /*0x854330*/
        goto LABEL_1546; /*0x854330*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x854344*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v653,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !v167._dateData ) /*0x854348*/
        goto LABEL_1546; /*0x854348*/
      v660 = (GameObject *)v167._dateData; /*0x854350*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x854354*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x854358*/
        goto LABEL_1546; /*0x854358*/
      v661 = *(_DWORD *)(v167._dateData + 152); /*0x854360*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x854368*/
                                   v660,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x85436c*/
        goto LABEL_1546; /*0x85436c*/
      *(_DWORD *)(v167._dateData + 152) = v654; /*0x854370*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x85437c*/
                                   v660,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
      if ( !v167._dateData ) /*0x854380*/
        goto LABEL_1546; /*0x854380*/
      *(_DWORD *)(v167._dateData + 40) = v655; /*0x854384*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x854390*/
                                   v660,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
      if ( !v167._dateData ) /*0x854394*/
        goto LABEL_1546; /*0x854394*/
      *(float *)(v167._dateData + 36) = (float)v656; /*0x85439c*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8543a8*/
                                   v660,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x8543ac*/
        goto LABEL_1546; /*0x8543ac*/
      *(_DWORD *)(v167._dateData + 160) = v658; /*0x8543b4*/
      if ( v654 == v661 ) /*0x8543b8*/
        return; /*0x8543b8*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8543cc*/
                                   v660,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x8543d0*/
        goto LABEL_1546; /*0x8543d0*/
      SharedCreature::ShowLevelupParticles((SharedCreature *)v167._dateData, 1, 0.0, nullptr); /*0x8543e0*/
      v662 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x8543f4*/
      if ( !v662 ) /*0x8543f8*/
        goto LABEL_1546; /*0x8543f8*/
      v167._dateData = (uint64_t)v662->nearby_players; /*0x8543fc*/
      if ( !v167._dateData ) /*0x854400*/
        goto LABEL_1546; /*0x854400*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x854414*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v653,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::ContainsKey);
      if ( (v167._dateData & 1) != 0 ) /*0x854418*/
      {
        v663 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x854424*/
        if ( !v663 ) /*0x854428*/
          goto LABEL_1546; /*0x854428*/
        v167._dateData = (uint64_t)v663->nearby_players; /*0x85442c*/
        if ( !v167._dateData ) /*0x854430*/
          goto LABEL_1546; /*0x854430*/
        v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x85443c*/
                                     (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                     v653,
                                     MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::get_Item);
        if ( !v167._dateData ) /*0x854440*/
          goto LABEL_1546; /*0x854440*/
        v664 = *(Object_1 **)(v167._dateData + 16); /*0x854448*/
        if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x85444c*/
          j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x854458*/
        v167._dateData = UnityEngine::Object::op_Inequality(v664, nullptr, nullptr); /*0x854468*/
        if ( (v167._dateData & 1) != 0 ) /*0x85446c*/
        {
          v665 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x854480*/
          if ( !v665 ) /*0x854484*/
            goto LABEL_1546; /*0x854484*/
          v167._dateData = (uint64_t)v665->nearby_players; /*0x85448c*/
          if ( !v167._dateData ) /*0x854494*/
            goto LABEL_1546; /*0x854494*/
          v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8544a0*/
                                       (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                       v653,
                                       MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::get_Item);
          if ( !v167._dateData ) /*0x8544a4*/
            goto LABEL_1546; /*0x8544a4*/
          v167._dateData = *(_QWORD *)(v167._dateData + 16); /*0x8544a8*/
          if ( !v167._dateData ) /*0x8544ac*/
            goto LABEL_1546; /*0x8544ac*/
          v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8544b4*/
                                       (GameObject *)v167._dateData,
                                       MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
          if ( !v167._dateData ) /*0x8544b8*/
            goto LABEL_1546; /*0x8544b8*/
          SharedCreature::RedrawMultiplayerOverhead((SharedCreature *)v167._dateData, (String *)v653, v654, nullptr); /*0x8544c8*/
        }
      }
      else
      {
        v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x857e34*/
                                     v660,
                                     MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
        if ( !v167._dateData ) /*0x857e38*/
          goto LABEL_1546; /*0x857e38*/
        SharedCreature::RedrawLevelText((SharedCreature *)v167._dateData, nullptr); /*0x857e40*/
      }
      return; /*0x8544cc*/
    case 74:
      v666 = Packet::GetString(incoming, nullptr);// // case 0x4B: INCREASE_HP /*0x8544e4*/
      v167._dateData = Packet::GetLong(incoming, nullptr); /*0x8544f0*/
      if ( !TypeInfo::PlayerData->static_fields->Instance ) /*0x854504*/
        goto LABEL_1546; /*0x854504*/
      v667 = v167._dateData; /*0x854514*/
      v668 = PlayerData::GetGlobalString( /*0x854524*/
               TypeInfo::PlayerData->static_fields->Instance,
               (String *)"username_lower",
               nullptr);
      v167._dateData = System::String::op_Equality(v666, v668, nullptr); /*0x854534*/
      v669 = TypeInfo::MobControl->static_fields->Instance; /*0x854554*/
      if ( (v167._dateData & 1) != 0 ) /*0x85455c*/
        v666 = (String *)"LOCAL"; /*0x85455c*/
      if ( !v669 ) /*0x854560*/
        goto LABEL_1546; /*0x854560*/
      v167._dateData = (uint64_t)v669->active_combatants; /*0x854564*/
      if ( !v167._dateData ) /*0x854568*/
        goto LABEL_1546; /*0x854568*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x85457c*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         (Object *)v666,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x854580*/
        return; /*0x854580*/
      v670 = TypeInfo::MobControl->static_fields->Instance; /*0x854594*/
      if ( !v670 ) /*0x854598*/
        goto LABEL_1546; /*0x854598*/
      v167._dateData = (uint64_t)v670->active_combatants; /*0x85459c*/
      if ( !v167._dateData ) /*0x8545a0*/
        goto LABEL_1546; /*0x8545a0*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8545b4*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   (Object *)v666,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !v167._dateData ) /*0x8545b8*/
        goto LABEL_1546; /*0x8545b8*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8545c0*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
      if ( !v167._dateData ) /*0x8545c4*/
        goto LABEL_1546; /*0x8545c4*/
      Combatant::IncreaseHp((Combatant *)v167._dateData, v667, nullptr); /*0x8545d0*/
      return; /*0x8545d4*/
    case 75:
      v306 = Packet::GetString(incoming, nullptr);// // case 0x4C: SHOW_EXP /*0x8511e0*/
      v1018 = GameServerReceiver::UnpackPosition((GameServerReceiver *)v306, incoming, v307); /*0x8511e4*/
      v308 = TypeInfo::GameController; /*0x8511fc*/
      if ( !TypeInfo::GameController->_1.cctor_finished_or_no_cctor ) /*0x851200*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::GameController); /*0x85120c*/
        v308 = TypeInfo::GameController; /*0x851210*/
      }
      v167._dateData = (uint64_t)v308->static_fields->Instance; /*0x851218*/
      if ( !v167._dateData ) /*0x85121c*/
        goto LABEL_1546; /*0x85121c*/
      GameController::showOverheadNotif((GameController *)v167._dateData, v306, v1018, 0, 0, nullptr); /*0x85123c*/
      return; /*0x851240*/
    case 77:
      v710 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x4E: COMPANION_EQUIP /*0x854bd0*/
      v711 = InventoryItem::UnpackFromWeb(incoming, nullptr); /*0x854be0*/
      v712 = InventoryItem::UnpackFromWeb(incoming, nullptr); /*0x854bf0*/
      v167._dateData = (uint64_t)InventoryItem::UnpackFromWeb(incoming, nullptr); /*0x854bfc*/
      v713 = TypeInfo::MobControl->static_fields->Instance; /*0x854c10*/
      if ( !v713 ) /*0x854c14*/
        goto LABEL_1546; /*0x854c14*/
      v714 = v167._dateData; /*0x854c18*/
      v167._dateData = (uint64_t)v713->active_combatants; /*0x854c1c*/
      if ( !v167._dateData ) /*0x854c20*/
        goto LABEL_1546; /*0x854c20*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x854c34*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v710,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x854c38*/
        return; /*0x854c38*/
      v715 = TypeInfo::MobControl->static_fields->Instance; /*0x854c4c*/
      if ( !v715 ) /*0x854c50*/
        goto LABEL_1546; /*0x854c50*/
      v167._dateData = (uint64_t)v715->active_combatants; /*0x854c54*/
      if ( !v167._dateData ) /*0x854c58*/
        goto LABEL_1546; /*0x854c58*/
      v716 = System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x854c74*/
               (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
               v710,
               MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x854c78*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x854c84*/
      v167._dateData = UnityEngine::Object::op_Inequality((Object_1 *)v716, nullptr, nullptr); /*0x854c94*/
      if ( (v167._dateData & 1) == 0 ) /*0x854c98*/
        return; /*0x854c98*/
      if ( !v716 ) /*0x854c9c*/
        goto LABEL_1546; /*0x854c9c*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x854ca8*/
                                   (GameObject *)v716,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
      if ( !v167._dateData ) /*0x854cac*/
        goto LABEL_1546; /*0x854cac*/
      if ( *(_DWORD *)(v167._dateData + 60) != 3 ) /*0x854cb8*/
        return; /*0x854cb8*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::get_gameObject((GameObject *)v716, nullptr); /*0x854cc4*/
      if ( !v167._dateData ) /*0x854cc8*/
        goto LABEL_1546; /*0x854cc8*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x854cd8*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x854cdc*/
        goto LABEL_1546; /*0x854cdc*/
      v717 = (SharedCreature *)v167._dateData; /*0x854ce4*/
      if ( !*(_BYTE *)(v167._dateData + 172) && *(_DWORD *)(v167._dateData + 184) == 6 ) /*0x854cf4*/
      {
        *(_QWORD *)(v167._dateData + 120) = v711; /*0x854cfc*/
        sub_73C72C(v167._dateData + 120); /*0x854d04*/
        v717->body_ = v712; /*0x854d0c*/
        sub_73C72C(&v717->body_); /*0x854d14*/
        v717->hand_ = (InventoryItem *)v714; /*0x854d1c*/
        sub_73C72C(&v717->hand_); /*0x854d24*/
        SharedCreature::OnEquipmentChanged(v717, nullptr); /*0x854d30*/
      }
      return; /*0x854d34*/
    case 78:
      v174 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x4F: RENAME_COMPANION /*0x84fbf8*/
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x84fc04*/
      v175 = TypeInfo::MobControl->static_fields->Instance; /*0x84fc18*/
      if ( !v175 ) /*0x84fc1c*/
        goto LABEL_1546; /*0x84fc1c*/
      v176 = (String *)v167._dateData; /*0x84fc20*/
      v167._dateData = (uint64_t)v175->active_combatants; /*0x84fc24*/
      if ( !v167._dateData ) /*0x84fc28*/
        goto LABEL_1546; /*0x84fc28*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x84fc3c*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v174,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x84fc40*/
        return; /*0x84fc40*/
      v177 = TypeInfo::MobControl->static_fields->Instance; /*0x84fc54*/
      if ( !v177 ) /*0x84fc58*/
        goto LABEL_1546; /*0x84fc58*/
      v167._dateData = (uint64_t)v177->active_combatants; /*0x84fc5c*/
      if ( !v167._dateData ) /*0x84fc60*/
        goto LABEL_1546; /*0x84fc60*/
      v178 = System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x84fc7c*/
               (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
               v174,
               MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x84fc80*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x84fc8c*/
      v167._dateData = UnityEngine::Object::op_Inequality((Object_1 *)v178, nullptr, nullptr); /*0x84fc9c*/
      if ( (v167._dateData & 1) == 0 ) /*0x84fca0*/
        return; /*0x84fca0*/
      if ( !v178 ) /*0x84fca4*/
        goto LABEL_1546; /*0x84fca4*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x84fcb0*/
                                   (GameObject *)v178,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
      if ( !v167._dateData ) /*0x84fcb4*/
        goto LABEL_1546; /*0x84fcb4*/
      if ( *(_DWORD *)(v167._dateData + 60) != 3 ) /*0x84fcc0*/
        return; /*0x84fcc0*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::get_gameObject((GameObject *)v178, nullptr); /*0x84fccc*/
      if ( !v167._dateData ) /*0x84fcd0*/
        goto LABEL_1546; /*0x84fcd0*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x84fce0*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x84fce4*/
        goto LABEL_1546; /*0x84fce4*/
      v179 = v167._dateData; /*0x84fcec*/
      if ( *(_BYTE *)(v167._dateData + 172) || *(_DWORD *)(v167._dateData + 184) != 6 ) /*0x84fcfc*/
        return; /*0x84fcfc*/
      v180 = *(_QWORD *)(v167._dateData + 32); /*0x84fd00*/
      if ( !v180 ) /*0x84fd04*/
        goto LABEL_1546; /*0x84fd04*/
      v181 = *(_QWORD *)(v180 + 24); /*0x84fd08*/
      if ( !v181 ) /*0x84fd0c*/
        goto LABEL_1546; /*0x84fd0c*/
      v167._dateData = *(_QWORD *)(v181 + 96); /*0x84fd10*/
      if ( !v167._dateData ) /*0x84fd14*/
        goto LABEL_1546; /*0x84fd14*/
      v182 = TypeInfo::MobControl->static_fields->Instance; /*0x84fd34*/
      v167._dateData = (uint64_t)System::Collections::Generic::List<System::Object>::get_Item( /*0x84fd38*/
                                   (List_1_System_Object_ *)v167._dateData,
                                   0,
                                   MethodInfo::System::Collections::Generic::List<System::String>::get_Item);
      v183 = *(_QWORD *)(v179 + 32); /*0x84fd3c*/
      if ( !v183 ) /*0x84fd40*/
        goto LABEL_1546; /*0x84fd40*/
      v184 = *(_QWORD *)(v183 + 24); /*0x84fd44*/
      if ( !v184 ) /*0x84fd48*/
        goto LABEL_1546; /*0x84fd48*/
      v185 = (String *)v167._dateData; /*0x84fd4c*/
      v167._dateData = *(_QWORD *)(v184 + 96); /*0x84fd50*/
      if ( !v167._dateData ) /*0x84fd54*/
        goto LABEL_1546; /*0x84fd54*/
      v186 = System::Collections::Generic::List<System::Object>::get_Item( /*0x84fd60*/
               (List_1_System_Object_ *)v167._dateData,
               1,
               MethodInfo::System::Collections::Generic::List<System::String>::get_Item);
      v167._dateData = (uint64_t)System::String::Concat(v185, (String *)v186, nullptr); /*0x84fd70*/
      if ( !v182 ) /*0x84fd74*/
        goto LABEL_1546; /*0x84fd74*/
      OverheadNameColor = MobControl::GetOverheadNameColor(v182, (String *)v167._dateData, nullptr); /*0xf1c0000000000010*/
      SharedCreature::AssignOverheadName((SharedCreature *)v179, v176, OverheadNameColor, nullptr); /*0x84fd94*/
      v187 = *(Object_1 **)(v179 + 56); /*0x84fd9c*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x84fda0*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x84fda8*/
      if ( !UnityEngine::Object::op_Inequality(v187, nullptr, nullptr) ) /*0x84fdbc*/
        goto LABEL_50; /*0x84fdbc*/
      v167._dateData = (uint64_t)TypeInfo::GameController; /*0x84fdc0*/
      if ( !TypeInfo::GameController->_1.cctor_finished_or_no_cctor ) /*0x84fdc4*/
      {
        j_il2cpp_runtime_class_init_0(TypeInfo::GameController); /*0x84fdcc*/
        v167._dateData = (uint64_t)TypeInfo::GameController; /*0x84fdd0*/
      }
      v188 = **(_QWORD **)(v167._dateData + 184); /*0x84fdd8*/
      if ( !v188 ) /*0x84fddc*/
        goto LABEL_1546; /*0x84fddc*/
      v167._dateData = *(_QWORD *)(v188 + 600); /*0x84fde0*/
      if ( !v167._dateData ) /*0x84fde4*/
        goto LABEL_1546; /*0x84fde4*/
      System::Collections::Generic::List<System::Object>::Remove( /*0x84fdf8*/
        (List_1_System_Object_ *)v167._dateData,
        *(Object **)(v179 + 56),
        MethodInfo::System::Collections::Generic::List<UnityEngine::GameObject>::Remove);
      v189 = *(Object_1 **)(v179 + 56); /*0x84fe00*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x84fe04*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x84fe0c*/
      UnityEngine::Object::Destroy(v189, nullptr); /*0x84fe18*/
LABEL_50:
      SharedCreature::RedrawLevelDisplay((SharedCreature *)v179, nullptr); /*0x84fe1c*/
      return; /*0x84fe28*/
    case 79:
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr);// // case 0x50: DESTROY_COMPANION /*0x85502c*/
      v732 = TypeInfo::MobControl->static_fields->Instance; /*0x855040*/
      if ( !v732 ) /*0x855044*/
        goto LABEL_1546; /*0x855044*/
      v733 = (Object *)v167._dateData; /*0x855048*/
      v167._dateData = (uint64_t)v732->active_combatants; /*0x85504c*/
      if ( !v167._dateData ) /*0x855050*/
        goto LABEL_1546; /*0x855050*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x855064*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v733,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x855068*/
        return; /*0x855068*/
      v734 = TypeInfo::MobControl->static_fields->Instance; /*0x85507c*/
      if ( !v734 ) /*0x855080*/
        goto LABEL_1546; /*0x855080*/
      v167._dateData = (uint64_t)v734->active_combatants; /*0x855084*/
      if ( !v167._dateData ) /*0x855088*/
        goto LABEL_1546; /*0x855088*/
      v735 = System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8550a4*/
               (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
               v733,
               MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x8550a8*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x8550b4*/
      v167._dateData = UnityEngine::Object::op_Inequality((Object_1 *)v735, nullptr, nullptr); /*0x8550c4*/
      if ( (v167._dateData & 1) == 0 ) /*0x8550c8*/
        return; /*0x8550c8*/
      if ( !v735 ) /*0x8550cc*/
        goto LABEL_1546; /*0x8550cc*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8550d8*/
                                   (GameObject *)v735,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>);
      if ( !v167._dateData ) /*0x8550dc*/
        goto LABEL_1546; /*0x8550dc*/
      if ( *(_DWORD *)(v167._dateData + 60) != 3 ) /*0x8550e8*/
        return; /*0x8550e8*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::get_gameObject((GameObject *)v735, nullptr); /*0x8550f4*/
      if ( !v167._dateData ) /*0x8550f8*/
        goto LABEL_1546; /*0x8550f8*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x855108*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x85510c*/
        goto LABEL_1546; /*0x85510c*/
      if ( *(_BYTE *)(v167._dateData + 172) || *(_DWORD *)(v167._dateData + 184) != 6 ) /*0x855120*/
        return; /*0x855120*/
      v736 = UnityEngine::GameObject::get_gameObject((GameObject *)v735, nullptr); /*0x855134*/
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x855138*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x855144*/
      v737 = (Object_1 *)v736; /*0x855148*/
      goto LABEL_1276; /*0x85514c*/
    case 80:
      v745 = Packet::GetString(incoming, nullptr);// // case 0x51: APPLY_PERK /*0x8552e4*/
      v746 = Packet::GetLong(incoming, nullptr); /*0x8552f4*/
      v747 = Packet::GetString(incoming, nullptr); /*0x855308*/
      v167._dateData = sub_73C88C(TypeInfo::PerkData); /*0x855310*/
      if ( !v167._dateData ) /*0x855314*/
        goto LABEL_1546; /*0x855314*/
      v748 = (PerkData *)v167._dateData; /*0x85531c*/
      PerkData::PerkData((PerkData *)v167._dateData, nullptr); /*0x855320*/
      PerkData::UnpackFromWeb(v748, incoming, nullptr); /*0x855330*/
      v749 = Packet::GetShort(incoming, nullptr); /*0x855340*/
      v750 = Packet::GetString(incoming, nullptr); /*0x855350*/
      v167._dateData = Packet::GetByte(incoming, nullptr); /*0x85535c*/
      if ( !TypeInfo::PlayerData->static_fields->Instance ) /*0x855368*/
        goto LABEL_1546; /*0x855368*/
      v751 = v167._dateData; /*0x855378*/
      v752 = PlayerData::GetGlobalString( /*0x855388*/
               TypeInfo::PlayerData->static_fields->Instance,
               (String *)"username_lower",
               nullptr);
      v167._dateData = System::String::op_Equality(v747, v752, nullptr); /*0x855398*/
      v753 = TypeInfo::MobControl->static_fields->Instance; /*0x8553b8*/
      if ( (v167._dateData & 1) != 0 ) /*0x8553c0*/
        v747 = (String *)"LOCAL"; /*0x8553c0*/
      if ( !v753 ) /*0x8553c4*/
        goto LABEL_1546; /*0x8553c4*/
      v167._dateData = (uint64_t)v753->active_combatants; /*0x8553c8*/
      if ( !v167._dateData ) /*0x8553cc*/
        goto LABEL_1546; /*0x8553cc*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x8553e0*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         (Object *)v747,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) != 0 ) /*0x8553e4*/
      {
        v754 = TypeInfo::MobControl->static_fields->Instance; /*0x8553f8*/
        if ( !v754 ) /*0x8553fc*/
          goto LABEL_1546; /*0x8553fc*/
        v167._dateData = (uint64_t)v754->active_combatants; /*0x855400*/
        if ( !v167._dateData ) /*0x855404*/
          goto LABEL_1546; /*0x855404*/
        v755 = System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x85541c*/
                 (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                 (Object *)v747,
                 MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      }
      else
      {
        v755 = nullptr; /*0x8564a0*/
      }
      if ( !TypeInfo::UnityEngine::Object->_1.cctor_finished_or_no_cctor ) /*0x8564a8*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Object); /*0x8564b0*/
      v167._dateData = UnityEngine::Object::op_Inequality((Object_1 *)v755, nullptr, nullptr); /*0x8564c0*/
      if ( (v167._dateData & 1) != 0 ) /*0x8564c4*/
      {
        if ( !v755 ) /*0x8564c8*/
          goto LABEL_1546; /*0x8564c8*/
        v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8564dc*/
                                     (GameObject *)v755,
                                     MethodInfo::UnityEngine::GameObject::GetComponent<PerkReceiver>);
        if ( !v167._dateData ) /*0x8564e0*/
          goto LABEL_1546; /*0x8564e0*/
        PerkReceiver::ApplyPerkEffect( /*0x85650c*/
          (PerkReceiver *)v167._dateData,
          v751 == 1,
          v750,
          v748,
          v749,
          v745,
          v746,
          0,
          nullptr);
      }
      return; /*0x856510*/
    case 81:
      if ( !TypeInfo::UnityEngine::Debug->_1.cctor_finished_or_no_cctor )// // case 0x52: LAUNCH_PERK /*0x8524c0*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Debug); /*0x8524cc*/
      UnityEngine::Debug::Log((Object *)"Received: launch projectile", nullptr);
      v167._dateData = sub_73C88C(TypeInfo::PerkData); /*0x8524e0*/
      if ( !v167._dateData ) /*0x8524e8*/
        goto LABEL_1546; /*0x8524e8*/
      v438 = (PerkData *)v167._dateData; /*0x8524f0*/
      PerkData::PerkData((PerkData *)v167._dateData, nullptr); /*0x8524f4*/
      PerkData::UnpackFromWeb(v438, incoming, nullptr); /*0x852504*/
      v439 = Packet::GetShort(incoming, nullptr); /*0x852514*/
      v440 = Packet::GetString(incoming, nullptr); /*0x852524*/
      v441 = Packet::GetString(incoming, nullptr); /*0x852534*/
      v442 = (GameServerReceiver *)Packet::GetLong(incoming, nullptr); /*0x852540*/
      v443 = (int)v442; /*0x852548*/
      v1021 = GameServerReceiver::UnpackPosition(v442, incoming, v444); /*0x85254c*/
      v1022 = GameServerReceiver::UnpackPosition(v445, incoming, v446); /*0x852560*/
      v167._dateData = (uint64_t)TypeInfo::PlayerData->static_fields->Instance; /*0x85256c*/
      if ( !v167._dateData ) /*0x852570*/
        goto LABEL_1546; /*0x852570*/
      v447 = PlayerData::GetGlobalString((PlayerData *)v167._dateData, (String *)"username_lower", nullptr); /*0x852590*/
      v167._dateData = System::String::op_Equality(v440, v447, nullptr); /*0x8525a0*/
      if ( !TypeInfo::PerkControl->static_fields->Instance ) /*0x8525ac*/
        goto LABEL_1546; /*0x8525b0*/
      if ( (v167._dateData & 1) != 0 ) /*0x8525d8*/
        v448 = (String *)"LOCAL"; /*0x8525d8*/
      else
        v448 = v440; /*0x8525d8*/
      PerkControl::LaunchProjectile( /*0x8525f8*/
        TypeInfo::PerkControl->static_fields->Instance,
        v438,
        v439,
        v448,
        v441,
        v443,
        v1021,
        v1022,
        nullptr);
      return; /*0x8525fc*/
    case 82:
      v775 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x53: QUICK_TAG /*0x85572c*/
      v167._dateData = Packet::GetByte(incoming, nullptr); /*0x855738*/
      v776 = TypeInfo::MobControl->static_fields->Instance; /*0x85574c*/
      if ( !v776 ) /*0x855750*/
        goto LABEL_1546; /*0x855750*/
      v777 = v167._dateData; /*0x855754*/
      v167._dateData = (uint64_t)v776->active_combatants; /*0x855758*/
      if ( !v167._dateData ) /*0x85575c*/
        goto LABEL_1546; /*0x85575c*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x855770*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v775,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x855774*/
        return; /*0x855774*/
      v778 = TypeInfo::MobControl->static_fields->Instance; /*0x855788*/
      if ( !v778 ) /*0x85578c*/
        goto LABEL_1546; /*0x85578c*/
      v167._dateData = (uint64_t)v778->active_combatants; /*0x855794*/
      if ( !v167._dateData ) /*0x85579c*/
        goto LABEL_1546; /*0x85579c*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x8557b0*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v775,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !v167._dateData ) /*0x8557b4*/
        goto LABEL_1546; /*0x8557b4*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x8557bc*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x8557c0*/
        goto LABEL_1546; /*0x8557c0*/
      *(_BYTE *)(v167._dateData + 82) = v777 == 1; /*0x8557d0*/
      return; /*0x8557d4*/
    case 83:
      v671 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x54: ALL_PERKS /*0x8545f0*/
      v672 = Packet::GetShort(incoming, nullptr); /*0x854600*/
      if ( v672 < 1 ) /*0x854608*/
        return; /*0x854608*/
      do /*0x85478c*/
      {
        v673 = Packet::GetString(incoming, nullptr); /*0x85461c*/
        v674 = Packet::GetLong(incoming, nullptr); /*0x854630*/
        v167._dateData = sub_73C88C(TypeInfo::PerkData); /*0x854638*/
        if ( !v167._dateData ) /*0x85463c*/
          goto LABEL_1546; /*0x85463c*/
        v675 = (PerkData *)v167._dateData; /*0x854644*/
        PerkData::PerkData((PerkData *)v167._dateData, nullptr); /*0x854648*/
        PerkData::UnpackFromWeb(v675, incoming, nullptr); /*0x854658*/
        v676 = Packet::GetShort(incoming, nullptr); /*0x854668*/
        v677 = Packet::GetString(incoming, nullptr); /*0x854678*/
        v678 = Packet::GetShort(incoming, nullptr); /*0x854688*/
        Packet::GetShort(incoming, nullptr); /*0x854694*/
        v167._dateData = (uint64_t)TypeInfo::PlayerData->static_fields->Instance; /*0x8546a0*/
        if ( !v167._dateData ) /*0x8546a4*/
          goto LABEL_1546; /*0x8546a4*/
        v679 = PlayerData::GetGlobalString((PlayerData *)v167._dateData, (String *)"username_lower", nullptr); /*0x8546b8*/
        v167._dateData = System::String::op_Equality(v673, v679, nullptr); /*0x8546c8*/
        v680 = TypeInfo::MobControl->static_fields->Instance; /*0x8546e8*/
        if ( (v167._dateData & 1) != 0 ) /*0x8546f0*/
          v673 = (String *)"LOCAL"; /*0x8546f0*/
        if ( !v680 ) /*0x8546f4*/
          goto LABEL_1546; /*0x8546f4*/
        v167._dateData = (uint64_t)v680->active_combatants; /*0x8546f8*/
        if ( !v167._dateData ) /*0x8546fc*/
          goto LABEL_1546; /*0x8546fc*/
        v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x854710*/
                           (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                           v671,
                           MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
        if ( (v167._dateData & 1) != 0 ) /*0x854714*/
        {
          v681 = TypeInfo::MobControl->static_fields->Instance; /*0x854728*/
          if ( !v681 ) /*0x85472c*/
            goto LABEL_1546; /*0x85472c*/
          v167._dateData = (uint64_t)v681->active_combatants; /*0x854730*/
          if ( !v167._dateData ) /*0x854734*/
            goto LABEL_1546; /*0x854734*/
          v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x854748*/
                                       (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                       v671,
                                       MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
          if ( !v167._dateData ) /*0x85474c*/
            goto LABEL_1546; /*0x85474c*/
          v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x85475c*/
                                       (GameObject *)v167._dateData,
                                       MethodInfo::UnityEngine::GameObject::GetComponent<PerkReceiver>);
          if ( !v167._dateData ) /*0x854760*/
            goto LABEL_1546; /*0x854760*/
          PerkReceiver::InitializeDurationTimer( /*0x854784*/
            (PerkReceiver *)v167._dateData,
            v678,
            v677,
            v675,
            v676,
            v673,
            v674,
            1,
            nullptr);
        }
        --v672; /*0x854788*/
      }
      while ( v672 ); /*0x85478c*/
      return; /*0x85478c*/
    case 84:
      v1017 = GameServerReceiver::UnpackPosition( /*0x84fe44*/
                (GameServerReceiver *)&MethodInfo::UnityEngine::GameObject::GetComponent<Combatant>,
                incoming,
                (MethodInfo *)&TypeInfo::Startup);// // case 0x55: CREATE_PERK_DROP
      v190 = Packet::GetString(incoming, nullptr); /*0x84fe64*/
      v167._dateData = sub_73C88C(TypeInfo::PerkData); /*0x84fe6c*/
      if ( !v167._dateData ) /*0x84fe70*/
        goto LABEL_1546; /*0x84fe70*/
      v191 = (PerkData *)v167._dateData; /*0x84fe80*/
      PerkData::PerkData((PerkData *)v167._dateData, nullptr); /*0x84fe84*/
      PerkData::UnpackFromWeb(v191, incoming, nullptr); /*0x84fe94*/
      v192 = Packet::GetShort(incoming, nullptr); /*0x84fea4*/
      v193 = Packet::GetString(incoming, nullptr); /*0x84feb4*/
      v194 = Packet::GetLong(incoming, nullptr); /*0x84fec8*/
      if ( !TypeInfo::UnityEngine::Debug->_1.cctor_finished_or_no_cctor ) /*0x84fecc*/
        j_il2cpp_runtime_class_init_0(TypeInfo::UnityEngine::Debug); /*0x84fed8*/
      UnityEngine::Debug::Log((Object *)"Got: Create Drop", nullptr);
      v167._dateData = (uint64_t)TypeInfo::PerkControl->static_fields->Instance; /*0x84fef0*/
      if ( !v167._dateData ) /*0x84fef4*/
        goto LABEL_1546; /*0x84fef4*/
      PerkControl::CreateDrop((PerkControl *)v167._dateData, v1017, v190, v191, v192, v193, v194, 0, nullptr); /*0x84ff20*/
      return; /*0x84ff24*/
    case 85:
      v276 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x56: RESPAWN /*0x850d1c*/
      v167._dateData = sub_73C88C(TypeInfo::OnlinePlayerData); /*0x850d24*/
      if ( !v167._dateData ) /*0x850d28*/
        goto LABEL_1546; /*0x850d28*/
      v277 = (OnlinePlayerData *)v167._dateData; /*0x850d30*/
      OnlinePlayerData::OnlinePlayerData((OnlinePlayerData *)v167._dateData, nullptr); /*0x850d34*/
      OnlinePlayerData::Unpack(v277, incoming, nullptr); /*0x850d44*/
      v278 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x850d58*/
      if ( !v278 ) /*0x850d5c*/
        goto LABEL_1546; /*0x850d5c*/
      v167._dateData = (uint64_t)v278->nearby_players; /*0x850d60*/
      if ( !v167._dateData ) /*0x850d64*/
        goto LABEL_1546; /*0x850d64*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x850d78*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v276,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x850d7c*/
        return; /*0x850d7c*/
      v279 = TypeInfo::MobControl->static_fields->Instance; /*0x850d90*/
      if ( !v279 ) /*0x850d94*/
        goto LABEL_1546; /*0x850d94*/
      v167._dateData = (uint64_t)v279->active_combatants; /*0x850d98*/
      if ( !v167._dateData ) /*0x850d9c*/
        goto LABEL_1546; /*0x850d9c*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x850db0*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v276,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) != 0 ) /*0x850db4*/
        return; /*0x850db4*/
      v280 = TypeInfo::GameServerInterface->static_fields->Instance; /*0x850dc8*/
      if ( !v280 ) /*0x850dcc*/
        goto LABEL_1546; /*0x850dcc*/
      v167._dateData = (uint64_t)v280->nearby_players; /*0x850dd0*/
      if ( !v167._dateData ) /*0x850dd4*/
        goto LABEL_1546; /*0x850dd4*/
      v281 = TypeInfo::MobControl->static_fields->Instance; /*0x850df0*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x850df4*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v276,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,OnlinePlayer>::get_Item);
      if ( !v281 ) /*0x850df8*/
        goto LABEL_1546; /*0x850df8*/
      MobControl::SpawnOtherPlayer(v281, (OnlinePlayer *)v167._dateData, v277, nullptr); /*0x850e0c*/
      return; /*0x850e10*/
    case 87:
      v598 = (Object *)Packet::GetString(incoming, nullptr);// // case 0x58: MOB_TARGET_SYNC /*0x853a38*/
      LOBYTE(v599) = Packet::GetByte(incoming, nullptr); /*0x853a50*/
      v167._dateData = sub_73C88C(TypeInfo::System::Collections::Generic::List<System::String>); /*0x853a5c*/
      if ( !v167._dateData ) /*0x853a60*/
        goto LABEL_1546; /*0x853a60*/
      v600 = v167._dateData; /*0x853a68*/
      System::Collections::Generic::List<System::Object>::List( /*0x853a6c*/
        (List_1_System_Object_ *)v167._dateData,
        MethodInfo::System::Collections::Generic::List<System::String>::List);
      v599 = (unsigned __int8)v599; /*0x853a70*/
      if ( !(_BYTE)v599 ) /*0x853a74*/
        goto LABEL_667; /*0x853a74*/
      do /*0x853ae4*/
      {
        v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr); /*0x853a80*/
        v601 = *(_QWORD *)(v600 + 16); /*0x853a88*/
        v602 = MethodInfo::System::Collections::Generic::List<System::String>::Add; /*0x853a8c*/
        ++*(_DWORD *)(v600 + 28); /*0x853a94*/
        if ( !v601 ) /*0x853a98*/
          goto LABEL_1546; /*0x853a98*/
        v603 = *(int *)(v600 + 24); /*0x853a9c*/
        v604 = v167._dateData; /*0x853aa4*/
        if ( (unsigned int)v603 >= *(_DWORD *)(v601 + 24) ) /*0x853aac*/
        {
          v167._dateData = (*((__int64 (__fastcall **)(uint64_t, uint64_t))v602->klass->rgctx_data[11].rgctxDataDummy + 1))( /*0x853adc*/
                             v600,
                             v167._dateData);
        }
        else
        {
          v605 = v601 + 8 * v603; /*0x853ab4*/
          *(_DWORD *)(v600 + 24) = v603 + 1; /*0x853ab8*/
          *(_QWORD *)(v605 + 32) = v604; /*0x853abc*/
          v167._dateData = sub_73C72C(v605 + 32); /*0x853ac0*/
        }
        --v599; /*0x853ae0*/
      }
      while ( v599 ); /*0x853ae4*/
LABEL_667:
      v606 = TypeInfo::MobControl->static_fields->Instance; /*0x853ae8*/
      if ( !v606 ) /*0x853afc*/
        goto LABEL_1546; /*0x853afc*/
      v167._dateData = (uint64_t)v606->active_combatants; /*0x853b00*/
      if ( !v167._dateData ) /*0x853b04*/
        goto LABEL_1546; /*0x853b04*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x853b18*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v598,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x853b1c*/
        return; /*0x853b1c*/
      v607 = TypeInfo::MobControl->static_fields->Instance; /*0x853b30*/
      if ( !v607 ) /*0x853b34*/
        goto LABEL_1546; /*0x853b34*/
      v167._dateData = (uint64_t)v607->active_combatants; /*0x853b3c*/
      if ( !v167._dateData ) /*0x853b44*/
        goto LABEL_1546; /*0x853b44*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x853b58*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v598,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,UnityEngine::GameObject>::get_Item);
      if ( !v167._dateData ) /*0x853b5c*/
        goto LABEL_1546; /*0x853b5c*/
      v167._dateData = (uint64_t)UnityEngine::GameObject::GetComponent<System::Object>( /*0x853b64*/
                                   (GameObject *)v167._dateData,
                                   MethodInfo::UnityEngine::GameObject::GetComponent<SharedCreature>);
      if ( !v167._dateData ) /*0x853b68*/
        goto LABEL_1546; /*0x853b68*/
      *(_QWORD *)(v167._dateData + 176) = v600; /*0x853b6c*/
      v419 = v167._dateData + 176; /*0x853b6c*/
      goto LABEL_871; /*0x853b74*/
    case 89:
      v167._dateData = (uint64_t)Packet::GetString(incoming, nullptr);// // case 0x5A: BANDIT_FLAG_DEST /*0x84ff38*/
      v195 = TypeInfo::BanditCampsControl->static_fields->Instance; /*0x84ff4c*/
      if ( !v195 ) /*0x84ff50*/
        goto LABEL_1546; /*0x84ff50*/
      v196 = (Object *)v167._dateData; /*0x84ff54*/
      v167._dateData = (uint64_t)v195->loaded_bandit_camp_instances; /*0x84ff58*/
      if ( !v167._dateData ) /*0x84ff5c*/
        goto LABEL_1546; /*0x84ff5c*/
      v167._dateData = System::Collections::Generic::Dictionary<System::Object,System::Object>::ContainsKey( /*0x84ff68*/
                         (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                         v196,
                         MethodInfo::System::Collections::Generic::Dictionary<System::String,BanditCampInstance>::ContainsKey);
      if ( (v167._dateData & 1) == 0 ) /*0x84ff6c*/
        return; /*0x84ff6c*/
      v197 = TypeInfo::BanditCampsControl->static_fields->Instance; /*0x84ff78*/
      if ( !v197 ) /*0x84ff7c*/
        goto LABEL_1546; /*0x84ff7c*/
      v167._dateData = (uint64_t)v197->loaded_bandit_camp_instances; /*0x84ff84*/
      if ( !v167._dateData ) /*0x84ff8c*/
        goto LABEL_1546; /*0x84ff8c*/
      v167._dateData = (uint64_t)System::Collections::Generic::Dictionary<System::Object,System::Object>::get_Item( /*0x84ffa0*/
                                   (Dictionary_2_System_Object_System_Object_ *)v167._dateData,
                                   v196,
                                   MethodInfo::System::Collections::Generic::Dictionary<System::String,BanditCampInstance>::get_Item);
      if ( !v167._dateData ) /*0x84ffa4*/
        goto LABEL_1546; /*0x84ffa4*/
      *(_BYTE *)(v167._dateData + 48) = 1; /*0x84ffac*/
      v198 = TypeInfo::GameServerConnector->static_fields->Instance; /*0x84ffb8*/
      if ( !v198 ) /*0x84ffbc*/
        goto LABEL_1546; /*0x84ffbc*/
      if ( v198->is_host_cached ) /*0x84ffc0*/
        BanditCampInstance::SaveToDisk((BanditCampInstance *)v167._dateData, nullptr); /*0x84ffcc*/
      return; /*0x84ffd0*/
    default:
      return;
  }
}