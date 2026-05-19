#include "generate.hpp"

void generate(std::string data, std::string filename) {

	try {
		// режим шбтрихкода 128
		ZXing::MultiFormatWriter writer(ZXing::BarcodeFormat::Code128);

		// принимает на любом языке (русский и английский), пространство вокруг штрихкода 
		writer.setEncoding(ZXing::CharacterSet::UTF8);
		writer.setMargin(20);

		// матрица из 0 и 1 - неотформатированный штрихкод
		auto matrix = writer.encode(data, 300, 100);

		// будем увеличивать изображение в SCALE раз
		const int SCALE = 20;

		int imgWidth = matrix.width() * SCALE;
        int imgHeight = matrix.height() * SCALE;
		// белый фон
        cv::Mat barcodeImage(imgHeight, imgWidth, CV_8UC3, cv::Scalar(255, 255, 255)); 
        
		// рисуем прямоугольнички и закрашиваем, так получается штрихкод в 
		// понятном нам виде
        for (int y = 0; y < matrix.height(); ++y) {
            for (int x = 0; x < matrix.width(); ++x) {
                if (matrix.get(x, y)) {
					cv::rectangle(barcodeImage,
					cv::Point(x * SCALE, y * SCALE),
					cv::Point((x + 1) * SCALE, (y + 1) * SCALE),
					cv::Scalar(0, 0, 0),
					cv::FILLED);
                }
            }
        }
		
		// сохраняем получившееся изображение в файлик
		cv::imwrite(filename + ".png", barcodeImage);
		std::cout << "The barcode has been successfully created in file " << outputFilename << std::endl;

		// Опционально: показать изображение в окне
		// cv::imshow("Сгенерированный штрихкод", barcodeImage);
		// cv::waitKey(0);


	} catch (const std::exception& e) {
		// ловим ошибку и обрабатываем
		std::cerr << "Ошибка: " << e.what() << std::endl;
	}
}
