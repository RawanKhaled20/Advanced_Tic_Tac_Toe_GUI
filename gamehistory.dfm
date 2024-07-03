object Form6: TForm6
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Form6'
  ClientHeight = 446
  ClientWidth = 463
  Color = clGradientActiveCaption
  CustomTitleBar.CaptionAlignment = taCenter
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 78
    Top = 119
    Width = 100
    Height = 20
    Caption = 'Game Number:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 78
    Top = 145
    Width = 70
    Height = 20
    Caption = 'Opponent:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 261
    Top = 119
    Width = 79
    Height = 20
    Caption = 'Played with:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 261
    Top = 145
    Width = 43
    Height = 20
    Caption = 'Status:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 233
    Top = 27
    Width = 3
    Height = 15
  end
  object Label6: TLabel
    Left = 400
    Top = 27
    Width = 3
    Height = 15
  end
  object Label7: TLabel
    Left = 201
    Top = 75
    Width = 3
    Height = 15
  end
  object Label8: TLabel
    Left = 379
    Top = 75
    Width = 3
    Height = 15
  end
  object Label9: TLabel
    Left = 40
    Top = 48
    Width = 383
    Height = 20
    Caption = 'Enter the Game Number You would like to show its history'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 184
    Top = 119
    Width = 3
    Height = 20
    Caption = '.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label11: TLabel
    Left = 315
    Top = 145
    Width = 3
    Height = 20
    Caption = '.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label12: TLabel
    Left = 154
    Top = 145
    Width = 3
    Height = 20
    Caption = '.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label13: TLabel
    Left = 346
    Top = 119
    Width = 3
    Height = 20
    Caption = '.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label14: TLabel
    Left = 151
    Top = 22
    Width = 76
    Height = 20
    Caption = 'You Played '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label15: TLabel
    Left = 304
    Top = 22
    Width = 45
    Height = 20
    Caption = 'Games'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label16: TLabel
    Left = 54
    Top = 22
    Width = 69
    Height = 20
    Caption = 'Press here:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 125
    Top = 184
    Width = 62
    Height = 49
    TabOrder = 0
  end
  object Button2: TButton
    Left = 193
    Top = 184
    Width = 62
    Height = 49
    TabOrder = 1
  end
  object Button3: TButton
    Left = 261
    Top = 184
    Width = 62
    Height = 49
    TabOrder = 2
  end
  object Button4: TButton
    Left = 125
    Top = 239
    Width = 62
    Height = 49
    TabOrder = 3
  end
  object Button5: TButton
    Left = 193
    Top = 239
    Width = 62
    Height = 49
    TabOrder = 4
  end
  object Button6: TButton
    Left = 261
    Top = 239
    Width = 62
    Height = 49
    TabOrder = 5
  end
  object Button7: TButton
    Left = 125
    Top = 294
    Width = 62
    Height = 49
    TabOrder = 6
  end
  object Button8: TButton
    Left = 193
    Top = 294
    Width = 62
    Height = 49
    TabOrder = 7
  end
  object Button9: TButton
    Left = 261
    Top = 294
    Width = 62
    Height = 49
    TabOrder = 8
  end
  object Button10: TButton
    Left = 170
    Top = 80
    Width = 85
    Height = 33
    Caption = 'Show '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button10Click
  end
  object ButtonPrevious: TButton
    Left = 76
    Top = 360
    Width = 108
    Height = 25
    Caption = 'Previous Move'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = ButtonPreviousClick
  end
  object ButtonNext: TButton
    Left = 261
    Top = 360
    Width = 109
    Height = 25
    Caption = 'Next Move'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = ButtonNextClick
  end
  object Button11: TButton
    Left = 24
    Top = 405
    Width = 99
    Height = 25
    Caption = 'Back to Home'
    TabOrder = 12
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 329
    Top = 80
    Width = 44
    Height = 33
    Caption = '>'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 242
    Top = 19
    Width = 47
    Height = 23
    Caption = 'N'
    TabOrder = 14
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 272
    Top = 80
    Width = 46
    Height = 33
    Caption = '<'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = Button14Click
  end
  object ComboBox1: TComboBox
    Left = 96
    Top = 85
    Width = 52
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 16
    OnChange = ComboBox1Change
  end
  object EmployeeConnection: TFDConnection
    Params.Strings = (
      'ConnectionDef=EMPLOYEE')
    Connected = True
    LoginPrompt = False
    Left = 53
    Top = 256
  end
  object GameresultsTable: TFDQuery
    Active = True
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM GAMERESULTS')
    Left = 45
    Top = 320
  end
  object UsersTable: TFDQuery
    Active = True
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM USERS')
    Left = 36
    Top = 194
  end
end
