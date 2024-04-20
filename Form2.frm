VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   11865
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   19260
   LinkTopic       =   "Form2"
   Picture         =   "Form2.frx":0000
   ScaleHeight     =   11865
   ScaleWidth      =   19260
   StartUpPosition =   3  '系統預設值
   Begin VB.CommandButton Command1 
      Caption         =   "回首頁"
      BeginProperty Font 
         Name            =   "新細明體"
         Size            =   50.25
         Charset         =   136
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   2055
      Left            =   14160
      TabIndex        =   1
      Top             =   9240
      Width           =   4095
   End
   Begin VB.Label Label1 
      BackColor       =   &H8000000E&
      Caption         =   "本資料處理程式可以建立線段樹做資料結構，並可以進行單點修改、查詢指定區間和、指定區間乘積、指定區間最大值、指定區間最小值"
      BeginProperty Font 
         Name            =   "新細明體"
         Size            =   50.25
         Charset         =   136
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   8535
      Left            =   480
      TabIndex        =   0
      Top             =   360
      Width           =   13575
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Form2.Hide
Form1.Show
End Sub
