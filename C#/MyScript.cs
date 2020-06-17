using System;
using UnityEngine;
using UnityEngine.UI;

public class MyScript : MonoBehaviour
{
    [SerializeField]
    private Light MyLight;
    public int x, y;

    public GameObject MyCube;

    //Функции обрабатываемые до запуска
    private void Awake()
    {
        //print("Hello world");
    }

    //Функции обрабатываемые при запуске
    void Start()
    {
        MyLight = GetComponent<Light>();
    }

    //Функции обрабатываемые при смене кадра
    void Update()
    {
        MyFunction();

        //Включаем / выключаем свет
        if (Input.GetKeyUp(KeyCode.Space))
            MyLight.enabled = !MyLight.enabled;

        //Куб - скрываем
        if (Input.GetKeyUp(KeyCode.W) && MyCube != null)
            MyCube.SetActive(false);

        //Куб - показываем
        if (Input.GetKeyUp(KeyCode.S) && MyCube != null)
            MyCube.SetActive(true);

        //Куб - удаляем
        if (Input.GetKeyUp(KeyCode.Q) && MyCube != null)
            Destroy (MyCube);

        //Куб - красный
        if (Input.GetKeyUp(KeyCode.R) && MyCube != null)
            MyCube.GetComponent <Renderer>().material.color = Color.red;

        //Куб - желтый
        if (Input.GetKeyUp(KeyCode.E) && MyCube != null)
            MyCube.GetComponent<Renderer>().material.color = Color.yellow;
    }

    void FixedUpdate()
    {
        //print(y++ + " Время " + Time.deltaTime);
    }

    void MyFunction()
    {
        print(x++ + " Время " + Time.deltaTime);
    }
}