VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Form4"
   ClientHeight    =   11880
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   19275
   LinkTopic       =   "Form4"
   Picture         =   "Form4.frx":0000
   ScaleHeight     =   11880
   ScaleWidth      =   19275
   StartUpPosition =   3  '系統預設值
   Begin VB.CommandButton Command2 
      Caption         =   "首頁"
      Height          =   1455
      Left            =   10560
      TabIndex        =   2
      Top             =   9960
      Width           =   2775
   End
   Begin VB.CommandButton Command1 
      Caption         =   "上一頁"
      Height          =   1455
      Left            =   15840
      TabIndex        =   1
      Top             =   9840
      Width           =   2535
   End
   Begin VB.PictureBox Picture1 
      Height          =   8295
      Left            =   6600
      Picture         =   "Form4.frx":A50AD
      ScaleHeight     =   8235
      ScaleWidth      =   11835
      TabIndex        =   0
      Top             =   600
      Width           =   11895
   End
   Begin VB.Label Label1 
      BackColor       =   &H8000000E&
      Caption         =   $"Form4.frx":BDA8C
      BeginProperty Font 
         Name            =   "新細明體"
         Size            =   69.75
         Charset         =   136
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   5655
      Left            =   2280
      TabIndex        =   3
      Top             =   1800
      Width           =   1455
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Form4.Hide
Form3.Show
End Sub

Private Sub Command2_Click()
Form4.Hide
Form1.Show
End Sub
