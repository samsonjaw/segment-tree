VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7590
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   11700
   LinkTopic       =   "Form1"
   Picture         =   "Form1.frx":0000
   ScaleHeight     =   7590
   ScaleWidth      =   11700
   StartUpPosition =   3  '¨t²Î¹w³]­È
   Begin VB.CommandButton Command3 
      Caption         =   "¶}©l¨Ï¥Î"
      Height          =   1575
      Left            =   8400
      TabIndex        =   3
      Top             =   3240
      Width           =   2655
   End
   Begin VB.CommandButton Command2 
      Caption         =   "½u¬q¾ð¤¶²Ð"
      Height          =   1575
      Left            =   4440
      TabIndex        =   2
      Top             =   3240
      Width           =   2655
   End
   Begin VB.CommandButton Command1 
      Caption         =   "¥\¯à¤¶²Ð"
      Height          =   1575
      Left            =   600
      TabIndex        =   1
      Top             =   3240
      Width           =   2655
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackColor       =   &H8000000E&
      Caption         =   "½u¬q¾ð¸ê®Æ³B²z¤u¨ã"
      BeginProperty Font 
         Name            =   "·s²Ó©úÅé"
         Size            =   60
         Charset         =   136
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1200
      Left            =   480
      TabIndex        =   0
      Top             =   480
      Width           =   10935
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Form1.Hide
Form2.Show
End Sub

Private Sub Command2_Click()
Form1.Hide
Form3.Show
End Sub

Private Sub Command3_Click()
RetVal = Shell("segment_tree.exe", 1)
End Sub
