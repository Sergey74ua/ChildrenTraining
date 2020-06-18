using UnityEngine;

public class MoveCube : MonoBehaviour
{
    [SerializeField]
    public GameObject MyCube;
    float delta;

    void Start()
    {
        
    }

    void Update()
    {
        delta = Input.GetAxis("Horizontal") * 50;

        MyCube.transform.position = new Vector3(100 + delta, 20, 100);

        //Куб - красный
        if (Input.GetKeyUp(KeyCode.R))
            MyCube.GetComponent<Renderer>().material.color = Color.red;
        //Куб - зеленый
        else if (Input.GetKeyUp(KeyCode.G))
            MyCube.GetComponent<Renderer>().material.color = Color.green;
        //Куб - зеленый
        else if (Input.GetKeyUp(KeyCode.B))
            MyCube.GetComponent<Renderer>().material.color = Color.blue;

        //Куб - скрываем
        if (Input.GetKeyUp(KeyCode.Z) && MyCube != null)
            MyCube.SetActive(false);

        //Куб - показываем
        if (Input.GetKeyUp(KeyCode.X) && MyCube != null)
            MyCube.SetActive(true);

        //Куб - удаляем
        if (Input.GetKeyUp(KeyCode.Escape))
            Destroy(MyCube);
    }
}