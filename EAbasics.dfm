object Form1: TForm1
  Left = 239
  Top = -2
  BorderStyle = bsSingle
  Caption = 'EA-Basic'
  ClientHeight = 282
  ClientWidth = 905
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 40
    Width = 33
    Height = 13
    Caption = 'Lenght'
  end
  object Label2: TLabel
    Left = 8
    Top = 64
    Width = 50
    Height = 13
    Caption = 'Population'
  end
  object Label3: TLabel
    Left = 8
    Top = 88
    Width = 41
    Height = 13
    Caption = 'Cr. Porb.'
  end
  object Label4: TLabel
    Left = 8
    Top = 112
    Width = 49
    Height = 13
    Caption = 'Mut. Prob.'
  end
  object Label5: TLabel
    Left = 8
    Top = 136
    Width = 57
    Height = 13
    Caption = 'Generations'
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 105
    Height = 25
    Caption = 'Solve'
    TabOrder = 0
    OnClick = Button1Click
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 200
    Width = 889
    Height = 73
    ColCount = 42
    DefaultColWidth = 20
    DefaultRowHeight = 20
    RowCount = 3
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 72
    Top = 40
    Width = 41
    Height = 21
    TabOrder = 2
    Text = '40'
  end
  object Edit2: TEdit
    Left = 72
    Top = 64
    Width = 41
    Height = 21
    TabOrder = 3
    Text = '20'
  end
  object Edit3: TEdit
    Left = 72
    Top = 88
    Width = 41
    Height = 21
    TabOrder = 4
    Text = '0,80'
  end
  object Edit4: TEdit
    Left = 72
    Top = 112
    Width = 41
    Height = 21
    TabOrder = 5
    Text = '0,30'
  end
  object GroupBox1: TGroupBox
    Left = 120
    Top = 8
    Width = 273
    Height = 185
    Caption = 'Selection Mechanisms'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    object RadioButton1: TRadioButton
      Left = 8
      Top = 56
      Width = 113
      Height = 17
      Caption = 'Sigma scaling'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 88
      Width = 153
      Height = 17
      Caption = 'Boltzmann scaling         T='
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = True
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 8
      Top = 120
      Width = 113
      Height = 17
      Caption = 'Rank selection'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object Edit5: TEdit
      Left = 160
      Top = 88
      Width = 33
      Height = 21
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = '3'
    end
    object RadioButton4: TRadioButton
      Left = 8
      Top = 152
      Width = 217
      Height = 17
      Caption = 'Tournament selection    K=                 E='
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = RadioButton4Click
    end
    object Edit6: TEdit
      Left = 160
      Top = 152
      Width = 33
      Height = 21
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      Text = '2'
    end
    object Edit7: TEdit
      Left = 224
      Top = 152
      Width = 33
      Height = 21
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      Text = '0,7'
    end
    object RadioButton10: TRadioButton
      Left = 8
      Top = 24
      Width = 161
      Height = 17
      Caption = 'Fitness Proportionate scaling'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = RadioButton10Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 400
    Top = 8
    Width = 177
    Height = 113
    Caption = 'Selection Protocols'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    object RadioButton5: TRadioButton
      Left = 8
      Top = 24
      Width = 161
      Height = 17
      Caption = 'Full generational replacement'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object RadioButton6: TRadioButton
      Left = 8
      Top = 56
      Width = 113
      Height = 17
      Caption = 'Over Production'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = True
    end
    object RadioButton7: TRadioButton
      Left = 8
      Top = 88
      Width = 113
      Height = 17
      Caption = 'Generational Mixing'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object Edit8: TEdit
    Left = 72
    Top = 136
    Width = 41
    Height = 21
    TabOrder = 8
    Text = '100'
  end
  object Button2: TButton
    Left = 400
    Top = 136
    Width = 177
    Height = 25
    Caption = 'Plot'
    Enabled = False
    TabOrder = 9
    OnClick = Button2Click
  end
  object GroupBox3: TGroupBox
    Left = 584
    Top = 8
    Width = 153
    Height = 113
    Caption = 'Problems'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 10
    object RadioButton8: TRadioButton
      Left = 8
      Top = 24
      Width = 113
      Height = 17
      Caption = 'The one-max problem'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = True
    end
    object RadioButton9: TRadioButton
      Left = 8
      Top = 56
      Width = 137
      Height = 17
      Caption = 'Random bit target vector'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
  end
end
