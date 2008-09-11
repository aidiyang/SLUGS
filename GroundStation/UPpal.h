//---------------------------------------------------------------------------

#ifndef UPpalH
#define UPpalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "tinyxml.h"
#include <ComCtrls.hpp>
#include "Placemnt.hpp"
#include <Buttons.hpp>
#include "ABSMain.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Dialogs.hpp>
#include <Mask.hpp>
#include "apDefinitions.h"
#include "protDecoder.h"
#include "AdPort.hpp"
#include "OoMisc.hpp"
#include "CircBuffer.h"
#include "_GClass.hpp"
#include "AbLED.hpp"
#include "AbOpHour.hpp"

//---------------------------------------------------------------------------
class TFPpal : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *StatusBar1;
    TPageControl *pc_main;
    TTabSheet *ts_ge;
    TTabSheet *ts_telemetry;
    TTabSheet *TabSheet3;
    TTabSheet *TabSheet1;
    TPanel *Panel1;
    TLabel *Label1;
    TMemo *mm_diagnose;
    TFormStorage *FormStorage1;
    TSpeedButton *bt_clear;
    TABSDatabase *ad_main;
    TABSTable *tb_config;
    TLabel *Label2;
    TDataSource *fte_config;
    TDBEdit *DBEdit1;
    TSpeedButton *bt_mainKml;
    TStringField *tb_configkmlFile;
    TStringField *tb_configplanePathFile;
    TSmallintField *tb_configupdateRate;
    TSmallintField *tb_configtessellate;
    TLabel *Label3;
    TDBEdit *DBEdit2;
    TSpeedButton *bt_ppKml;
    TDBRadioGroup *DBRadioGroup1;
    TDBCheckBox *DBCheckBox1;
    TSpeedButton *bt_gearth;
    TTimer *Timer1;
    TSaveDialog *od_mainKml;
    TBitBtn *BitBtn1;
    TColorBox *cb_color1;
    TLabel *Label4;
    TLabel *Label5;
    TColorBox *cb_color2;
    TTrackBar *kb_tessalate;
    TLabel *Label6;
    TLabel *Label7;
    TDBEdit *DBEdit3;
    TSpeedButton *bt_icon;
    TDBRadioGroup *DBRadioGroup2;
    TLabel *Label8;
    TDBEdit *bt_wp;
    TSpeedButton *SpeedButton3;
    TBitBtn *BitBtn2;
    TIntegerField *tb_configtrajectoryColorR;
    TIntegerField *tb_configtrajectoryColorG;
    TIntegerField *tb_configtrajectoryColorB;
    TSmallintField *tb_configtailLength;
    TIntegerField *tb_configtessalateColorR;
    TIntegerField *tb_configtessalateColorG;
    TIntegerField *tb_configtessalateColorB;
    TSmallintField *tb_configtessalateTransparency;
    TStringField *tb_configiconFile;
    TStringField *tb_configwaypointFile;
    TApdComPort *cp_serial;
    TSpeedButton *bt_serial;
    TAbLED *ld_serial;
    TTimer *Timer2;
    TGroupBox *GroupBox1;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label17;
    TLabel *Label18;
    TStaticText *et_date;
    TStaticText *et_time;
    TStaticText *et_lat;
    TStaticText *et_lon;
    TStaticText *et_height;
    TStaticText *et_sog;
    TStaticText *et_cog;
    TStaticText *et_hdop;
    TStaticText *et_fix;
    TStaticText *et_sats;
        void __fastcall FormShow(TObject *Sender);
    void __fastcall bt_clearClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall bt_ppKmlClick(TObject *Sender);
    void __fastcall bt_gearthClick(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall cb_color1Exit(TObject *Sender);
    void __fastcall cb_color2Exit(TObject *Sender);
    void __fastcall kb_tessalateExit(TObject *Sender);
    void __fastcall bt_serialClick(TObject *Sender);
    void __fastcall Timer2Timer(TObject *Sender);
    void __fastcall cp_serialTriggerAvail(TObject *CP, WORD Count);
    void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFPpal(TComponent* Owner);
        void createBlankKML(char KMLType);
        void updateKML(void);
        void addAndAppendNode(char* name, char* value, TiXmlNode* appendTo);
        unsigned char* getHexColor(unsigned char whichColor);       
        tGpsData gpsSamples[15];
//        CircBuffer mainSerial;
//        CBRef telemPort;
};
//---------------------------------------------------------------------------
extern PACKAGE TFPpal *FPpal;
//---------------------------------------------------------------------------
#endif