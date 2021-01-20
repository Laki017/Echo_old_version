object Form2: TForm2
  Left = 0
  Top = 3
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderStyle = bsNone
  Caption = #1058#1077#1083#1077#1082' '#1051#1077#1075#1077#1085#1076#1099
  ClientHeight = 766
  ClientWidth = 1012
  Color = clBackground
  Enabled = False
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 0
    Width = 1000
    Height = 761
    Color = clBackground
    TabOrder = 0
  end
  object MediaPlayer1: TMediaPlayer
    Left = 328
    Top = 0
    Width = 29
    Height = 20
    VisibleButtons = []
    Display = Panel1
    Visible = False
    TabOrder = 1
    OnNotify = MediaPlayer1Notify
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 1009
    Height = 761
    Color = clBlack
    TabOrder = 2
    Visible = False
    object Label1: TLabel
      Left = 32
      Top = 184
      Width = 3
      Height = 14
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'Continuum Medium'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
  end
end
