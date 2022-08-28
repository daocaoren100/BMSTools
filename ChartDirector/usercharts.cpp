#include "usercharts.h"
#include "chartdir.h"
#include "FinanceChart.h"


ANGULAR_METER_STRUCT roundmeterreadout_volt(int chartIndex)
{
    // The value to display on the meter
    double value = 0;
    ANGULAR_METER_STRUCT r;

    // The main color of the four meters in this example. The other colors and gradients are derived
    // from the main color.
    int mainColor = 0x873324;

    //
    // In this example, we demonstrate how to parameterized by size, so that the chart size can be
    // changed by changing just one variable.
    //
    int size = 200;

    // The radius of the entire meter, which is size / 2, minus 2 pixels for margin
    int outerRadius = size / 2 - 2;

    // The radius of the meter scale
    int scaleRadius = outerRadius * 92 / 100;

    // The radius of the color scale
    int colorScaleRadius = scaleRadius * 43 / 100;

    // The width of the color scale
    int colorScaleWidth = scaleRadius * 10 / 100;

    // Major tick length
    int tickLength = scaleRadius * 10 / 100;

    // Major tick width
    int tickWidth = scaleRadius * 1 / 100 + 1;

    // Label font size
    int fontSize = scaleRadius * 13 / 100;

    // Radius of readout circle as a ratio to the scale radius
    double readOutRadiusRatio = 0.333333333333;

    // Readout font size
    int readOutFontSize = scaleRadius * 24 / 100;

    //
    // Create an angular meter based on the above parameters
    //

    // Create an AngularMeter object of the specified size. In this demo, we use black (0x000000) as
    // the background color. You can also use transparent or other colors.
    AngularMeter *m = new AngularMeter(size, size, 0xffffff);

    // Set the default text and line colors to white (0xffffff)
    m->setColor(Chart::TextColor, 0xffffff);
    m->setColor(Chart::LineColor, 0xffffff);

    // Set meter center and scale radius, and set the scale angle from -180 to +90 degrees
    m->setMeter(size / 2, size / 2, scaleRadius, -140, 140);


    // Background gradient with the mainColor at the center and become darker near the border
    double bgGradient[] = {0, mainColor, 0.5, m->adjustBrightness(mainColor, 0.75), 1,
        m->adjustBrightness(mainColor, 0.15)};

    // Fill the meter background with the background gradient
    m->addRing(0, outerRadius, m->relativeRadialGradient(DoubleArray(bgGradient, (int)(sizeof(
        bgGradient) / sizeof(bgGradient[0]))), outerRadius * 0.66));

    // Gradient for the neon backlight, with the main color at the scale radius fading to
    // transparent
    double neonGradient[] = {0.89, Chart::Transparent, 1, mainColor, 1.07, Chart::Transparent};
    m->addRing(scaleRadius * 85 / 100, outerRadius, m->relativeRadialGradient(DoubleArray(
        neonGradient, (int)(sizeof(neonGradient) / sizeof(neonGradient[0])))));

    // The neon ring at the scale radius with width equal to 1/80 of the scale radius, creating
    // using a brighter version of the main color
    m->addRing(scaleRadius, scaleRadius + scaleRadius / 80, m->adjustBrightness(mainColor, 2));

    // ���ݷ�Χ
    double minData = 0;
    double maxData = 900;
    double major = maxData / 10;
    double minor = major / 2;
    double micro = minor / 2;
    // Meter scale is 0 - 900, with major/minor/micro ticks every 90/18/9 units
    m->setScale(minData, maxData, major, minor, micro);

    // Set the scale label style, tick length and tick width. The minor and micro tick lengths are
    // 80% and 60% of the major tick length, and their widths are around half of the major tick
    // width.
    m->setLabelStyle("ariali.ttf", fontSize);
    m->setTickLength(-tickLength, -tickLength * 80 / 100, -tickLength * 60 / 100);
    m->setLineWidth(0, tickWidth, tickWidth + 1 / 2, tickWidth + 1 / 2);

    // Demostrate different types of color scales and putting them at different positions.
    double smoothColorScale[] = {minData, 0x0000ff, (maxData - minData) * 0.25, 0x0088ff, (maxData - minData) * 0.5, 0x00ff00, (maxData - minData) * 0.75, 0xdddd00, maxData,
        0xff0000};
    double highColorScale[] = {70, Chart::Transparent, 100, 0xff0000};

    if (chartIndex == 0) {
        // Add the smooth color scale
        m->addColorScale(DoubleArray(smoothColorScale, (int)(sizeof(smoothColorScale) / sizeof(
            smoothColorScale[0]))), colorScaleRadius, colorScaleWidth);
        // Add a red (0xff0000) pointer
        r.p = m->addPointer2(value, 0xff0000);
    } else {
        // Add the high color scale at the default position
        m->addColorScale(DoubleArray(highColorScale, (int)(sizeof(highColorScale) / sizeof(
            highColorScale[0]))));
        // Add a red (0xff0000) triangular pointer starting from 40% and ending at 60% of scale
        // radius, with a width 6 times the default
        r.p = m->addPointer2(value, 0xff0000, -1, Chart::TriangularPointer2, 0.4, 0.6, 6);
    }

    // Configure a large "pointer cap" to be used as the readout circle at the center. The cap
    // border width is set to 1.5% of the scale radius. The cap color is darker version of the main
    // color. The border color is a brighter version of the main color with 75% brightness gradient
    // effect.
    m->setCap2(Chart::Transparent, m->adjustBrightness(mainColor, 0.3), m->adjustBrightness(
        mainColor, 1.5), 0.75, 0, readOutRadiusRatio, 0.015);

    // Add value label at the center using a brighter version of the main color and Arial Italic
    // font
    r.tb = m->addText(size / 2, size / 2, m->formatValue(value, "{value|0}"), "ariali.ttf",
        readOutFontSize, m->adjustBrightness(mainColor, 2.5), Chart::Center);
    r.tb->setMargin(0);

    // Add a text label centered at (125, 175) with 15pt Arial Italic font
    m->addText(size / 2, size * 4 / 5, "V", "ariali.ttf", 30, Chart::TextColor, Chart::Center);

    // Add glare up to the scale radius
    m->addGlare(scaleRadius);

    // Output the chart
    m->makeChart();

    r.b = m;
    return r;
}

ANGULAR_METER_STRUCT roundmeterreadout_current(int chartIndex)
{
    // The value to display on the meter
    double value = 0;
    ANGULAR_METER_STRUCT r;

    // The main color of the four meters in this example. The other colors and gradients are derived
    // from the main color.
    int mainColor = 0x873324;

    //
    // In this example, we demonstrate how to parameterized by size, so that the chart size can be
    // changed by changing just one variable.
    //
    int size = 200;

    // The radius of the entire meter, which is size / 2, minus 2 pixels for margin
    int outerRadius = size / 2 - 2;

    // The radius of the meter scale
    int scaleRadius = outerRadius * 92 / 100;

    // The radius of the color scale
    int colorScaleRadius = scaleRadius * 43 / 100;

    // The width of the color scale
    int colorScaleWidth = scaleRadius * 10 / 100;

    // Major tick length
    int tickLength = scaleRadius * 10 / 100;

    // Major tick width
    int tickWidth = scaleRadius * 1 / 100 + 1;

    // Label font size
    int fontSize = scaleRadius * 13 / 100;

    // Radius of readout circle as a ratio to the scale radius
    double readOutRadiusRatio = 0.333333333333;

    // Readout font size
    int readOutFontSize = scaleRadius * 24 / 100;

    //
    // Create an angular meter based on the above parameters
    //

    // Create an AngularMeter object of the specified size. In this demo, we use black (0x000000) as
    // the background color. You can also use transparent or other colors.
    AngularMeter *m = new AngularMeter(size, size, 0xffffff);

    // Set the default text and line colors to white (0xffffff)
    m->setColor(Chart::TextColor, 0xffffff);
    m->setColor(Chart::LineColor, 0xffffff);

    // Set meter center and scale radius, and set the scale angle from -180 to +90 degrees
    m->setMeter(size / 2, size / 2, scaleRadius, -140, 140);


    // Background gradient with the mainColor at the center and become darker near the border
    double bgGradient[] = {0, mainColor, 0.5, m->adjustBrightness(mainColor, 0.75), 1,
        m->adjustBrightness(mainColor, 0.15)};

    // Fill the meter background with the background gradient
    m->addRing(0, outerRadius, m->relativeRadialGradient(DoubleArray(bgGradient, (int)(sizeof(
        bgGradient) / sizeof(bgGradient[0]))), outerRadius * 0.66));

    // Gradient for the neon backlight, with the main color at the scale radius fading to
    // transparent
    double neonGradient[] = {0.89, Chart::Transparent, 1, mainColor, 1.07, Chart::Transparent};
    m->addRing(scaleRadius * 85 / 100, outerRadius, m->relativeRadialGradient(DoubleArray(
        neonGradient, (int)(sizeof(neonGradient) / sizeof(neonGradient[0])))));

    // The neon ring at the scale radius with width equal to 1/80 of the scale radius, creating
    // using a brighter version of the main color
    m->addRing(scaleRadius, scaleRadius + scaleRadius / 80, m->adjustBrightness(mainColor, 2));

    // ���ݷ�Χ
    double minData = -500;
    double maxData = 500;
    double major = (maxData - minData) / 10;
    double minor = major / 2;
    double micro = minor / 2;
    // Meter scale is 0 - 900, with major/minor/micro ticks every 90/18/9 units
    m->setScale(minData, maxData, major, minor, micro);

    // Set the scale label style, tick length and tick width. The minor and micro tick lengths are
    // 80% and 60% of the major tick length, and their widths are around half of the major tick
    // width.
    m->setLabelStyle("ariali.ttf", fontSize);
    m->setTickLength(-tickLength, -tickLength * 80 / 100, -tickLength * 60 / 100);
    m->setLineWidth(0, tickWidth, tickWidth + 1 / 2, tickWidth + 1 / 2);

    // Demostrate different types of color scales and putting them at different positions.
    double smoothColorScale[] = {minData, 0xff0000, minData * 0.75, 0xdddd00, minData * 0.5, 0x00ff00, minData * 0.25, 0x0088ff, 0,
         0x0000ff, maxData * 0.25, 0x0088ff, maxData * 0.5, 0x00ff00, maxData * 0.75, 0xdddd00, maxData, 0xff0000};
    double highColorScale[] = {70, Chart::Transparent, 100, 0xff0000};

    if (chartIndex == 0) {
        // Add the smooth color scale
        m->addColorScale(DoubleArray(smoothColorScale, (int)(sizeof(smoothColorScale) / sizeof(
            smoothColorScale[0]))), colorScaleRadius, colorScaleWidth);
        // Add a red (0xff0000) pointer
        r.p = m->addPointer2(value, 0xff0000);
    } else {
        // Add the high color scale at the default position
        m->addColorScale(DoubleArray(highColorScale, (int)(sizeof(highColorScale) / sizeof(
            highColorScale[0]))));
        // Add a red (0xff0000) triangular pointer starting from 40% and ending at 60% of scale
        // radius, with a width 6 times the default
        r.p = m->addPointer2(value, 0xff0000, -1, Chart::TriangularPointer2, 0.4, 0.6, 6);
    }

    // Configure a large "pointer cap" to be used as the readout circle at the center. The cap
    // border width is set to 1.5% of the scale radius. The cap color is darker version of the main
    // color. The border color is a brighter version of the main color with 75% brightness gradient
    // effect.
    m->setCap2(Chart::Transparent, m->adjustBrightness(mainColor, 0.3), m->adjustBrightness(
        mainColor, 1.5), 0.75, 0, readOutRadiusRatio, 0.015);

    // Add value label at the center using a brighter version of the main color and Arial Italic
    // font
    r.tb = m->addText(size / 2, size / 2, m->formatValue(value, "{value|0}"), "ariali.ttf",
        readOutFontSize, m->adjustBrightness(mainColor, 2.5), Chart::Center);
    r.tb->setMargin(0);

    // Add a text label centered at (125, 175) with 15pt Arial Italic font
    m->addText(size / 2, size * 4 / 5, "A", "ariali.ttf", 30, Chart::TextColor, Chart::Center);

    // Add glare up to the scale radius
    m->addGlare(scaleRadius);

    // Output the chart
    m->makeChart();

    r.b = m;
    return r;
}

ANGULAR_METER_STRUCT roundmeterreadout_SOC(int chartIndex)
{
    // The value to display on the meter
    double value = 0;
    ANGULAR_METER_STRUCT r;

    // The main color of the four meters in this example. The other colors and gradients are derived
    // from the main color.
    int mainColor = 0x873324;

    //
    // In this example, we demonstrate how to parameterized by size, so that the chart size can be
    // changed by changing just one variable.
    //
    int size = 200;

    // The radius of the entire meter, which is size / 2, minus 2 pixels for margin
    int outerRadius = size / 2 - 2;

    // The radius of the meter scale
    int scaleRadius = outerRadius * 92 / 100;

    // The radius of the color scale
    int colorScaleRadius = scaleRadius * 43 / 100;

    // The width of the color scale
    int colorScaleWidth = scaleRadius * 10 / 100;

    // Major tick length
    int tickLength = scaleRadius * 10 / 100;

    // Major tick width
    int tickWidth = scaleRadius * 1 / 100 + 1;

    // Label font size
    int fontSize = scaleRadius * 13 / 100;

    // Radius of readout circle as a ratio to the scale radius
    double readOutRadiusRatio = 0.333333333333;

    // Readout font size
    int readOutFontSize = scaleRadius * 24 / 100;

    //
    // Create an angular meter based on the above parameters
    //

    // Create an AngularMeter object of the specified size. In this demo, we use black (0x000000) as
    // the background color. You can also use transparent or other colors.
    AngularMeter *m = new AngularMeter(size, size, 0xffffff);

    // Set the default text and line colors to white (0xffffff)
    m->setColor(Chart::TextColor, 0xffffff);
    m->setColor(Chart::LineColor, 0xffffff);

    // Set meter center and scale radius, and set the scale angle from -180 to +90 degrees
    m->setMeter(size / 2, size / 2, scaleRadius, -180, 90);


    // Background gradient with the mainColor at the center and become darker near the border
    double bgGradient[] = {0, mainColor, 0.5, m->adjustBrightness(mainColor, 0.75), 1,
        m->adjustBrightness(mainColor, 0.15)};

    // Fill the meter background with the background gradient
    m->addRing(0, outerRadius, m->relativeRadialGradient(DoubleArray(bgGradient, (int)(sizeof(
        bgGradient) / sizeof(bgGradient[0]))), outerRadius * 0.66));

    // Gradient for the neon backlight, with the main color at the scale radius fading to
    // transparent
    double neonGradient[] = {0.89, Chart::Transparent, 1, mainColor, 1.07, Chart::Transparent};
    m->addRing(scaleRadius * 85 / 100, outerRadius, m->relativeRadialGradient(DoubleArray(
        neonGradient, (int)(sizeof(neonGradient) / sizeof(neonGradient[0])))));

    // The neon ring at the scale radius with width equal to 1/80 of the scale radius, creating
    // using a brighter version of the main color
    m->addRing(scaleRadius, scaleRadius + scaleRadius / 80, m->adjustBrightness(mainColor, 2));

    // ���ݷ�Χ
    double minData = 0;
    double maxData = 100;
    double major = (maxData - minData) / 10;
    double minor = major / 2;
    double micro = minor / 2;
    // Meter scale is 0 - 900, with major/minor/micro ticks every 90/18/9 units
    m->setScale(minData, maxData, major, minor, micro);

    // Set the scale label style, tick length and tick width. The minor and micro tick lengths are
    // 80% and 60% of the major tick length, and their widths are around half of the major tick
    // width.
    m->setLabelStyle("ariali.ttf", fontSize);
    m->setTickLength(-tickLength, -tickLength * 80 / 100, -tickLength * 60 / 100);
    m->setLineWidth(0, tickWidth, tickWidth + 1 / 2, tickWidth + 1 / 2);

    // Demostrate different types of color scales and putting them at different positions.
    double smoothColorScale[] = {minData, 0x0000ff, (maxData - minData) * 0.25, 0x0088ff, (maxData - minData) * 0.5, 0x00ff00, (maxData - minData) * 0.75, 0xdddd00, maxData,
        0xff0000};
    double highColorScale[] = {70, Chart::Transparent, 100, 0x00ff00};

    if (chartIndex == 0) {
        // Add the smooth color scale
        m->addColorScale(DoubleArray(smoothColorScale, (int)(sizeof(smoothColorScale) / sizeof(
            smoothColorScale[0]))), colorScaleRadius, colorScaleWidth);
        // Add a red (0xff0000) pointer
        r.p = m->addPointer2(value, 0xff0000);
    } else {
        // Add the high color scale at the default position
        m->addColorScale(DoubleArray(highColorScale, (int)(sizeof(highColorScale) / sizeof(
            highColorScale[0]))));
        // Add a red (0xff0000) triangular pointer starting from 40% and ending at 60% of scale
        // radius, with a width 6 times the default
        r.p = m->addPointer2(value, 0xff0000, -1, Chart::TriangularPointer2, 0.4, 0.6, 6);
    }

    // Configure a large "pointer cap" to be used as the readout circle at the center. The cap
    // border width is set to 1.5% of the scale radius. The cap color is darker version of the main
    // color. The border color is a brighter version of the main color with 75% brightness gradient
    // effect.
    m->setCap2(Chart::Transparent, m->adjustBrightness(mainColor, 0.3), m->adjustBrightness(
        mainColor, 1.5), 0.75, 0, readOutRadiusRatio, 0.015);

    // Add value label at the center using a brighter version of the main color and Arial Italic
    // font
    r.tb = m->addText(size / 2, size / 2, m->formatValue(value, "{value|0}"), "ariali.ttf",
        readOutFontSize, m->adjustBrightness(mainColor, 2.5), Chart::Center);
    r.tb->setMargin(0);

    // Add a text label centered at (125, 175) with 15pt Arial Italic font
    m->addText(size * 5 / 7, size * 5 / 7, "%", "ariali.ttf", 30, Chart::TextColor, Chart::Center);

    // Add glare up to the scale radius
    m->addGlare(scaleRadius);

    // Output the chart
    m->makeChart();

    r.b = m;
    return r;
}

