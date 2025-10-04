// Program.fs
(*
    Project:
        TextAnalyzer - Text Analysis Application
    
    Description:
        Приложение для идентификации авторства текста
    
    Technical Stack:
        Language: F#
        Framework: .NET 8.0
        GUI: WPF
        IDE: Visual Studio 2022
    
    Author: Максим Покидько
    University: КФУ ФТИ ПИ
    Version: 1.0.0
    Created: 2025-10-05
*)

open System
open System.Windows


[<STAThread>]
[<EntryPoint>]
let main(_) =
    let app = Application()

    let window = 
        Uri("MainWindow.xaml", UriKind.Relative)
        |> Application.LoadComponent
        :?> Window
        |> MainWindow.initializeWindow

    app.MainWindow <- window
    window.Show()
    app.Run()