// Проект TextAnalyzer на F# с GUI - WPF

open System
open System.Windows

[<STAThread>]
[<EntryPoint>]
let main(_) =
    let app = Application()
    
    let window = 
        Application.LoadComponent(Uri("MainWindow.xaml", UriKind.Relative)) :?> Window
        |> MainWindow.initializeWindow

    app.MainWindow <- window
    window.Show()
    app.Run()