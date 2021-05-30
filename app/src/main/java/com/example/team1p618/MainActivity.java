package com.example.team1p618;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.jjoe64.graphview.Viewport;
import com.jjoe64.graphview.helper.GraphViewXML;
import com.jjoe64.graphview.series.DataPoint;
import com.jjoe64.graphview.GraphView;
import com.jjoe64.graphview.series.Series;


public class MainActivity extends AppCompatActivity {
    private FirebaseDatabase myRef;
    private GraphViewXML speedGraph;
    private View b_voltage;
    private View range;
    private View temperature;
    private View acceleration;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        FirebaseDatabase.getInstance();
        myRef = new FirebaseDatabase("team-1p618-99e8f.firebaseio.com");
        speedGraph = (GraphViewXML) findViewById(R.id.sGraph);
        acceleration = (View) findViewById(R.id.Acceleration);
        range = (View) findViewById(R.id.Temperature);
        temperature = (View) findViewById(R.id.Range);
        b_voltage = (View) findViewById(R.id.BatteryVoltage);
        Button aGraph = (Button) findViewById(R.id.aGraph);
        Button tGraph = (Button) findViewById(R.id.tGraph);
        Button rGraph = (Button) findViewById(R.id.rGraph);
        Button vGraph = (Button) findViewById(R.id.vGraph);

        speedGraph.setOnClickListener(new View.OnClickListener() {
                                          @Override
                                          public void onClick(View view) {
                                              FirebaseDatabase database = FirebaseDatabase.getInstance();
                                              DatabaseReference myRef = database.getReference("Team 1.618");
                                              myRef.setValue("Speed");
                                              GraphView graph = (GraphView) findViewById(R.id.sGraph);
                                              Series<DataPoint> series = new Series <~>(myRef);
                                              graph.addSeries((Series) speedGraph);
                                              Viewport viewport = graph.getViewport();
                                              viewport.setYAxisBoundsManual(true);
                                              viewport.setMinX(0);
                                              viewport.setScrollable(true);
                                          }
                                      }
        );
    }

}




