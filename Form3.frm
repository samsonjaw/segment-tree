VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Form3"
   ClientHeight    =   12000
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   19200
   BeginProperty Font 
      Name            =   "新細明體"
      Size            =   35.25
      Charset         =   136
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form3"
   Picture         =   "Form3.frx":0000
   ScaleHeight     =   12000
   ScaleWidth      =   19200
   StartUpPosition =   3  '系統預設值
   Begin VB.CommandButton Command2 
      Caption         =   "首頁"
      BeginProperty Font 
         Name            =   "新細明體"
         Size            =   9
         Charset         =   136
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1695
      Left            =   11160
      TabIndex        =   1
      Top             =   9960
      Width           =   3495
   End
   Begin VB.CommandButton Command1 
      Caption         =   "下一頁"
      BeginProperty Font 
         Name            =   "新細明體"
         Size            =   9
         Charset         =   136
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1695
      Left            =   15360
      TabIndex        =   0
      Top             =   9960
      Width           =   3375
   End
   Begin VB.Label Label1 
      Caption         =   $"Form3.frx":A50AD
      BeginProperty Font 
         Name            =   "新細明體"
         Size            =   33
         Charset         =   136
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   8295
      Left            =   120
      TabIndex        =   2
      Top             =   360
      Width           =   19095
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Form3.Hide
Form4.Show
End Sub

Private Sub Command2_Click()
Form3.Hide
Form1.Show
End Sub

