module TextAnalizer

open System
open System.Windows
open System.Windows.Controls

[<STAThread>]
[<EntryPoint>]
let main(_) =
    
    let textBox = TextBox()
    textBox.Width <- 500
    textBox.Height <- 300

    let btnEnter = Button()
    btnEnter.Width <- 200
    btnEnter.Height <- 40
    btnEnter.Content  <- "Ввод текста"
    btnEnter.Click.Add(fun _ ->
        textBox.Text <- "Hello world!"
    )

    let btnClear = Button()
    btnClear.Width <- 200
    btnClear.Height <- 40
    btnClear.Content  <- "Очистить текст"
    btnClear.Click.Add(fun _ ->
        textBox.Text <- ""
    )

    let layout = StackPanel()
    layout.Children.Add(textBox) |> ignore
    layout.Children.Add(btnEnter) |> ignore
    layout.Children.Add(btnClear) |> ignore

    let grid = Grid()
    grid.Children.Add(layout) |> ignore

    let window = Window()
    window.Title <- "Text analizer"
    window.Visibility <- Visibility.Visible
    window.Width <- 640
    window.Height <- 480
    window.Content <- grid

    let app = Application()
    app.MainWindow <- window
    app.Run()