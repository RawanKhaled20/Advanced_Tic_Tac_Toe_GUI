object Form7: TForm7
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Form7'
  ClientHeight = 289
  ClientWidth = 527
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 132
    Height = 28
    Caption = 'Reset Password'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 72
    Width = 99
    Height = 19
    Caption = 'Username/Email'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 272
    Top = 134
    Width = 142
    Height = 19
    Caption = 'Confirm New Password'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 272
    Top = 72
    Width = 89
    Height = 19
    Caption = 'New Password'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object SpeedButton2: TSpeedButton
    Left = 463
    Top = 92
    Width = 34
    Height = 28
    OnClick = SpeedButton2Click
  end
  object SpeedButton1: TSpeedButton
    Left = 463
    Top = 154
    Width = 34
    Height = 28
    OnClick = SpeedButton1Click
  end
  object Label5: TLabel
    Left = 24
    Top = 137
    Width = 66
    Height = 15
    Caption = 'PIN Number'
  end
  object Edit1: TEdit
    Left = 24
    Top = 97
    Width = 185
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 272
    Top = 97
    Width = 185
    Height = 23
    TabOrder = 1
  end
  object Button1: TButton
    Left = 334
    Top = 225
    Width = 123
    Height = 33
    Caption = 'Confirm'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 24
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Back'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit3: TEdit
    Left = 272
    Top = 159
    Width = 185
    Height = 23
    TabOrder = 4
  end
  object Edit4: TEdit
    Left = 24
    Top = 158
    Width = 185
    Height = 23
    TabOrder = 5
  end
  object Button3: TButton
    Left = 24
    Top = 197
    Width = 113
    Height = 25
    Caption = 'Send PIN'
    TabOrder = 6
    OnClick = Button3Click
  end
  object EmployeeConnection: TFDConnection
    Params.Strings = (
      'ConnectionDef=EMPLOYEE')
    LoginPrompt = False
    Left = 194
    Top = 200
  end
  object UsersTable: TFDQuery
    Connection = EmployeeConnection
    SQL.Strings = (
      'SELECT * FROM USERS')
    Left = 242
    Top = 232
  end
end
