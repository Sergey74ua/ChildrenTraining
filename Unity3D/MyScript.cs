using UnityEngine;

public class MyScript : MonoBehaviour
{
    [SerializeField]
    public int x, y;

    //Функции обрабатываемые до запуска
    private void Awake()
    {
        print("Hello world");
    }

    //Функции обрабатываемые при запуске
    void Start()
    {
        print("Hello world!");
    }

    //Функции обрабатываемые при смене кадра
    void Update()
    {
        //MyFunction();
    }

    //Функции обрабатываемые по таймеру
    void FixedUpdate()
    {
        //print(y++ + " Время по таймеру " + Time.deltaTime);
    }

    //Пользовательская функция
    void MyFunction()
    {
        print(x++ + " Время по кадру " + Time.deltaTime);
    }
}