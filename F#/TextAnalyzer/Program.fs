// Проект TextAnalyzer на F# с GUI - WPF

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