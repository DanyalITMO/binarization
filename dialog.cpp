#include <QApplication>
#include<QHBoxLayout>
#include<QLabel>
#include<iostream>

//QImage brightness(const QImage& imgOrig)
//{
//    QImage imgTemp = imgOrig;
//    int  nHeight = imgTemp.height();
//    int nWidth  = imgTemp.width();

//    QRgb** matrix ;
//    matrix = new QRgb* [nHeight];

//    QRgb* tempLine = NULL;

//    for (qint32 y = 0; y < nHeight; ++y)
//    {
//        tempLine = reinterpret_cast<QRgb*>(imgTemp.scanLine(y));
//        for (qint32 x = 0; x < nWidth; ++x)
//        {
//            int r = qRed(*tempLine);
//            int g = qGreen(*tempLine);
//            int b = qBlue(*tempLine);

//          //  *tempLine  = ((r + g + b) / 3 < 128) ? qRgba(255,255,255,255): qRgba(0,0,0,255);
//            matrix[y]  = tempLine;
//            *tempLine++;
//        }
//    }
//      QImage img((uchar*)matrix, nWidth, nHeight, QImage::Format_RGB32);
//    return img;
//}

QImage brightness(const QImage& imgOrig)
{
    QImage imgTemp = imgOrig;
    int  nHeight = imgTemp.height();
    int nWidth  = imgTemp.width();
    int deph = imgTemp.depth();



    QRgb** matrix ;
    matrix = new QRgb* [nHeight];

    QRgb** tempLine = NULL;
    tempLine = new  QRgb* [nHeight];

    for (qint32 y = 0; y < nHeight; ++y)
    {
        tempLine[y] =reinterpret_cast<QRgb*>(imgTemp.scanLine(y));
//        for (qint32 x = 0; x < nWidth; ++x)
//        {/*
//            int r = qRed(*(tempLine+x));
//            int g = qGreen(*(tempLine+x));
//            int b = qBlue(*(tempLine+x));


//          //  *tempLine  = ((r + g + b) / 3 < 128) ? qRgba(255,255,255,255): qRgba(0,0,0,255);
//            *tempLine++;*/
//            int r = qRed(*(tempLine));
//            int g = qGreen(*(tempLine));
//            int b = qBlue(*(tempLine));
//            tempLine+=20;

//        }
        //matrix[y]  = tempLine[y];

    }
      QImage img((uchar*)tempLine, nWidth, nHeight, QImage::Format_ARGB32);
    return img;
}

/*QImage brightness(const QImage& imgOrig, int n)
{
    QImage imgTemp = imgOrig;
    qint32 nHeight = imgTemp.height();
    qint32 nWidth  = imgTemp.width();
    for (qint32 y = 0; y < nHeight; ++y)
    {
        QRgb* tempLine = reinterpret_cast<QRgb*>(imgTemp.scanLine(y));
        for (qint32 x = 0; x < nWidth; ++x)
        {
            int r = qRed(*tempLine) + n;
            int g = qGreen(*tempLine) + n;
            int b = qBlue(*tempLine) + n;
            int a = qAlpha(*tempLine);
            *tempLine++ = qRgba(r > 255 ? 255 : r < 0 ? 0 : r,
                                g > 255 ? 255 : g < 0 ? 0 : g,
                                b > 255 ? 255 : b < 0 ? 0 : b,
                               a                                 );
        }
    }
    return imgTemp;
}*/

int main(int argc, char *argv[])
{

        QApplication app(argc, argv);
        QImage       img("C:\\paint\\temp.png");
        QWidget      wgt;
        QHBoxLayout* phbx = new QHBoxLayout;
        phbx->setMargin(0);
        phbx->setSpacing(0);
//        for (int i = -150; i < 150; i += 50)
//        {
//QImage tempImg = brightness(img);
//std::cout<<"save = "<<img.save("C:\\myImg.png", "png")<<std::endl;

QImage temp2("C:\\myImg.png");
QLabel* plbl = new QLabel;
            plbl->setFixedSize(img.size());
            plbl->setPixmap(QPixmap::fromImage(temp2));
            phbx->addWidget(plbl);
//        }
        wgt.setLayout(phbx);
        wgt.show();
        return app.exec();


}
